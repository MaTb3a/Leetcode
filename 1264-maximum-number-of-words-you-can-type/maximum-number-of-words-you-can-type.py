class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        return sum(all(c not in (brokenLetters) for c in s) for s in text.split())
