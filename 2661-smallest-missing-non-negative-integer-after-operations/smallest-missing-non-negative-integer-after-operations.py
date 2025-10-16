class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mex = 0
        mp = {}
        for i in range(len(nums)):
            nums[i] = ((nums[i] %value)+value)%value
            while nums[i] in mp:
                l,r,cur = 0, 1000000, 0
                while l <= r:
                    md = (l+r)//2
                    if nums[i]+(md*value) not in mp:
                        r = md -1
                        cur = md
                    else:
                        l = md+1
                nums[i]+=(cur*value)
            mp[nums[i]] = True
        
       
        for i in range(len(nums)+1):
            if i not in mp:
                return i 
        return -1