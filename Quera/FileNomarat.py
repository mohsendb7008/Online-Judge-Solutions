class Grade:

    def __init__(self, stu_id, crc_code, score):
        self.student_id = stu_id
        self.course_code = crc_code
        self.score = score
    
    @staticmethod
    def from_line(line):
        line = line.split()
        return Grade(int(line[0]), int(line[1]), float(line[2]))


class CourseUtil:

    def set_file(self, address):
        self.address = address

    def load(self, line_number):
        with open(self.address) as f:
            lines = f.readlines()
            if line_number > len(lines):
                return None
            return Grade.from_line(lines[line_number - 1])
    
    def save(self, grade):
        with open(self.address) as f:
            if len(list(filter(lambda x: x.student_id == grade.student_id and x.course_code == grade.course_code, map(lambda x: Grade.from_line(x), f.readlines())))):
                return
        with open(self.address, 'a') as f:
            f.write(f'\n{grade.student_id} {grade.course_code} {grade.score}')

    def calc_student_average(self, student_id):
        with open(self.address) as f:
            all = list(filter(lambda x: x.student_id == student_id, map(lambda x: Grade.from_line(x), f.readlines())))
            return sum(map(lambda x: x.score, all)) / len(all)

    def calc_course_average(self, course_code):
        with open(self.address) as f:
            all = list(filter(lambda x: x.course_code == course_code, map(lambda x: Grade.from_line(x), f.readlines())))
            return sum(map(lambda x: x.score, all)) / len(all)

    def count(self):
        with open(self.address) as f:
            return len(f.readlines())

   
