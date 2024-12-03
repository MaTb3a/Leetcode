class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size();
        string ans(n+m,' ');
        for(int i = 0,j=0 ; i < s.size();i++){
            if(j < spaces.size() && i == spaces[j])j++;
            ans[i+j] = s[i];
        }
        return ans;
    }
};