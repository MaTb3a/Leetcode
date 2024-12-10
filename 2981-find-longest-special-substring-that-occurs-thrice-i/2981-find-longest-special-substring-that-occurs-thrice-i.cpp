class Solution {
public:
    bool ok(string &s,int md){
        vector<int>vis(26);
        int l = 0;
        for(int r = 0 ; r < s.size();r++){
            if(s[r] != s[l]) l = r;
            if(r-l+1>=md)vis[s[r]-'a']++;
            if(vis[s[r]-'a']>2)return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int st = 1,ed = s.size() ,cur = -1,md;
        while(st<=ed){
            md = (st+ed)/2;
            if(ok(s,md)){
                cur = md;
                st = md+1;
            }
            else ed = md-1;
        }
        return cur;
    }
};