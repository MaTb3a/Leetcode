class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>frq(1000003);
        int mx = 0;
        for(int i = 0 ; i < intervals.size();i++){
            frq[intervals[i][0]]++;
            frq[intervals[i][1]+1]--;
            mx=max(mx,intervals[i][1]+1);
        }
       
        int ans = 0;
        for(int i = 1 ; i <= mx ;i++){
            frq[i]+=frq[i-1];
            ans=max(ans,frq[i]);
        }

      
        return ans;
    }
};