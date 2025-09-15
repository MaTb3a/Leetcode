class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        for s in text.split(' '):
            count = 1
            for c in brokenLetters:
                if c in s:
                    count = 0
                    break
            ans+=count
        return ans
