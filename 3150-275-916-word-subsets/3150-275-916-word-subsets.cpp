class Solution {
public:
    vector<int>solve(string &s){
        vector<int>v(26);
        for(char ch : s)
            v[ch-'a']++;
        return v;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>frq(26);
        for(string s : words2){
            vector<int>tmp = solve(s);
            for(int i = 0 ; i <26 ;i++)
                frq[i] = max(frq[i],tmp[i]);
        }
        vector<string>ans;
        for(string s : words1){
            vector<int>tmp = solve(s);
            bool ok = true;
            for(int i = 0 ; i < 26 ;i++)
                if(frq[i]> tmp[i])
                    ok = false;

            if(ok)ans.push_back(s);
        }
        return ans;


    }
};