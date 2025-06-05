class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        def solve(x):
            if x > n:
                return
            ans.append(x)
            solve(x*10)
            if x%10 < 9 :
                solve(x+1)
            
        solve(1)
        return ans

