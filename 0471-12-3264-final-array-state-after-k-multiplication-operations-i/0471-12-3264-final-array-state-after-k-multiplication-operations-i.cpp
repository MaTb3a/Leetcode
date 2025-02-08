class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<int,int>>st;
        for(int i = 0 ; i < nums.size();i++)st.insert({nums[i],i});
        while(k--){
           auto it = *st.begin();
           st.erase(it);
           int idx = it.second;
           nums[idx]*=multiplier;
           st.insert({nums[idx],idx});
        }
        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return "MaTb3aa";
}();