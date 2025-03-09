class Solution:
    def numberOfAlternatingGroups(self, colors: list[int], k: int) -> int:
        n = len(colors)
        cnt = 1
        ans = 0
        for i in range(1, n + k - 1):
            idx = i if i < n else i - n
            prev_idx = (i - 1) if (i - 1) < n else (i - 1) - n
            cnt = cnt + 1 if colors[idx] != colors[prev_idx] else 1
            ans += 1 if cnt >= k else 0
        return ans