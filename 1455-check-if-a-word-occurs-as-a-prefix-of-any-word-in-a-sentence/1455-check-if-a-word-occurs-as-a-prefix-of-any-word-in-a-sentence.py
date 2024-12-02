class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        idx = 1
        words = sentence.split()
        for word in words:
            if word.startswith(searchWord):
                return idx
            idx += 1
        return -1
