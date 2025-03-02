class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
      
        vector<vector<int>>v;
        int i = 0, j = 0 , n = nums1.size(),m = nums2.size();
        while(i < n || j < m){
            int id1 = i == n ? 1e9 : nums1[i][0];
            int id2 = j == m ? 1e9 : nums2[j][0];
            if(id1 < id2)v.push_back(nums1[i++]);
            else if (id2 < id1)v.push_back(nums2[j++]);
            else {
                nums1[i][1]+=nums2[j++][1];
                v.push_back(nums1[i++]);
            }
        }
        return v;

    }
};