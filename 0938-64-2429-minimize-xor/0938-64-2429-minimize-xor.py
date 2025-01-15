class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        diff = bin(num2).count('1') - bin(num1).count('1')
        for i in range(32):
            if diff > 0 and not (num1 & (1 << i)):
                diff -= 1
                num1 ^= (1 << i)
            elif diff < 0 and (num1 & (1 << i)):
                diff += 1
                num1 ^= (1 << i)
        return num1
