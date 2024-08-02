class Solution {
public:
    int n;
    int dp[1001][4];
    int solve(int idx,int sz,bool greater,vector<int>& rating){
        if(idx ==n)
            return 0;
        if(sz==3)return 1;
        
        int &ret = dp[idx][sz];
        if(~ret)return ret;
        ret = 0;
        for(int i = idx+1;i<n;i++){
            if(greater){
                if(rating[i] > rating[idx])
                    ret+=solve(i,sz+1,greater,rating);
            }
            else {
                if(rating[i] < rating[idx])
                    ret+=solve(i,sz+1,greater,rating);
            }
        }
        return ret;
    }
    int numTeams(vector<int>& rating) {
       n = rating.size();
       int ans = 0;
       memset(dp,-1,sizeof dp);
       for(int i = 0 ; i < n ;i++)
            ans+=solve(i,1,true,rating);
        memset(dp,-1,sizeof dp);
       for(int i = 0 ; i < n ;i++)
            ans+=solve(i,1,false,rating);
        return ans;

    }
};