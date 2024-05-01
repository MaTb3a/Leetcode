class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        for i in range(0,len(word)):
            if word[i] == ch:
                return word[i::-1] + word[i+1:]
        return word