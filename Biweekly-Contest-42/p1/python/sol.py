class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = 0
        while len(sandwiches) > 0 and cnt+2 < len(students):
            stack_top = sandwiches[0]
            x = students[0]
            if x != stack_top:
                students.append(x)
                students = students[1:]
                cnt = cnt + 1
            else:
                sandwiches = sandwiches[1:]
        return len(students)