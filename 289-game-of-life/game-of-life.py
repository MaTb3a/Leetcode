class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n,m = len(board),len(board[0])
        newBoard = [[0 for j in range(m)] for i in range(n)]

        dx = [0,0,1,-1,1,1,-1,-1]
        dy = [1,-1,0,0,1,-1,1,-1]

        def valid(x,y):
            return x >= 0 and y >=0 and x < n and y < m
        for i in range(n):
            for j in range(m):
            
                cnt = 0
                for k in range(8):
                    ddx = dx[k]+i
                    ddy = dy[k]+j
                    if valid(ddx,ddy) and board[ddx][ddy] == 1:
                        cnt+=1
                if board[i][j] == 0:
                    newBoard[i][j] = cnt == 3
                
                else:
                    newBoard[i][j] = cnt == 2 or cnt == 3
        
        for i in range(n):
            for j in range(m):
                if newBoard[i][j]:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
        
                    


