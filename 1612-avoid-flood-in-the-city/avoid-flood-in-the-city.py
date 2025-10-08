class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        zeros = SortedList()
        mp = {}
        n = len(rains)
        ans = [1]*n
        for i in range(n):
            if rains[i] == 0:
                zeros.add(i)
                continue
            if rains[i] in mp:
                it = zeros.bisect(mp[rains[i]])
                if it == len(zeros):
                    return []
                ans[zeros[it]] = rains[i]
                zeros.discard(zeros[it])
            mp[rains[i]] = i
            ans[i] = -1
        return ans

