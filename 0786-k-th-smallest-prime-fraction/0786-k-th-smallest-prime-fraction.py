class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        nums = []
        for i in range(0,len(arr)):
            for j in range(i+1,len(arr)):
                nums.append( (arr[i]/arr[j], arr[i],arr[j]))
        nums.sort();
        return [nums[k-1][1],nums[k-1][2]]