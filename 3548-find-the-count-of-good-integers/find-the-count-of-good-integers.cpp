class Solution {
public:
    unordered_set<string>vis;
    int fact[11] = {1};
    long long calc(string s,int n,int k){ // 4 2 2 4   => 2 2 4 4 
        long long num = stoll(s);
        sort(s.begin(),s.end());
        if(num%k != 0 || vis.count(s))return 0;
        vis.insert(s);
        vector<int>f(10);
        for(char c : s)f[c-'0']++;
        long long ans = (n - f[0]) * fact[n-1];
        for(int i = 0 ; i < 10 ; i++)
            ans/=fact[f[i]];
        return ans;
    }
    long long solve(int i,string s,int n,int k){
        if(i*2 >= n+1){
            return calc(s,n,k);
        }
        long long ret = 0;
        for(int j = 0 ; j < 10;j++){
            if(!i && !j)continue;
            s[i] = s[n-1-i] = j+'0';
            ret+=solve(i+1,s,n,k);
        }
        return ret;
    }
    long long countGoodIntegers(int n, int k) {
        string s = string(n,'#');
        for(int i = 1 ; i < 11 ;i++)
            fact[i] = fact[i-1]*i;

        return solve(0,s,n,k);
    }
};