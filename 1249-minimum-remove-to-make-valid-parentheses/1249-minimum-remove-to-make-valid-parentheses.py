class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        ans = ""
        for i in range(0,len(s)):
            if s[i] =='(':
                stk.append(len(ans))
                ans= ans + s[i]
            elif s[i] == ')' :
                if(len(stk) > 0) :
                    ans = ans + ')'
                    stk.pop()
            else :
                ans = ans + s[i]
        ans = list(ans)
        while len(stk):
            ans.pop(stk.pop())
        return "".join(ans)