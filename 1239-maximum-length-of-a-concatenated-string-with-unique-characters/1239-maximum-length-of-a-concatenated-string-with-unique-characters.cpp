class Solution {
public:
    bool check(string &s,int &mask){
        for(int i = 0 ;i < s.size();i++){
            if(mask & (1<<(s[i]-'a')) )return false;
            mask|=(1<<(s[i]-'a'));
        }
        return true;
    }
   
    int maxLength(vector<string>& arr) {
        int ans = 0 , n = arr.size();
        
        for(int i = 0 ; i < (1<<n); i++){
            bool ok = true;
            int mask = 0;
            for(int j = 0 ; j < n ;j++){
                if(i & (1<<j)){
                    if(!check(arr[j],mask))ok=false;
                }
            }
            if(ok)ans=max(ans,(int)__builtin_popcount(mask));
        }
        return ans;
        
    }
};