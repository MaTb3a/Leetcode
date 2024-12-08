from heapq import heappush, heappop

class Solution:
    def maxTwoEvents(self, events: list[list[int]]) -> int:
        events.sort()  
        max_value = 0
        max_prev_value = 0
        pq = []  

        for start, end, value in events:
            while pq and pq[0][0] < start:
                max_prev_value = max(max_prev_value, heappop(pq)[1])
            
            max_value = max(max_value, value + max_prev_value)
            
            heappush(pq, (end, value))
        
        return max_value
