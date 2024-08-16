class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn =1e9, mx = -1e9, ans = 0, n = arrays.size();
        for(int i = 0 ; i < n;i++){
            int sz = arrays[i].size();
            ans = max(ans,arrays[i][sz-1] - mn);  // as max
            ans = max(ans,mx - arrays[i][0]); // as min
            mn = min(mn,arrays[i][0]);
            mx = max(mx,arrays[i][sz-1]);
        }
        return ans;
    }
};