class Solution {
public:
    unordered_map<string,bool>vis;
    bool subFolder(string s){
       while(s.size()){
          s.pop_back();
          if(s.size() && s.back() == '/'){
            s.pop_back();
            if(vis.find(s) != vis.end())return true;
          }
       }
       return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),[&](string a,string b){
            return a.size() < b.size();
        });
        vector<string>v;

        for(int i = 0; i < folder.size();i++){
            if(subFolder(folder[i]))continue;
            vis[folder[i]] = true;
            v.push_back(folder[i]);
        }
        return v;
        // "/a","/a/b","/c/d","/c/d/e","/c/f"
        // a 
        // a b
        // c d
        // c d e
        // c f
    }
};