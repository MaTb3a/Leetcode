class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def ok(md):
            cnt,i = 0,0
            while i<len(nums):
                if nums[i] <= md:
                    cnt+=1
                    i+=2
                else :
                    i+=1
            return cnt>=k
        st,ed,cur,md = min(nums),max(nums),-1,0
        while st <=ed:
            md = (st+ed)//2
            if ok(md):
                cur = md
                ed = md -1
            else:
                st = md+1
        return cur