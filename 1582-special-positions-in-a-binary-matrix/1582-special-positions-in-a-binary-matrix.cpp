class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                int tmp = 0;
                if(!mat[i][j])continue;
                for(int k = 0 ; k < m;k++)tmp+=mat[i][k];
                for(int k = 0 ; k < n;k++)tmp+=mat[k][j];
                cnt+=tmp==2;
            }
        }
        return cnt;
    }
};