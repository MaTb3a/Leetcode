class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        x = 1
        while len(ans) < n:
            ans.append(x)
            if x * 10 <= n:
                x*=10
            else:
                while x == n or x % 10 == 9:
                    x//=10
                x+=1
            
        return ans