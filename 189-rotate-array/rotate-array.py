class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 1,2,3,4,5,6,7
        # 5,6,7,1,2,3,4
        q = deque(nums)
        k%=len(nums)
        while k:
            q.appendleft(q.pop())
            k-=1
        
        nums[:] = list(q)