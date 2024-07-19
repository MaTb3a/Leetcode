class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>row(n,INT_MAX),column(m);

        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                row[i] = min(row[i],matrix[i][j]);
                column[j] = max(column[j],matrix[i][j]);
            }
        }
        vector<int>ans;
         for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m ;j++)
                if(matrix[i][j] == row[i] && matrix[i][j] == column[j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};