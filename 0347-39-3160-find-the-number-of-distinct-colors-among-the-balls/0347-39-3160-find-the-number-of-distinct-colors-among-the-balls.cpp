class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>v(n);
        unordered_map<int,int>mp,colorCnt;
        for(int i = 0 ; i < n ;i++){
            int ball = queries[i][0], color = queries[i][1];
            if(mp[ball]){
                int oldColor = mp[ball];
                colorCnt[oldColor]--;
                if(!colorCnt[oldColor])colorCnt.erase(oldColor);
            }
            colorCnt[color]++;
            mp[ball] = color;
            v[i] = (colorCnt.size());
        }
        return v;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();