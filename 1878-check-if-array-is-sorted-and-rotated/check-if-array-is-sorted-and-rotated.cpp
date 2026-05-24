class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n;i++){
            int j = i+1,lst = nums[i];
            while(j < n && nums[j]>=lst)lst = nums[j++];
            if(j != n)continue;
            j = 0;
            while(j < i && nums[j] >= lst)lst = nums[j++];
            if(i == j)return true;
        }
        return false;
    }
};