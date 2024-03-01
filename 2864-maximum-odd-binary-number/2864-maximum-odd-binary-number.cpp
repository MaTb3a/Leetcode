class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = count(s.begin(),s.end(),'1');
        string ans = string(s.size(),'0');
        ans.back() = '1';one--;
        for(int i = 0 ; i < ans.size();i++)
            if(one)ans[i]='1',one--;
        return ans;
        
    }
};