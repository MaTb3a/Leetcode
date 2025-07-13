class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        multiset<int>mst(trainers.begin(),trainers.end());
        int cnt = 0;
        for(auto p : players){
            auto it = mst.lower_bound(p);
            if(it != mst.end()){
                cnt++;
                mst.erase(it);
            }
        }
        return cnt;
    }
};