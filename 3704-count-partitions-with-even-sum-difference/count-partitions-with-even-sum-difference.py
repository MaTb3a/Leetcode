class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        ls,cnt,rs = 0,0,sum(nums)
        for x in nums:
            ls += x
            rs-=x
            if ls and rs and not (rs-ls)&1:
                cnt+=1
        return cnt

        