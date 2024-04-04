class Solution:
    def maxDepth(self, s: str) -> int:
        ans, p=0, 0
        for c in s:
            p+=(c=='(')-(c==')')
            ans=max(ans, p)
        return ans