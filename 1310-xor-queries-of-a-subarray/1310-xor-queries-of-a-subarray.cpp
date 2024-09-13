class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> v(q);
        for(int i = 1;i < arr.size();i++)
            arr[i] ^=  arr[i-1];
        
        for(int i = 0 ; i < q ;i++){
            int l = queries[i][0], r = queries[i][1]; 
            v[i] =  arr[r] ^ (l > 0 ? arr[l-1] : 0);
        }
        return v;
    }
};