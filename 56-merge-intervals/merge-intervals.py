class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        j = 0
        for i in range(1,len(intervals)):
            if intervals[i][0] <= intervals[j][1]:
                intervals[j][1] = max(intervals[i][1],intervals[j][1])
            else :
                j+=1
                intervals[j] = intervals[i]
        
        return intervals[:j+1]