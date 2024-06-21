class Solution:

    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        
        sm = 0   
        n = len(customers)
        for i in range(min(minutes,n)):
            if grumpy[i]:
                sm+=customers[i]
        mx = sm
        for i in range(minutes,n):
            if grumpy[i-minutes]:
                sm-=customers[i-minutes]
            if grumpy[i]:
                sm+=customers[i]
            mx=max(mx,sm)
        ans = 0
        for i in range(n):
            if not grumpy[i]:
                ans+=customers[i]
        return ans+mx