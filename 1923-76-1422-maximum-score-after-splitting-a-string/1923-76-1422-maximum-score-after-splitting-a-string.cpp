class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = count(s.begin(),s.end(),'1'),ans = 0;
        s.pop_back();
        for(char ch : s){
            ones-=ch=='1';
            zeros+=ch=='0';
            ans=max(ans,ones+zeros);
        }
        return ans;
    }
};