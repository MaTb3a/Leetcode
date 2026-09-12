class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dx = [0,0,1,-1,1,1,-1,-1]
        dy = [1,-1,0,0,-1,1,-1,1]

        n,m = len(board),len(board[0])
        # 0 1 2 3

        # 0 -> 0 -> 0 
        # 0 -> 1 -> 1

        # 1 -> 0 -> 2
        # 1 -> 1 -> 3
        # 00000000
        # 00000001 >> 1
        # 00000010

        def valid(x,y):
            return x >=0 and y >= 0 and x < n and y < m

        for i in range(n):
            for j in range(m):
                cnt = 0
                for k in range(8):
                    ddx = dx[k] + i
                    ddy = dy[k] + j
                    if valid(ddx,ddy):
                        cnt+=board[ddx][ddy]&1
                
                if board[i][j] == 0:
                    if cnt == 3:
                        board[i][j] |= 2 
                else:
                    if cnt == 2 or cnt == 3:
                        board[i][j] |= 2
        
        for i in range(n):
            for j in range(m):
                board[i][j] >>=1
        
        


        
        
        