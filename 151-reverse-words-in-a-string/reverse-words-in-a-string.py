class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split()
        print(words)
        return " ".join(reversed(words))