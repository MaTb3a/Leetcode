class Solution:
    def rotateTheBox(self, box):
        n = len(box)
        m = len(box[0])

        rotated_box = [['.'] * n for _ in range(m)]
        
        for i in range(n):
            last_stone = m - 1
            for j in range(m - 1, -1, -1):
                if box[i][j] == '*':
                    last_stone = j - 1
                    rotated_box[j][n - i - 1] = '*'
                elif box[i][j] == '#':
                    rotated_box[last_stone][n - i - 1] = '#'
                    last_stone -= 1

        return rotated_box
