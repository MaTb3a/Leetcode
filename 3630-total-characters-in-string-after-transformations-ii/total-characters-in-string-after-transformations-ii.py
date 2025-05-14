MOD = 10**9 + 7

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: list[int]) -> int:
        T = self.getTransformationMatrix(nums)
        poweredT = self.matrixPow(T, t)

        count = [0] * 26
        lengths = [0] * 26

        for c in s:
            count[ord(c) - ord('a')] += 1

        for i in range(26):
            for j in range(26):
                lengths[j] = (lengths[j] + count[i] * poweredT[i][j]) % MOD

        return sum(lengths) % MOD

    def getTransformationMatrix(self, nums):
        T = [[0] * 26 for _ in range(26)]
        for i in range(len(nums)):
            for step in range(1, nums[i] + 1):
                T[i][(i + step) % 26] += 1
        return T

    def getIdentityMatrix(self, size):
        I = [[0] * size for _ in range(size)]
        for i in range(size):
            I[i][i] = 1
        return I

    def matrixMult(self, A, B):
        size = len(A)
        C = [[0] * size for _ in range(size)]
        for i in range(size):
            for j in range(size):
                for k in range(size):
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
        return C

    def matrixPow(self, M, n):
        if n == 0:
            return self.getIdentityMatrix(len(M))
        if n % 2 == 1:
            return self.matrixMult(M, self.matrixPow(M, n - 1))
        half = self.matrixPow(M, n // 2)
        return self.matrixMult(half, half)