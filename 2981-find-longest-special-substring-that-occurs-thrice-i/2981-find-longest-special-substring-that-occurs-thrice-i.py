class Solution:
    def ok(self, s: str, md: int) -> bool:
        vis = [0] * 26  
        l = 0

        for r in range(len(s)):
            if s[r] != s[l]:
                l = r 
            if r - l + 1 >= md:
                vis[ord(s[r]) - ord('a')] += 1
            if vis[ord(s[r]) - ord('a')] > 2:
                return True
        
        return False

    def maximumLength(self, s: str) -> int:
        st, ed = 1, len(s)
        cur = -1

        while st <= ed:
            md = (st + ed) // 2
            if self.ok(s, md):
                cur = md
                st = md + 1
            else:
                ed = md - 1

        return cur
