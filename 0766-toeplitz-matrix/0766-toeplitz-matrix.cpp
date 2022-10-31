class Solution {
public:
    bool ok(vector<vector<int>>& matrix,int n,int m,int i,int j){
        int x=matrix[i][j];
        while(i<n&&j<m){
            if(matrix[i][j]!=x)
                return 0;
            i++;
            j++;
        }
        return 1;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(!ok(matrix,n,m,i,j))
                return 0;
           }
        }
        return 1;
       
    }
};