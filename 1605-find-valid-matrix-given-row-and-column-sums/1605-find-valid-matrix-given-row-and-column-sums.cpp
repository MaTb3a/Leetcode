class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>matrix(n,vector<int>(m));
        for(int i =0,j=0 ; i < n && j < m ;){
                matrix[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -=matrix[i][j];
                colSum[j] -=matrix[i][j];
                if(!rowSum[i])i++;
                if(!colSum[j])j++;
        }
    
        return matrix;
    }
};