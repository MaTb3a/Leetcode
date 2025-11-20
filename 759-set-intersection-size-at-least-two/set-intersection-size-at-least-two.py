class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: (x[0], -x[1]))
        n = len(intervals)

        last1 = intervals[-1][0]
        last2 = last1 + 1
        ans = [last1, last2]

        for i in range(n - 2, -1, -1):
            L, R = intervals[i]

            if last1 >= L and last2 <= R:
                continue

            if (L <= last1 <= R) or (L <= last2 <= R):
                ans.append(L)
                last2 = last1
                last1 = L
            else:
                ans.append(L)
                ans.append(L + 1)
                last1 = L
                last2 = L + 1

        return len(ans)