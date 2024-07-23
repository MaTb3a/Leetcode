class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int>idx(n); // 0 1 2 3 
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int idx1,int idx2){
            return heights[idx1] > heights[idx2];
        });
        vector<string>ans(n);
         for(int i = 0 ; i < n ;i++)
            ans[i] = names[idx[i]];
        return ans;
    }
};