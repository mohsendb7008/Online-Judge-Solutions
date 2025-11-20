import sys

def solve():
    lines = sys.stdin.read().splitlines()
    i = 0
    while i < len(lines):
        if lines[i] == "0":
            return
        projects = {}
        student_projects = {}
        current_project = ""
        while i < len(lines) and lines[i] != "1":
            line = lines[i]
            if line.isupper():
                current_project = line
                projects[current_project] = set()
            else:
                student = line
                projects[current_project].add(student)
                if student not in student_projects:
                    student_projects[student] = set()
                student_projects[student].add(current_project)
            i += 1

        final_counts = {}
        for project, students in projects.items():
            count = sum(1 for s in students if len(student_projects[s]) == 1)
            final_counts[project] = count

        for project, count in sorted(final_counts.items(), key=lambda x: (-x[1], x[0])):
            print(project, count)

        i += 1

if __name__ == "__main__":
    solve()