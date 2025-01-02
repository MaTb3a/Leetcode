class Solution:
    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        def is_vowel(ch: str) -> bool:
            return ch in 'aeiou'

        n = len(words)
        pre = [0] * n

        for i in range(n):
            pre[i] = is_vowel(words[i][0]) and is_vowel(words[i][-1])
            if i > 0:
                pre[i] += pre[i - 1]

        ans = []
        for l, r in queries:
            ans.append(pre[r] - (pre[l - 1] if l > 0 else 0))
        
        return ans
