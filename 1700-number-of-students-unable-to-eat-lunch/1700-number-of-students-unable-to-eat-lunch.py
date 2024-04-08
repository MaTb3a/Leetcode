class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        zeros = students.count(0)
        ones = students.count(1)

        for sandwich in sandwiches :
            if sandwich == 0:
                zeros-=1
            else :
                ones-=1
            if zeros < 0:
                return ones
            if ones < 0:
                return zeros
        return 0
        
        