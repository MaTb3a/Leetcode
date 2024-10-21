class Solution {
public:
    int solve(int idx,unordered_set<string> &vis,string &s){
        if(idx == s.size())
            return 0;

        int mx = 0;
        for(int i = idx ; i < s.size() ;i++) {
            string sub = s.substr(idx,i - idx + 1);
            if(vis.find(sub) == vis.end()){
                vis.insert(sub); // do 
                mx = max(mx,solve(i+1,vis,s)+1); // rec
                vis.erase(sub); // undo
            }
        }
        return mx;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> vis;
        return solve(0,vis,s);
    }
};