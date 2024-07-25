class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>frq;
        for(auto it : nums)
            frq[it]++;
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(frq[a] == frq[b])
                return a > b;
            return frq[a] < frq[b];
        });
        return nums;
    }
};