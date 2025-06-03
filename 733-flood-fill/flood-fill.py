class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        q = []
        q.append([sr,sc])
        d = [-1,0,1,0,-1]
        n = len(image)
        m = len(image[0])
        c = image[sr][sc]
        image[sr][sc] = color
        while q:
            x,y = q.pop()
            for i in range(4):
                dx = x+d[i]
                dy = y+d[i+1]
                if dx < 0 or dy < 0 or dx >= n or dy >= m or image[dx][dy] != c or image[dx][dy] == color:
                    continue
                image[dx][dy] = color
                q.append([dx,dy])
        return image
                

