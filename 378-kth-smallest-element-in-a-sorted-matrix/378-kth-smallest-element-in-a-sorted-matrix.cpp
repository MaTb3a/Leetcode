class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v;
        for(auto t : matrix)
            for(auto it : t)
                v.push_back(it);
        sort(v.begin(),v.end());
        return v[k-1];
    }
};