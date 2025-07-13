class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < numbers.size();i++){
            if(mp.find(target- numbers[i]) != mp.end())return {mp[target-numbers[i]]+1,i+1};
            mp[numbers[i]] = i;
        }
        return {-1,-1};
    }
};