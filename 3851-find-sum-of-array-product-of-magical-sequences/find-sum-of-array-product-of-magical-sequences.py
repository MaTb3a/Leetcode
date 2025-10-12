MOD = 10**9 + 7
from functools import lru_cache
import math
from typing import List

class Solution:
    def magicalSum(self, total_count: int, target_odd: int, numbers: List[int]) -> int:
        
        @lru_cache(None)
        def solve(rem, odd, idx, carry):
            if rem < 0 or odd < 0 or rem + carry.bit_count() < odd:
                return 0
            if rem == 0:
                return 1 if odd == carry.bit_count() else 0
            if idx >= len(numbers):
                return 0
            
            ans = 0
            for take in range(rem + 1):
                ways = math.comb(rem, take) * pow(numbers[idx], take, MOD) % MOD
                new_carry = carry + take
                ans += ways * solve(rem - take, odd - (new_carry % 2), idx + 1, new_carry // 2)
                ans %= MOD
            return ans
        
        return solve(total_count, target_odd, 0, 0)