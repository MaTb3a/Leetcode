class Solution:
    def maxChunksToSorted(self, arr: list[int]) -> int:
        if not arr[0]:
            arr[0] = 1
        else:
            arr[1] = max(arr[0], arr[1])
            arr[0] = 0
        
        for i in range(1, len(arr)):
            arr[i] = max(arr[i], arr[i - 1])
            if arr[i] == i:
                arr[0] += 1
        
        return arr[0]
