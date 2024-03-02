class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int freq[10001];
        for(auto t : nums){
            if(t<0)t=-t;
            freq[t]++;
        }
        int idx = 0;
        vector<int>v(nums.size());
        for(int i = 0 ; i < 10001;i++)
            while(freq[i])v[idx++] = i*i,freq[i]--;
        return v;
    }
};