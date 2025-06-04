class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        vis_row = [[ False for _ in range(10)] for _ in range(10)]
        vis_col = [[ False for _ in range(10)] for _ in range(10)]
        vis_sub_boxes = [[ set() for _ in range(3)] for _ in range(3)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = int(board[i][j])
                vis_row[i][num] = True
                vis_col[j][num] = True
                vis_sub_boxes[i//3][j//3].add(num)

        
        # print(vis_row)
        # print(vis_col)
        # print(vis_sub_boxes)

        def solve(i,j):
            if j == 9:
                return solve(i+1,0)

            if i == 9:
                return True
            
            if board[i][j] != '.':
                return solve(i,j+1)

            for num in range(1,10):
                if vis_row[i][num] == True or vis_col[j][num] == True or num in vis_sub_boxes[i//3][j//3]:
                    continue
                vis_row[i][num] = True 
                vis_col[j][num] = True
                vis_sub_boxes[i//3][j//3].add(num)
                board[i][j] = str(num)
                if solve(i,j+1):
                    return True
                board[i][j] = "."
                vis_row[i][num] = False 
                vis_col[j][num] = False
                vis_sub_boxes[i//3][j//3].remove(num)
            return False

        
        solve(0,0)


        