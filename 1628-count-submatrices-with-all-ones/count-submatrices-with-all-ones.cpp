class Solution {
public:
    inline int get(int x,int y,int n,int m,vector<vector<int>>& mat){
          return (x < 0 || y < 0 || x >= n || y >= m) ? 0 : mat[x][y];
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        for(int i = 0 ; i < n;i++)
            for(int j = 1 ; j < m ;j++)
                mat[i][j]+=mat[i][j-1];
        
         for(int i = 1 ; i < n;i++)
            for(int j = 0 ; j < m ;j++)
                mat[i][j]+=mat[i-1][j];
        
        int ans = 0;
         for(int i = 0 ; i < n;i++)
            for(int j = 0 ; j < m ;j++)
                for(int i2 = i ; i2 < n; i2++)
                    for(int j2 = j; j2 < m ;j2++){
                        int x = i2-i+1, y = j2 - j + 1;
                        int ones = mat[i2][j2] - get(i-1,j2,n,m,mat) - get(i2,j-1,n,m,mat) + get(i-1,j-1,n,m,mat);
                        ans+=ones == (x*y);
                    }
            
        return ans;
    }
};