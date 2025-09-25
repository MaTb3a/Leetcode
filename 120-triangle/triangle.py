class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = list(triangle[-1])
        for i in range(len(triangle)-2 , -1 ,-1):
            for j in range(0,len(triangle[i])):
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j]
        return dp[0]
        

       