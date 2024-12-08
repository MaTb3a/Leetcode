class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
       
        vector<vector<int>>v;
        for(auto time : events){
            v.push_back({time[0],0,time[2]});
            v.push_back({time[1],1,time[2]});
        }
        sort(v.begin(),v.end());
        int mx = 0, mxV = 0;
        for(auto it : v){
            if(it[1]==1)  mxV=max(mxV,it[2]);
            else mx=max(mx,it[2]+mxV);
        }
        return mx;
    }
    
};