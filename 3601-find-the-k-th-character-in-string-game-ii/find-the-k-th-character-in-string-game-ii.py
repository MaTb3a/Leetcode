class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        ans = 0
        k -= 1
        for i in range(k.bit_length() - 1, -1, -1):
            if (k >> i) & 1:
                ans += operations[i]
        return chr(ord("a") + (ans % 26))