class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        order = sorted(range(n), key=lambda i: intervals[i][1])  
        rights = [intervals[i][1] for i in order]

        prev = [(0, [])] * (n + 1)  
        for _ in range(4):
            cur = [(0, [])] * (n + 1)
            for p in range(1, n + 1):
                i = order[p - 1] 
                l, r, w = intervals[i]
                j = bisect_left(rights, l)  
                score, ids = prev[j]
                cur[p] = min((score - w, sorted(ids + [i])), cur[p - 1])
            prev = cur
        return prev[n][1]