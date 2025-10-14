class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        if k == 1:
            return True
        i,j=1,k+1
        while(j < len(nums)):
            cnt = 0
            for x in range(k):
                if j+x >= len(nums):
                    break
                if nums[i+x] > nums[i+x-1] and nums[j+x] > nums[j+x-1]:
                    cnt+=1
                else:
                    break
            print(i,j,cnt)
            if cnt == k-1:
                return True
            i+=1
            j+=1
        return False
                    


