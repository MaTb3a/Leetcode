class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (cnt == 0) {
                ans = x;
                cnt = 1;
            } else if (ans == x) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ans;
    }
};
