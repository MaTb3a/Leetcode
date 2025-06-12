class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int idx = 0;
        int l = intervals[0][0],r = intervals[0][1];
        for(auto &it : intervals){
            if ( r >= it[0]) r=max(r,it[1]);
            else{
                intervals[idx++] = {l,r};
                l = it[0];r = it[1];
            }
        }
        intervals[idx++] = {l,r};
        intervals.erase(intervals.begin()+idx,intervals.end());
        return intervals;
    }
};