class Solution {
public:
    int get(int x,int y,int n,int m, vector<vector<int>>& matrix){
        return (x < 0 || y < 0 || x >= n || y >= m ? 0 : matrix[x][y]);
    }
    
    bool solve(int x1,int y1,int len,int n,int m,vector<vector<int>>& matrix){
        int x2 = x1 + len, y2 = y1 + len;
        if(x2 >= n || y2 >= m)return 0;
         int grid = get(x2,y2,n,m,matrix) - get(x2,y1-1,n,m,matrix) - get(x1-1,y2,n,m,matrix)+ get(x1-1,y1-1,n,m,matrix);
        return grid == (len+1) * (len+1) ;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(),len = min(n,m);

        for(int i = 0 ; i < n;i++)
            for(int j = 1 ; j < m;j++)
                matrix[i][j]+=matrix[i][j-1];

        for(int i = 1 ; i < n;i++)
            for(int j = 0 ; j < m;j++)
                matrix[i][j]+=matrix[i-1][j];
        int cnt = 0;
        for(int k = 0 ; k < len;k++)
            for(int i = 0 ; i < n;i++)
                for(int j = 0 ; j < m;j++)
                    cnt+=solve(i,j,k,n,m,matrix);
                
        return cnt;
                
    }
};