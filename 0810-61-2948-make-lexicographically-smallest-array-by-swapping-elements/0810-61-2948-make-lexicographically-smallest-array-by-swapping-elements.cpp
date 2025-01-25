class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n;i++)v.push_back({nums[i],i});
        sort(v.begin(),v.end());

        for(int i = 0 ; i < n;){
            vector<int>idx;
            idx.push_back(v[i].second);
            int j = i + 1;
            while( j < n && v[j].first - v[j-1].first <= limit)idx.push_back(v[j].second),j++;
            sort(idx.begin(),idx.end());
            for(int k = 0 ; k < idx.size();k++)nums[idx[k]] = v[i+k].first;
            i = j;
        }
        return nums;


    }
};