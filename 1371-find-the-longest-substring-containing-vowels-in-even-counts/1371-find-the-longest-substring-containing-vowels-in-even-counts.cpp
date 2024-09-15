class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o';
    }
    int findTheLongestSubstring(string s) {
        int mask = 0; 
        
        unordered_map<int,int>mp;
        mp[mask] = -1;
        int ans = 0; 
        for(int j = 0 ; j < s.size();j++){
            if(isVowel(s[j])){
                int idx = s[j]-'a'; 
                mask ^= (1<<idx); 
            }
            if(mp.find(mask) == mp.end())
                mp[mask] = j;
            
            else ans = max(ans, j - mp[mask]);
                
        }
        return ans;

    

    }
};