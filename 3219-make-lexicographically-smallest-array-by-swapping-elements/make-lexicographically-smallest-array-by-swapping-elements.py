class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        v = []
        for i in range(n):
            v.append([nums[i],i])
        v.sort()

        connectedComp = []
        connectedComp.append([v[0]])
        for i in range(1,n):
            if v[i][0] - v[i-1][0] <= limit:
                connectedComp[-1].append(v[i])
            else:
                connectedComp.append([v[i]])
        
        for c in connectedComp:
            idx = [x[1] for x in c]
            idx.sort()
            for i in range(len(idx)):
                nums[idx[i]] = c[i][0]
        return nums
