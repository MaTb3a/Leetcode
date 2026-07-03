class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            idx = bisect.bisect_left(numbers,target - numbers[i],lo = i+1)
            if idx != len(numbers) and numbers[idx] + numbers[i] == target:
                return [i+1,idx+1]