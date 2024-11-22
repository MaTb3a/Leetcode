class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int mx = 0;
        unordered_map<string,int>mp;
        for(auto org : matrix){ // n
            string s,flip;
            for(int i = 0 ; i < m ; i++){
                s.push_back('0'+org[i]);
                flip.push_back('0'+(!org[i]));
            }   
            mp[s]++;mp[flip]++;
            mx = max(mx,mp[s]);
            mx = max(mx,mp[flip]);
        }
        return mx;
    }
};