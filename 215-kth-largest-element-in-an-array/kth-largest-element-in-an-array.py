class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        frq = [0]* (20001)
        for x in nums:
            frq[x+10000]+=1
        for i in range(20000,0,-1):
            if frq[i] >=k:
                return i-10000
            k-=frq[i]
        return -1