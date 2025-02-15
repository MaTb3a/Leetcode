class Solution:
    def punishmentNumber(self, n: int) -> int:
        ans = 0
        def solve(num, target):
            if num == target:
                return True
            if num < target or target < 0:
                return False
            return solve(num//10,target - num%10) or solve(num//100,target - num%100) or solve(num//1000,target - num%1000)
        for i in range(1,n+1):
            if solve(i*i,i):
                ans+=i*i
        return ans