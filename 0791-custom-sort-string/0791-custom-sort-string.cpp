class Solution {
public:
    
    string customSortString(string order, string s) {
        vector<int>vis(26,30);
        for(int i = 0 ; i < order.size() ;i++)vis[order[i]-'a']=i;
        sort(s.begin(),s.end(),[&](char a,char b){
            return vis[a-'a'] < vis[b-'a'];
        });
        return s;
    }
};