class Solution {
public:
    int dp[101][22][101];
    int solve(int idx,int lstColor,int CurTarget,vector<int>& houses, vector<vector<int>>& cost, int &m, int &n, int &target){
        if(idx==m){
            if(CurTarget!=target)
                return 1e9;
            return 0;
        }
        int &ret=dp[idx][lstColor][CurTarget];
        if(~ret)return ret;
        ret=1e9;
        if(!houses[idx])
            for(int col=1;col<=n;col++)
                ret=min(ret,solve(idx+1,col,CurTarget+(col!=lstColor),houses,cost,m,n,target)+cost[idx][col-1]);
        
        else 
            ret=min(ret,solve(idx+1,houses[idx],CurTarget+(houses[idx]!=lstColor),houses,cost,m,n,target));

        return ret;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,21,0,houses,cost,m,n,target);
      
        return (ans == 1e9 ? -1 : ans);
    }
};