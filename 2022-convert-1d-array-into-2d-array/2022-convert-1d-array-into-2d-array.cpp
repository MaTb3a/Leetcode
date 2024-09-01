class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>> v(m,vector<int>(n));
         int idx =0;
         if(n*m != original.size())return {};
         for(int i = 0 ; i < m ;i++)
            for(int j = 0 ; j < n;j++)
                v[i][j] = original[idx++];
        return v;
    }
};