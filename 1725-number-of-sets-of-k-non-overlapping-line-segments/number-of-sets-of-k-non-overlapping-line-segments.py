class Solution:
    MOD = 10**9 + 7

    def mod_pow(self, base: int, exp: int) -> int:
        result = 1

        while exp > 0:
            if exp & 1:
                result = result * base % self.MOD

            base = base * base % self.MOD

            exp >>= 1

        return result

    def numberOfSets(self, n: int, k: int) -> int:
        N = n + k - 1
        R = 2 * k

        R = min(R, N - R)

        numerator = 1
        denominator = 1

        for i in range(1, R + 1):
            numerator = numerator * (N - R + i) % self.MOD

            denominator = denominator * i % self.MOD

        inverse_denominator = self.mod_pow(
            denominator,
            self.MOD - 2
        )

        return numerator * inverse_denominator % self.MOD