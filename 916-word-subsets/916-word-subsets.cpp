class Solution {
public:
    vector<int> solve(string s)
    {
        vector<int> frq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            frq[s[i] - 'a']++;
        }
        return frq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans; 
       vector<int> check(26, 0);   
	   
		for(auto &x : words2) 
        {
            vector<int> frq = solve(x);
            for(int i = 0; i < 26; i++)
            {
                check[i] = max(frq[i], check[i]);
            }
        }
        

        for(auto &x : words1)
        {
            vector<int> frq = solve(x); 
            bool f = true;
            for(int i = 0; i < 26; i++)
            {
                if(frq[i] < check[i])
                {
                    f = false;
                    break;
                }
            }
            if(f) ans.push_back(x);
        }
        return ans;
    }
};