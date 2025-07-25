class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        while(st.size() && *st.begin() < 0)st.erase(st.begin());
        if(st.empty())return mx;
        int sum = 0;
        for(int x : st)
            sum+=(x>0 ? x : 0);

        return sum;
    }
};