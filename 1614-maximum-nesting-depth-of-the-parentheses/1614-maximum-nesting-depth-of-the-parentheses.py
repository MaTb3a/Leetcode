class Solution:
    def maxDepth(self, s: str) -> int:
        mx = 0
        op = 0
        for i in s:
            if i == '(':
                op+=1
            if i == ')':
                op-=1
            mx=max(mx,op)
        return mx