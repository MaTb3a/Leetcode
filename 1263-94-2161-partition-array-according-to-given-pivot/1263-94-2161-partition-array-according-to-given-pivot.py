class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        ans  = [0]*len(nums)
        ii,jj = 0 , len(nums)-1
        for i,j in zip(range(len(nums)),range(len(nums)-1,-1,-1)):
            if nums[i] < pivot:
                ans[ii] = nums[i]
                ii+=1
            if nums[j] > pivot:
                ans[jj] = nums[j]
                jj-=1
        while ii <= jj:
            ans[ii] = pivot
            ii+=1
        return ans