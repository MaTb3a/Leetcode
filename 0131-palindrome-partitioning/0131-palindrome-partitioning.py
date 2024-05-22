class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        def isPalendrom(s):
            return s == s[::-1]
        
        def solve(i,cur):
            if i == len(s):
                ans.append(cur.copy())
                return
            for j in range(i+1,len(s)+1):
                if isPalendrom(s[i:j]):
                    cur.append(s[i:j])
                    solve(j,cur)
                    cur.pop()
        solve(0,[])
        return ans