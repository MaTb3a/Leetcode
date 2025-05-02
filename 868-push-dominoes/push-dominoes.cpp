class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>L(n),R(n);
        string ans(n,'.');
        int dist=1e9;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R')dist=0;
            else if (dominoes[i]=='L')dist=1e9;
            else {
                if(dist!=1e9)dist++;
            }
            R[i]=dist;
        }
        dist=1e9;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L')dist=0;
            else if (dominoes[i]=='R')dist=1e9;
            else {
                if(dist!=1e9)dist++;
            }
            L[i]=dist;
        }
        for(int i=0;i<n;i++){
           if(L[i]<R[i])ans[i]='L';
            else if(R[i]<L[i])ans[i]='R';
            else ans[i]='.';
        }

        
    return ans;
    }
};