class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = 0
        while students:
            if cnt == len(students) :
                break
            if(students[0] == sandwiches[0]):
                students.pop(0)
                sandwiches.pop(0)
                cnt = 0
            else :
                cnt+=1
                students.append(students.pop(0))
                
        return len(students)
        
        