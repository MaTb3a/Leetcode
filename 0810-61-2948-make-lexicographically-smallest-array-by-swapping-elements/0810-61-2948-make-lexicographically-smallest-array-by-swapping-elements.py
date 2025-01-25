class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)
        v = sorted((val, i) for i, val in enumerate(nums))

        i = 0
        while i < n:
            idx = [v[i][1]]
            j = i + 1
            while j < n and v[j][0] - v[j - 1][0] <= limit:
                idx.append(v[j][1])
                j += 1
            idx.sort()
            for k in range(len(idx)):
                nums[idx[k]] = v[i + k][0]
            i = j

        return nums
