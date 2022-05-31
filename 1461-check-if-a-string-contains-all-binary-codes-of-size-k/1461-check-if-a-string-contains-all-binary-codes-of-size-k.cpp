class Solution {
public:
   
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return 0;
        unordered_set<int>st;
        int x=0;
        for(int j=0;j<k;j++){
            x<<=1;
            x|=(s[j]-'0');
        }
        st.insert(x);
        for(int j=k;j<s.size();j++){
            x&=~(1<<(k-1));
             x<<=1;
            x|=(s[j]-'0');
            st.insert(x);
        }
        return st.size()==(1<<k);
    }
  
};