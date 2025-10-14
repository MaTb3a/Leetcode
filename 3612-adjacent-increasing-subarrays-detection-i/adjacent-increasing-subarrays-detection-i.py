class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        def solve(i):
            for j in range(k-1):
                if nums[i+j+1] <= nums[i+j]:
                    return False
            return True
        i,j=0,k
        while(j+k-1 < len(nums)):
            if solve(i) and solve(j):
                return True
            i+=1
            j+=1
        return False
                    


