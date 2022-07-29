class Solution {
public:
    bool ok(string a,string b){
        if(a.size()!=b.size())
            return 0;
        unordered_map<char,char>mp;
        for(int i=0;i<a.size();i++){
            if(mp.find(a[i])==mp.end()){
                mp[a[i]]=b[i];
            }
            else if(mp[a[i]]!=b[i])
                return 0;
        }
      
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto t : words){
             if(ok(t,pattern) && ok(pattern,t))
                 ans.push_back(t);
        }
        return ans;
    }
};