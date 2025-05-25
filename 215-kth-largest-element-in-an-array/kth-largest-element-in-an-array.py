class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for x in nums:
            heapq.heappush(heap,x)
            if len(heap) > k:
                heapq.heappop(heap)
                
        return heap[0]