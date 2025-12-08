class Solution:
    def countTriples(self, n: int) -> int:
        cnt = 0
        for i in range(1,n+1):
            for j in range(1,n+1):
                if sqrt(i*i + j * j) == int(sqrt(i*i + j * j) ) and  int(sqrt(i*i + j * j) )  <= n:
                    cnt+=1
        return cnt