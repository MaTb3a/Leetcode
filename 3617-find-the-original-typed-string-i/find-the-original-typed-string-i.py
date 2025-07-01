class Solution:
    def possibleStringCount(self, word: str) -> int:
        return sum(1 if word[i] == word[i-1] else 0 for i in range(1,len(word)))+1