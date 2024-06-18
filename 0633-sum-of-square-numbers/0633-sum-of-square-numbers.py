class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0:
            return True
        mx = int(math.sqrt(c))
        for b in range(1,mx+1):
            a = int(math.sqrt(c-b*b))
            if a*a + b*b == c :
                print(a,b*b,c)
                return True
        return False
            