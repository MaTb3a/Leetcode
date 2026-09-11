class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        vis = [False]*len(digits)
        unique = set()
        def solve(depth,n):
            if depth == 3:
                if n > 99 and n%2 == 0:
                    unique.add(n)
                return

            for j in range(len(digits)):
                if vis[j] == False:
                    vis[j] = True
                    solve(depth+1,n*10+digits[j])
                    vis[j] = False
            
        solve(0,0)
        return len(unique)