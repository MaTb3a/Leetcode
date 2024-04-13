class Solution:
    def getArea(self,heights:List[int]):
            stack = []
            area = 0
            for i,val in enumerate(heights):
                start = i
                while stack and stack[-1][1] > val:
                    idx,h = stack.pop()
                    area=max(area,h*(i-idx))
                    start = idx
                stack.append((start,val))
            return area
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:            
        heights = [0] * (1+len(matrix[0]))
        best = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    heights[j]+=1
                else:
                    heights[j] = 0
                
            best = max(best,self.getArea(heights))
        return best