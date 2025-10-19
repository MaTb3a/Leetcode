class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        incremented = {str(n):str((n+a)%10) for n in range(10)}

        def addOp(s):
            res = ""
            for i in range(n):
                res += s[i] if i % 2 == 0 else incremented[s[i]]
            return res

        def rotOp(s):
            return s[n-b:] + s[:n-b]

        seen = set()
        def dfs(s):
            if s in seen:
                return
            seen.add(s)
            dfs(addOp(s))
            dfs(rotOp(s))
            return

        dfs(s)
        return min(seen)