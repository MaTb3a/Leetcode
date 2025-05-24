class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # 3,3,2,2
        st,ed = -1 , len(nums)-1
        while st < ed:
            while st+1 < ed and nums[st+1] != val:
                st+=1
            while st < ed and nums[ed] == val:
                ed-=1
            if st < ed:
                nums[st+1],nums[ed] = nums[ed],nums[st+1]
                st+=1
                ed-=1
       
        print(st,ed)
        nums[:] = nums[:st+1]

           
        
