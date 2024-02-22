class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1);
        for(auto t : trust)v[t[1]]++;
        int mx = *max_element(v.begin(),v.end());
        int val = -1;
        if(mx != n-1)return -1;
        for(int i = 0 ; i <= n ;i++)if(v[i] == mx)val = i;
        for(auto t : trust)if(t[0]==val)return -1;
        return val;
    }
};