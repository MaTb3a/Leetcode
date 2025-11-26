class Solution {
public:
   
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;
        int j = 0, n = s.size(),ans = 0;
        for(int i = 0 ; i < s.size();i++){
            while(j < n && mp[s[j]] == false){
                mp[s[j]]  = true;
                j+=1;
                ans=max(ans,j-i);
            }
            mp[s[i]] = false;
        }
        return ans;
    }
};