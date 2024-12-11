class Solution:
    def maximumBeauty(self, nums: list[int], k: int) -> int:
        mx = max(nums)
        vis = [0] * (mx + 2)
        for x in nums:
            vis[max(0, x - k)] += 1
            vis[min(x + k + 1, mx + 1)] -= 1

        ans, cnt = 0, 0
        for x in vis:
            cnt += x
            ans = max(ans, cnt)

        return ans
