from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        order_dict = {value: index for index, value in enumerate(arr2)}
        def sort_key(x):
            return (order_dict.get(x, float('inf')), x)
        
        sorted_arr1 = sorted(arr1, key=sort_key)
        
        return sorted_arr1