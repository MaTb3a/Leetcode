#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        ordered_set st;
        st.insert(arr[0]);
        int cnt = 0;
        for(int j = 1 ; j < arr.size();j++){
            for(int k = j+1; k < arr.size();k++){
                if(abs(arr[j] - arr[k]) > b)continue;
                int mx = min(a+arr[j],c+arr[k]);
                int mn = max(arr[j]-a,arr[k]-c);
                if(mn <= mx)cnt+=st.order_of_key(mx+1)-st.order_of_key(mn);
            }
            st.insert(arr[j]);
        }
        return cnt;
    }
};