class Solution {
public:
    unordered_map<char,int>vis;
    bool valid(){
        for(auto it : vis)if(it.second>1)return false;
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        
        int j = 0,ans = 0;
        for(int i = 0 ;i < s.size();i++){
            vis[s[i]]++;
            while(!valid()){
                vis[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }

        return max(ans,(int)s.size()-j);

    }
};