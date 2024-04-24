class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 2:
            if n == 2:
                return 1
            return n
        one = 0 
        two = 1
        three = 1
        for i in range(2,n):
            cur = one + two + three
            one = two
            two = three
            three = cur
        return cur
            