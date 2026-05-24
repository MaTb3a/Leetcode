class Solution {
public:
    static int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int dist=0;
        for (int l=0, r=0; l<n1 && r<n2; r++) {
            const int R=nums2[r];
            for( ; l<n1 && l<=r && nums1[l]>R; l++);
            if(l<n1 && l<=r)  dist=max(dist, r-l);
        }
        return dist;
    }
};