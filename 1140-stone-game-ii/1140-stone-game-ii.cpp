class Solution {
public:
    int n;
    int dp[101][102][2];
    int solve(int idx,int m,bool player,vector<int>& piles){
        if(idx == n)
            return 0;
     
        int &ret = dp[idx][m][player];  
        if(~ret)
            return ret;
        ret = player ? -1 : INT_MAX;
        int sum = 0;
        for(int x = 1 ; x <= 2*m ;x++){
           
            if(idx+x-1 >=n)break;
            sum+=piles[idx+x-1];
            if(player) 
                ret=max(ret,solve(idx+x,max(m, x),!player,piles)+sum);
            else   
                ret=min(ret,solve(idx+x,max(m, x),!player,piles));
        }
        return ret;

    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof dp);
        return solve(0,1,1,piles);
    }
};