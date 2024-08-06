class Solution {
public:
    int minimumPushes(string word) {
        vector<int>vis(26);
        for(char ch : word)vis[ch-'a']++;
        sort(vis.rbegin(),vis.rend());

        int ans = 0;
        for(int i = 0 ; i < 26;i++)
            ans += vis[i] * (i/8 +1);
        return ans;
    }
};