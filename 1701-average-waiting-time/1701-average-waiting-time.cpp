class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int time = 0;
        for(auto it : customers){
            time = max(time,it[0]) + it[1];
            ans += time - it[0];
        }
        return ans / (1.0 * size(customers));
    } 
};