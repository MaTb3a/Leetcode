class Solution:
   
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def solve(i,can):
            if i == len(prices):
                return 0
            if can:
                ret = max(-prices[i]+solve(i+1,False) , solve(i+1,True))
            else:
                ret = max(prices[i]+solve(i+1,True) , solve(i+1,False))
            return ret

        # 1,2,3,4,5
        # 7,1,5,3,6,4
        #   4   3 0 0

      
        
        # 1 10 100

        # 99
        # 9 + 90 

        # 7,1,5,3,6,4
        #     4   3
        # 1,2,3,4,5. I cannot use approach of first one can you have to sell
                  

        return solve(0,True)
