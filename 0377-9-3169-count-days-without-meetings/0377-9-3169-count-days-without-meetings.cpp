class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int d = 0, ans = 0;
        sort(meetings.begin(),meetings.end());
        for(auto it : meetings){
            if(it[0] > d)ans+=it[0] - d -1;
            d = max(d,it[1]);
        }
        return ans + days-d;
    }
};