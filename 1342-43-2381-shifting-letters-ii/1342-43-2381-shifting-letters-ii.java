class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        n = len(s)
        v = [0] * (n + 1)

        for l, r, d in shifts:
            v[l] += 1 if d else -1
            if r + 1 < n:
                v[r + 1] += -1 if d else 1

        for i in range(n):
            if i > 0:
                v[i] += v[i - 1]
            s = s[:i] + chr((ord(s[i]) - ord('a') + v[i]) % 26 + ord('a')) + s[i + 1:]

        return s
