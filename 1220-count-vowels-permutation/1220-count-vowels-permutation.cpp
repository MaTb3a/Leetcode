class Solution {
public:
    char arr[5] = {'a', 'e', 'i', 'o', 'u'};
    int nn;
    int  mod = 1e9+7;
    long long dp[20005][27];
    long long solve(int idx,char lst){
        if(idx==nn)
            return 1;
        long long &ret=dp[idx][lst-'a'];
        if(~ret)return ret;
        ret=0;
        if((lst)=='a')
              ret+=solve(idx+1,'e');
        if((lst)=='e'){
              ret+=solve(idx+1,'a');
              ret+=solve(idx+1,'i');
        }
        if((lst)=='i'){
            ret+=solve(idx+1,'a');
            ret+=solve(idx+1,'e');
            ret+=solve(idx+1,'o');
            ret+=solve(idx+1,'u');
        }
        if((lst)=='o'){
            ret+=solve(idx+1,'i');
            ret+=solve(idx+1,'u');
        }
        if((lst)=='u'){
            ret+=solve(idx+1,'a');    
        }
           
            
         return ret%mod;
              
    }
    int countVowelPermutation(int n) {
        nn=n;
        long long ans=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<5;i++){
            ans+=solve(1,arr[i])%mod;
        }
        return ans%mod;
    }
};