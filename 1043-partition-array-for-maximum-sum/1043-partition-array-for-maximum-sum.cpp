class Solution {
public:
    int dp[505][505],n;
    int solve(int st,int ed,vector<int>& arr, int k){
        if(ed == n)return 0;
        int &ret = dp[st][ed];
        if(~ret)return ret;
        int mx = 0;
        if(ed-st>=k)return 0;
        
        for(int i=st;i<=ed;i++)mx=max(mx,arr[i]);
        ret=max(ret,solve(ed+1,ed+1,arr,k)+mx*(ed-st+1));
        ret=max(ret,solve(st,ed+1,arr,k));
        return ret;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp,-1,sizeof dp);
        return solve(0,0,arr,k);
    }
};