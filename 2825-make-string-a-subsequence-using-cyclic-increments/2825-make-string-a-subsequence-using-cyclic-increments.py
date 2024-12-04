class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        j = 0
        for c in str1:
            if j < len(str2) and (c == str2[j] or (ord(c) - ord(str2[j]) == 25) or (ord(c) - ord(str2[j]) == -1)):
                j += 1
        return j == len(str2)
