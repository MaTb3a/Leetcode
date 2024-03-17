class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        vector<int>tmp = intervals[0];
        for(int i = 1 ; i < intervals.size() ;i++){
            if(tmp[1] >= intervals[i][0])tmp[1] = max(tmp[1],intervals[i][1]);
            else {
                v.push_back(tmp);
                tmp = intervals[i];
            }
        }
        v.push_back(tmp);
        return v;
        
        
    }
};
