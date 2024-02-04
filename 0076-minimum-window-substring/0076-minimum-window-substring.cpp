class Solution {
public:
    unordered_map<char,int>mp1,mp2;
    bool check(){
        for(auto t : mp2){
            if(mp1[t.first] < t.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l = 0 , r = 0 , len = 1e9 , n = s.size();
        for(auto t : t)mp2[t]++;
        pair<int,int>ans={-1,-1};
        if(t.size() > s.size())return "";
        while(r <= n ){
            if(check()){
                if(r-l+1 < len){
                    len = r-l+1;
                    ans = {l,r-1};
                }
                mp1[s[l++]]--;
            }
            else {
                mp1[s[r++]]++;
            }
        }
        if(len == 1e9)return "";
        return s.substr(ans.first,ans.second-ans.first+1);
    }
};