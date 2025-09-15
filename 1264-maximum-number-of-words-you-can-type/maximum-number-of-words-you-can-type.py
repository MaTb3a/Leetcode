class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        return sum(all(c not in set(brokenLetters) for c in s) for s in text.split())
