class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = Counter(magazine)
        for c in ransomNote:
            if mp[c] == 0:
                return False
            mp[c]-=1
        return True