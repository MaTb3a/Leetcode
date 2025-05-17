class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i,j,k = 0,0,0
        nums = [0] * (n+m)
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                nums[k] = nums1[i]
                i+=1
            else:
                nums[k] = nums2[j]
                j+=1
            k+=1
        
        while i < m:
            nums[k] = nums1[i]
            i+=1
            k+=1
        
        while j < n:
            nums[k] = nums2[j]
            j+=1
            k+=1
       
        for i in range(len(nums)):
            nums1[i] = nums[i]
        return nums1

        
        

        
                

        