class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n <=1 :
            return n
        cnt = 0
        while (1<<cnt) <= n:
            cnt+=1
        return ((1<<cnt)-1) - self.minimumOneBitOperations(n-(1<<(cnt-1)))