class Student:

    instances = []

    def __init__(self, name, identical_num, entering_year, field):
        self.name = name
        self.identical_num = identical_num
        self.entering_year = entering_year
        self.field = field
        self.classes = []
        Student.instances.append(self)


class Teach:

    instances = []

    def __init__(self, name, identical_num, field):
        self.name = name
        self.identical_num = identical_num
        self.field = field
        self.classes = []
        Teach.instances.append(self)

class Class:

    instances = []

    def __init__(self, name, class_id, field):
        self.name = name
        self.class_id = class_id
        self.field = field
        self.teach = None
        self.students = []
        Class.instances.append(self)

national_ids = {}
class_ids = {}
grades = {}
top_mark = {}

def calc_avg(student):
    summ, cnt = 0, 0
    for key, value in grades.items():
        if key[0] == student:
            summ += value
            cnt += 1
    if cnt == 0:
        return 'None'
    return summ/cnt

def process_cmd(cmd):
    tokens = cmd.split(' ')
    if tokens[0] == 'register_student':
        if tokens[2] in national_ids:
            return 'this identical number previously registered'
        national_ids[tokens[2]] = Student(*tokens[1:])
        return 'welcome to golestan'
    elif tokens[0] == 'register_professor':
        if tokens[2] in national_ids:
            return 'this identical number previously registered'
        national_ids[tokens[2]] = Teach(*tokens[1:])
        return 'welcome to golestan'
    elif tokens[0] == 'make_class':
        if tokens[2] in class_ids:
            return 'this class id previously used'
        class_ids[tokens[2]] = Class(*tokens[1:])
        return 'class added successfully'
    elif tokens[0] == 'add_student':
        if tokens[1] not in national_ids:
            return 'invalid student'
        student = national_ids[tokens[1]]
        if not isinstance(student, Student):
            return 'invalid student'
        if tokens[2] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[2]]
        if student.field != theClass.field:
            return 'student field is not match'
        if student in theClass.students:
            return 'student is already registered'
        theClass.students.append(student)
        student.classes.append(theClass)
        return 'student added successfully to the class'
    elif tokens[0] == 'add_professor':
        if tokens[1] not in national_ids:
            return 'invalid professor'
        teach = national_ids[tokens[1]]
        if not isinstance(teach, Teach):
            return 'invalid professor'
        if tokens[2] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[2]]
        if teach.field != theClass.field:
            return 'professor field is not match'
        if theClass.teach:
            return 'this class has a professor'
        theClass.teach = teach
        teach.classes.append(theClass)
        return 'professor added successfully to the class'
    elif tokens[0] == 'student_status':
        if tokens[1] not in national_ids:
            return 'invalid student'
        student = national_ids[tokens[1]]
        if not isinstance(student, Student):
            return 'invalid student'
        return f'{student.name} {student.entering_year} {student.field} {" ".join(list(map(lambda x: x.name, student.classes)))}'
    elif tokens[0] == 'professor_status':
        if tokens[1] not in national_ids:
            return 'invalid professor'
        teach = national_ids[tokens[1]]
        if not isinstance(teach, Teach):
            return 'invalid professor'
        return f'{teach.name} {teach.field} {" ".join(list(map(lambda x: x.name, teach.classes)))}'
    elif tokens[0] == 'class_status':
        if tokens[1] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[1]]
        return f'{theClass.teach.name if theClass.teach else "None"} {" ".join(list(map(lambda x: x.name, theClass.students)))}'
    elif tokens[0] == 'set_final_mark':
        if tokens[1] not in national_ids:
            return 'invalid professor'
        teach = national_ids[tokens[1]]
        if not isinstance(teach, Teach):
            return 'invalid professor'
        if tokens[2] not in national_ids:
            return 'invalid student'
        student = national_ids[tokens[2]]
        if not isinstance(student, Student):
            return 'invalid student'
        if tokens[3] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[3]]
        if theClass.teach != teach:
            return 'professor class is not match'
        if student not in theClass.students:
            return 'student did not registered'
        mark = int(tokens[4])
        grades[(student, theClass)] = mark
        top_mark[theClass] = max(mark, top_mark.get(theClass, mark))
        return 'student final mark added or changed'
    elif tokens[0] == 'mark_student':
        if tokens[1] not in national_ids:
            return 'invalid student'
        student = national_ids[tokens[1]]
        if not isinstance(student, Student):
            return 'invalid student'
        if tokens[2] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[2]]
        if student not in theClass.students:
            return 'student did not registered'
        return str(grades.get((student, theClass), 'None'))
    elif tokens[0] == 'mark_list':
        if tokens[1] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[1]]
        if not theClass.teach:
            return 'no professor'
        if not theClass.students:
            return 'no student'
        return " ".join(list(map(lambda x: str(grades.get((x, theClass), 'None')), theClass.students)))
    elif tokens[0] == 'average_mark_professor':
        if tokens[1] not in national_ids:
            return 'invalid professor'
        teach = national_ids[tokens[1]]
        if not isinstance(teach, Teach):
            return 'invalid professor'
        summ, cnt = 0, 0
        for key, value in grades.items():
            if key[1].teach == teach:
                summ += value
                cnt += 1
        if cnt == 0:
            return 'None'
        return f'{summ/cnt:.2f}'
    elif tokens[0] == 'average_mark_student':
        if tokens[1] not in national_ids:
            return 'invalid student'
        student = national_ids[tokens[1]]
        if not isinstance(student, Student):
            return 'invalid student'
        ans = calc_avg(student)
        if ans != 'None':
            ans = f'{ans:.2f}'
        return ans
    elif tokens[0] == 'top_student':
        field = tokens[1]
        entering_year = tokens[2]
        students = filter(lambda x: x.field == field and x.entering_year == entering_year, Student.instances)
        top_student, top_grade = None, -1
        for student in students:
            avg = calc_avg(student)
            if avg != 'None' and avg > top_grade:
                top_student = student
                top_grade = avg
        return top_student.name if top_student else 'None'
    elif tokens[0] == 'top_mark':
        if tokens[1] not in class_ids:
            return 'invalid class'
        theClass = class_ids[tokens[1]]
        return str(top_mark.get(theClass, 'None'))        

if __name__ == '__main__':
    while True:
        line = input()
        if line == 'end':
            break
        print(process_cmd(line))