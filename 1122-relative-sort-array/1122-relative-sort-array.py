from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = {value: index for index, value in enumerate(arr2)}
        def sort_key(x):
            return (dic.get(x, float('inf')), x)
        
        ans = sorted(arr1, key=sort_key)
        
        return ans