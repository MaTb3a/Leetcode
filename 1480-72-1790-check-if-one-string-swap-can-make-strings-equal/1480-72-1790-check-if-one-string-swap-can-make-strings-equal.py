class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        diff = [(i, j) for i, j in zip(s1, s2) if i != j]
        return len(diff) == 0 or (len(diff) == 2 and diff[0][::-1] == diff[1])
