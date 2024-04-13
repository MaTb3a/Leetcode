class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxArea = 0
        heights.append(0)
        for i in range(0,len(heights)):
            start = i
            while stack and stack[-1][1] > heights[i]:
                idx,val = stack.pop()
                maxArea=max(maxArea,val*(i-idx))
                start = idx
            stack.append((start,heights[i]))
        return maxArea