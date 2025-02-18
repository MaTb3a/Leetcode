class Solution:
    def smallestNumber(self, pattern: str) -> str:
        stk,ans = "",""
        for i in range(0,len(pattern)+1):
            stk+=str(i+1)
            if i == len(pattern) or pattern[i] == 'I':
                    ans+=stk[::-1]
                    stk=""
        return ans
            