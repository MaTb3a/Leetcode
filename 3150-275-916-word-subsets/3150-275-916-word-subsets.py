class Solution:
    def solve(self, s: str) -> list[int]:
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1
        return freq

    def wordSubsets(self, words1: list[str], words2: list[str]) -> list[str]:
        frq = [0] * 26
        for word in words2:
            tmp = self.solve(word)
            for i in range(26):
                frq[i] = max(frq[i], tmp[i])

        result = []
        for word in words1:
            tmp = self.solve(word)
            if all(frq[i] <= tmp[i] for i in range(26)):
                result.append(word)

        return result
