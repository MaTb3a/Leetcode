class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if k > len(s):
            return False
        
        freq = 0
        for ch in s:
            freq ^= (1 << (ord(ch) - ord('a')))
        
        return bin(freq).count('1') <= k
