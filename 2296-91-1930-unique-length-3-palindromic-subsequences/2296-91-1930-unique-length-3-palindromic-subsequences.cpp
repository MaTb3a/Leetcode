class Solution {
public:
    int solve(string s){

        vector<vector<int>>v(26);
        for(int i = 0 ; i < s.size();i++)v[s[i]-'a'].push_back(i);
        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(v[i].size() < 2)continue;
            for(int j = 0 ; j < 26 ; j++){
                int x = v[i][0];
                auto it = upper_bound(v[j].begin(),v[j].end(),x);
                if(it == v[j].end())continue;
                auto it2 = upper_bound(v[i].begin(),v[i].end(),*it);
                if(it2 == v[i].end())continue;
                cnt++;
            }
        }
        return cnt;
    }

    int countPalindromicSubsequence(string s) {
        vector<int>L(26,-1),R(26);
        for(int i = 0 ; i < s.size();i++)
            if(L[s[i]-'a']==-1)L[s[i]-'a'] = i;
            else R[s[i]-'a'] = i;
        int ans = 0;
        for(int i = 0 ; i < 26;i++){
            if(!R[i])continue;
            bitset<26>vis;
            for(int j = L[i]+1 ; j < R[i]; j++){
                char ch = s[j];
                if(L[ch-'a'] != -1 && !vis[ch-'a'])ans++,vis[ch-'a'] = 1;
            }
        }
        return ans;
        
    }
};