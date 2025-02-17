class Solution {
public:
    bitset<8>vis;
    int solve(string &s){
        int ret = 1;
        for(int i = 0 ; i < s.size();i++){
            if(vis[i] || (i  && s[i] == s[i-1] && !vis[i-1] ))continue;
            vis[i] = true;
            ret+=solve(s);
            vis[i] = false;
        }
        return ret;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        return solve(tiles)-1;
    }
};