class Solution:
    def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
        banned_set = set(banned)  
        count = 0
        
        for i in range(1, n + 1):
            if i not in banned_set and i <= maxSum:
                count += 1
                maxSum -= i
        
        return count
