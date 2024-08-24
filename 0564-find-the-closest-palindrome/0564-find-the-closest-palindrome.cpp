class Solution {
public:
    string nearestPalindromic(string s) {
        
            int n = s.size();
            vector<long long>cases;
            cases.push_back(pow(10,n)+1);
            cases.push_back(pow(10,n-1)-1);

            int md = (n+1)/2;
            long long prefix = stoll(s.substr(0,md));
            vector<long long>tmp = {prefix,prefix+1,prefix-1};
            for(auto it : tmp){      
                string suf = to_string(it); // 123
                if(n&1)suf.pop_back();//12
                reverse(suf.begin(),suf.end()); //21
                string all = to_string(it) + suf;
                cases.push_back(stoll(all));
            }
            long long original = stoll(s),ans,dif = 1e18;
            for(auto it : cases){
                if(original!=it){
                    if(abs(original - it) < dif) dif = abs(original - it),ans = it;
                    if(abs(original - it) == dif)ans=min(ans,it);
                }
            }
            return to_string(ans);
    }
};