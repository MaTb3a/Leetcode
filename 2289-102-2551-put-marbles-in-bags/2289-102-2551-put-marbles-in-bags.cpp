class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>v; 
        int n = weights.size();
        v.reserve(n-1);
        for(int i = 1 ; i <  n; i++)
            v.push_back(weights[i-1]+weights[i]);
        
        sort(v.begin(),v.end());
        long long ans = 0;
         for(int i = 0 ; i < k-1 ; i++)
            ans+=v[v.size()-i-1] - v[i];
        
        return ans;
        
    }
};