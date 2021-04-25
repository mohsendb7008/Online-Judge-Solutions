import os
from shutil import copyfile


class FileManager:

    recovery_folder = '__recovery__'
    file_id = 1

    def __init__(self):
        if not os.path.exists(FileManager.recovery_folder):
            os.mkdir(FileManager.recovery_folder)
        self.recovery_info = {}
        
    
    def find(self, name, address):
        ans = []
        for d, _, f in os.walk(address):
            ans.extend(list(map(lambda x: os.path.join(d, x), filter(lambda x: x == name, f))))
        return ans

    def create_file(self, name, address):
        if os.path.isfile(os.path.join(address, name)):
            return
        with open(os.path.join(address, name), 'w') as f:
            pass

    def create_dir(self, name, address):
        if os.path.isdir(os.path.join(address, name)):
            return
        os.mkdir(os.path.join(address, name))

    def delete(self, name, address):
        if os.path.exists(os.path.join(address, name)):
            copyfile(os.path.join(address, name), os.path.join(FileManager.recovery_folder, str(FileManager.file_id)))
            if name not in self.recovery_info:
                self.recovery_info[name] = []
            self.recovery_info[name].append((address, FileManager.file_id))
            FileManager.file_id += 1
            os.remove(os.path.join(address, name))

    def restore(self, name):
        if name in self.recovery_info and self.recovery_info[name]:
            info = self.recovery_info[name].pop()
            copyfile(os.path.join(FileManager.recovery_folder, str(info[1])), os.path.join(info[0], name))