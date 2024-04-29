class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        x = 0
        for i in nums:
            x = x^i
        cnt = 0
        while x or k:
            if (x&1) != (k&1):
                cnt+=1
            x= x//2
            k= k//2
        return cnt