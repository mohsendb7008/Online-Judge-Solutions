from datetime import datetime
import os
import sys

def is_photo(file):
    extensions = ['png', 'jpeg', 'jpg']
    for ext in extensions:
        if file.lower().endswith(f'.{ext}'):
            return True
    return False

def is_video(file):
    extensions = ['mp4', 'avi', '3gp', 'mpeg', 'mkv', 'wmv', 'mov']
    for ext in extensions:
        if file.lower().endswith(f'.{ext}'):
            return True
    return False

def file_last_modified_year(file):
    return datetime.fromtimestamp(os.path.getmtime(file)).year

def copy_file(src, dst):
    with open(src, 'rb') as src_file:
        data = src_file.read()
        with open(dst, 'wb') as dst_file:
            dst_file.write(data)

def organize(src, dst):
    information = {}
    for folder, _, files in os.walk(src):
        for photo in filter(lambda x: is_photo(x), files):
            year = file_last_modified_year(os.path.join(folder, photo))
            if year not in information:
                information[year] = {}
            if 'photos' not in information[year]:
                information[year]['photos'] = []
            information[year]['photos'].append(os.path.join(folder, photo))
        for video in filter(lambda x: is_video(x), files):
            year = file_last_modified_year(os.path.join(folder, video))
            if year not in information:
                information[year] = {}
            if 'videos' not in information[year]:
                information[year]['videos'] = []
            information[year]['videos'].append(os.path.join(folder, video))
    os.mkdir(dst)
    for year, info in information.items():
        os.mkdir(os.path.join(dst, str(year)))
        for folder, files in info.items():
            os.mkdir(os.path.join(dst, str(year), folder))
            for file in files:
                copy_file(file, os.path.join(dst, str(year), folder, os.path.basename(file)))


if __name__ == '__main__':
    organize(sys.argv[1], sys.argv[2])