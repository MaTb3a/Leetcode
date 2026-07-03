class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)-1,-1,-1):
            idx = bisect.bisect_left(numbers,target - numbers[i])
            if idx != len(numbers) and numbers[idx] + numbers[i] == target:
                return [idx+1,i+1]