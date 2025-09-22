class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp = Counter(nums)
        mx = max(mp.values())
        return sum(val for key,val in mp.items() if val == mx)