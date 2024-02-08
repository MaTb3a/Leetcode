class Solution {
public:
    vector<int>v;
    vector<vector<int>>dp;
    int solve(int idx,int rem){
        if(!rem)return 0;
        if(rem < 0 || idx == v.size())return 1e9;
        int &ret = dp[idx][rem];
        if(~ret)return ret;
        ret = 1e9;
        ret=min(ret,solve(idx+1,rem));
        ret=min(ret,solve(idx,rem-v[idx])+1);
        return ret;
    }
    int numSquares(int n) {
        long long i = 1;
        while(i*i <=n)v.push_back(i*i++);
        dp = vector<vector<int>>(v.size(),vector<int>(n+1,-1));
        return solve(0,n);
    }
};