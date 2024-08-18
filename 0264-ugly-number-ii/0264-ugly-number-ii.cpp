class Solution {
public:
    int nthUglyNumber(int n) {

        int ugly; 
        set<long long> st;
        st.insert(1);
        for(int i = 0 ; i < n ;i++){
            ugly = *st.begin();
            st.erase(ugly);
            st.insert(ugly*2LL);
            st.insert(ugly*3LL); 
            st.insert(ugly*5LL);
        }
        return ugly;
    }
};