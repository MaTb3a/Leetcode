class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        cnt = k
        for x in nums:
            if x == 0:
                cnt+=1
            else:
                if cnt < k:
                    return False
                cnt = 0
        return True