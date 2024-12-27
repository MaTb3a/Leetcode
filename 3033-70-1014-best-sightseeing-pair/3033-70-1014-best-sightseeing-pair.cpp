class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       
        int n = values.size(),mx = 0,dp;
        dp = values[0];
        for(int j = 1 ; j < n ; j++){
           mx=max(mx,values[j]-j+dp);
           dp = max(dp,values[j] +j);
        }
        return mx;
    }
};