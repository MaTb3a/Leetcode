class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,char>vis;
        for(int i = 0 ; i < s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(vis[t[i]])return false;
                mp[s[i]]=t[i];
            }
            else if(mp[s[i]] != t[i] ) return false;
            vis[t[i]]=1;
            s[i]=mp[s[i]];
        }
        cout<<s<<" "<<t<<endl;
        return s==t;
    }
};