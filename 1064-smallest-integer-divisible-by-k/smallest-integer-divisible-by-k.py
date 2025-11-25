class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        ans = 0
        for i in range(k+1):
            ans = (ans*10)+1
            if ans%k==0:
                return i+1
            ans%=k
        return -1
        