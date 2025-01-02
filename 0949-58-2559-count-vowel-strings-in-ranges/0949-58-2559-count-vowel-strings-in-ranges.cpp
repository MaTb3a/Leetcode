class Solution {
public:
    inline bool inVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n);
        for(int i = 0 ; i < n ; i++){
            pre[i] = inVowel(words[i][0]) & inVowel(words[i].back());
            if(i)pre[i]+=pre[i-1];
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i = 0 ; i < q;i++){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = pre[r] - (l ? pre[l-1] : 0);
        }
        return ans;

    }
};