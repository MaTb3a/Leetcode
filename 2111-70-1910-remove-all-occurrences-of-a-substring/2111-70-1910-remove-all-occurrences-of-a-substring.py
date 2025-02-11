class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        def kmp(part):
            lps = [0] * len(part)
            j = 0
            for i in range(1, len(part)):
                while j and part[i] != part[j]:
                    j = lps[j - 1]
                if part[i] == part[j]:
                    j += 1
                    lps[i] = j
            return lps

        lps = kmp(part)
        sz = len(part)
        ans, stk = [], []
        j = 0

        for ch in s:
            ans.append(ch)
            stk.append(j)

            while j and ch != part[j]:
                j = lps[j - 1]

            if ch == part[j]:
                j += 1

            stk[-1] = j

            if j == sz:
                ans = ans[:-sz]
                stk = stk[:-sz]
                j = stk[-1] if stk else 0

        return "".join(ans)
