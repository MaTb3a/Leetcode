class Solution {
public:
    bool solve(int n, int k){
        if(n==1)return 0;

        int len = (1<<n)-1;
        int md = len / 2 +1;

        if(md == k)return 1;

        else if(k < md) return solve(n-1,k);
        
        else return !solve(n-1,len-k+1);
    }
    char findKthBit(int n, int k) {
        return '0'+solve(n,k);// n => 20
    }
};