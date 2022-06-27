class Solution:
    def minPartitions(self, n: str) -> int:
        mx=0
        for i in range(0,len(n)):
            mx=max(mx,int(n[i]))
        return mx