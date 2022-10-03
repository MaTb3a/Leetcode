class Solution {
public:
    int dp[100005][27];
    int n;
    int solve(int idx,int lst,string &colors,vector<int>& neededTime){
        if(idx==n)
            return 0;
        int &ret=dp[idx][lst];
        if(~ret)
            return ret;
        ret=0x3f3f3f3f;
        if(colors[idx]-'a'!=lst)
            ret=min(ret,solve(idx+1,colors[idx]-'a',colors,neededTime));
       
        ret=min(ret,solve(idx+1,lst,colors,neededTime)+neededTime[idx]);
        return ret;
    }
    int minCost(string colors, vector<int>& neededTime) {
        n = colors.size();
        memset(dp,-1,sizeof dp);
        return solve(0,26,colors,neededTime);
    }
};