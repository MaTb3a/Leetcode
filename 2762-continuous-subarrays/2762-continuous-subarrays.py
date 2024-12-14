class Solution:
    def calc(self, l: int, r: int) -> int:
        n = r - l
        return n * (n + 1) // 2

    def continuousSubarrays(self, nums: list[int]) -> int:
        total_sum = 0
        l, r = 0, 0
        n = len(nums)
        mn, mx = nums[0], nums[0]

        while r < n:
            mn = min(mn, nums[r])
            mx = max(mx, nums[r])

            if mx - mn > 2:
                total_sum += self.calc(l, r)
                l = r
                mn = mx = nums[r]
                while l > 0 and abs(nums[r] - nums[l - 1]) <= 2:
                    l -= 1
                    mn = min(mn, nums[l])
                    mx = max(mx, nums[l])
                total_sum -= self.calc(l, r)

            r += 1

        return total_sum + self.calc(l, r)
