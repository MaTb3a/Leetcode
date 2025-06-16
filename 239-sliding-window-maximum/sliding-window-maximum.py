class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        my_deque = deque()
        n = len(nums)
        mx = 0
        for i in range(k):
            while len(my_deque) and my_deque[-1][0] < nums[i]:
                my_deque.pop()
            my_deque.append([nums[i],i])
            mx = max(mx,nums[i])
        
        ans.append(mx)

        for i in range(k,n):
            if len(my_deque) and i - my_deque[0][1] >= k:
                my_deque.popleft()
            
            while len(my_deque) and my_deque[-1][0] < nums[i]:
                my_deque.pop()
            
            my_deque.append([nums[i],i])
            ans.append(my_deque[0][0])

        return ans
        