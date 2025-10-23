class Solution:
    def hasSameDigits(self, s: str) -> bool:
        while len(s) > 2:
            d = ''
            for i in range(1,len(s)):
                d += str((int(s[i-1])+int(s[i]))%10)
            s = d
        return s[0] == s[1]
