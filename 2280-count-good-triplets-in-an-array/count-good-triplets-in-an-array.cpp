#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n = nums1.size();
        for(int i = 0 ; i < n;i++)mp[nums1[i]] = i;
        ordered_set st;
        long long ans = 0;
        for(int i = 0 ; i < n;i++){
            int idx = mp[nums2[i]];
            int l = st.order_of_key(idx); // log
            int r = (n - idx - 1) - (st.size() - l);
            ans+=(1LL*l*r);
            st.insert(idx);
        }
        return ans;
    }
};