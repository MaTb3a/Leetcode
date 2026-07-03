class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mp = {}
        for i in range(0,len(numbers)):
            if target-numbers[i] in mp:
                return [mp[target-numbers[i]]+1,i+1]
            mp[numbers[i]]=i
        
        