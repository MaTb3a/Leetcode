from typing import List
from itertools import permutations

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        ans = set()
        for perm in permutations(digits, 3):
            if perm[0] == 0:  
                continue
            num = perm[0]*100 + perm[1]*10 + perm[2]
            if num % 2 == 0:
                ans.add(num)
        return sorted(ans)
