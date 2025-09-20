class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        frq = Counter(magazine)
        for c in ransomNote:
            if frq[c] == 0:
                return False
            frq[c]-=1
        return True