class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        empty = numBottles
        ans = numBottles
        while empty >= numExchange:
            tmp = empty //numExchange
            empty %= numExchange
            empty+= tmp
            ans+=tmp
        return ans


