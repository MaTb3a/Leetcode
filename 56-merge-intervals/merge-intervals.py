class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        st,ed = intervals[0]
        for i in range(1,len(intervals)):
            if intervals[i][0] <= ed:
                ed = max(intervals[i][1],ed)
            else :
                ans.append([st,ed])
                st,ed = intervals[i]
        ans.append([st,ed])
        st,ed = intervals[-1]
        return ans