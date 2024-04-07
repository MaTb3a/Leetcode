class Solution:
    def __init__(self):
        self.dp = [[-1 for _ in range(0,101)] for _ in range(0,101)]
    def solve(self,idx,op,s):
        if idx == len(s):
            return op == 0
        if op < 0 :
            return 0
        if self.dp[idx][op] != -1:
            return self.dp[idx][op]
        ret = 0
        if s[idx] == '(':
            ret = max(ret,self.solve(idx+1,op+1,s))
        elif s[idx] == ')':
            ret = max(ret,self.solve(idx+1,op-1,s))
        else:
            ret = max(ret,self.solve(idx+1,op-1,s))
            ret = max(ret,self.solve(idx+1,op+1,s))
            ret = max(ret,self.solve(idx+1,op,s))
        self.dp[idx][op] =ret
        return ret 

    def checkValidString(self, s: str) -> bool:
        return self.solve(0,0,s)