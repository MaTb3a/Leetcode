class Solution:
    def minimumLength(self, s: str) -> int:
        mask1, mask2 = 0, 0
        removes = 0

        for ch in s:
            bit = 1 << (ord(ch) - ord('a'))
            if not (mask1 & bit):
                mask1 |= bit
            elif not (mask2 & bit):
                mask2 |= bit
            else:
                removes += 2
                mask1 &= ~bit

        return len(s) - removes
