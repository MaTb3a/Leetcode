class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def rowCheck(r):
            vis = set()
            for i in range(9):
                if board[r][i] != '.' and board[r][i] in vis:
                    return False
                vis.add(board[r][i])
            return True
        
        def colCheck(c):
            vis = set()
            for i in range(9):
                if board[i][c] != '.' and board[i][c] in vis:
                    return False
                vis.add(board[i][c])
            return True

        def subCheck(r,c):
            vis = set()
            for i in range(3):
                for j in range(3):
                    if board[r+i][c+j] != '.' and board[r+i][c+j] in vis:
                        return False
                    vis.add(board[r+i][c+j])
            return True

        for i in range(9):
            if not rowCheck(i) or not colCheck(i):
                return False
        for i in range(3):
            for j in range(3):
                if not subCheck(i*3,j*3):
                    return False
        return True

