import heapq

class Solution:
    def minOperations(self, nums, k):
        heapq.heapify(nums)
        cnt = 0

        while len(nums) > 1 and nums[0] < k:
            x = heapq.heappop(nums)
            y = heapq.heappop(nums)
            heapq.heappush(nums, min(x * 2 + y, k + 1))
            cnt += 1

        return cnt
