class Solution:
    def lexicalOrder(self, n: int) -> List[int]: # 13
        num = 1
        ans = []
        while len(ans) < n:
            ans.append(num) # 1
            if num * 10 <= n:
                num*=10
            else:
                while num == n or num%10 == 9: # 1
                    num//=10
                num+=1
        return ans # 1 10 11 12 13 2 3 4 5 6 7 8 9