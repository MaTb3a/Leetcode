class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>v,ans;
        int rep = 1;
        while (n) {
            if (n&1) {
                v.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }
        int mod = 1e9+7;
        for(auto x : queries){
            long long cur = 1;
            for(int i = x[0] ; i <= x[1] ;i++){
                cur=(cur * v[i])%mod;
            }
            ans.push_back(cur);
        }
        return ans;
        
    }
};