class Solution:
    @cache
    def solve(self,i,j,s1,s2):
        if i == len(s1) and j == len(s2):
            return 0
        if i == len(s1):
            return sum(ord(s2[x])  for x in range(j,len(s2)))
        if j == len(s2):
            return sum(ord(s1[x])  for x in range(i,len(s1)))
            
        ret = 1000000000
        if s1[i] == s2[j]:
            ret=min(ret,self.solve(i+1,j+1,s1,s2))
        ret=min(ret,self.solve(i+1,j,s1,s2)+(ord(s1[i]) ))
        ret=min(ret,self.solve(i,j+1,s1,s2)+(ord(s2[j]) ))
        return ret

    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        return self.solve(0,0,s1,s2)
    