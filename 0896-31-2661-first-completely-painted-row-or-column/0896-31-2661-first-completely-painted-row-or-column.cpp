class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
     
        int n = mat.size(), m = mat[0].size();
        vector<int>idx(arr.size()+1);
        for(int i = 0 ; i < arr.size();i++)
           idx[arr[i]] = i;
        
        int ans = 1e9;
        for(int i = 0 ; i < n;i++){
            int mx = 0;
            for(int j = 0; j < m ;j++){
                mx=max(mx,idx[mat[i][j]]);
            }
            ans=min(ans,mx);
        }
        for(int i = 0 ; i < m;i++){
            int mx = 0;
            for(int j = 0; j < n ;j++){
                mx=max(mx,idx[mat[j][i]]);
            }
            ans=min(ans,mx);
        }
            
       
        return ans;
    }
};