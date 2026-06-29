class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        vis = []
        vis = [-1 for i in range(3001)]
        
        for i in range(0,len(numbers)):
            if vis[target-numbers[i]+1000] != -1:
                return [vis[target-numbers[i]+1000]+1,i+1]
            vis[numbers[i]+1000]=i
        
        