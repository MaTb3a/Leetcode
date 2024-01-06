class Solution {
public:
    int dp[50005];
    int solve(int idx,vector<pair<pair<int,int>,int>>&v){
        if(idx==v.size())return 0;
        int &ret = dp[idx];
        if(~ret)return ret;
        ret=max(ret,solve(idx+1,v));
        int cur = lower_bound(v.begin(),v.end(),make_pair(make_pair(v[idx].first.second,0),0))-v.begin();
        ret=max(ret,solve(cur,v)+v[idx].second);
        return ret;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>v;
        memset(dp,-1,sizeof dp);
        for(int i = 0 ; i < startTime.size();i++){
            v.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(v.begin(),v.end());
        return solve(0,v);
    }
};