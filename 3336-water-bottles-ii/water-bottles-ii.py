class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles # 10
        empty = numBottles # 10
        while empty >= numExchange: # 10 > 3
            ans+=1
            empty-=numExchange
            empty+=1
            numExchange+=1
        return ans
            
        
            
