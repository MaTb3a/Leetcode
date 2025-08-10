class Solution {
public:
    bool ok(int x,int n){
        vector<int>vis(10);
        while(x){
            vis[x%10]++;
            x/=10;
        }
        while(n){
            vis[n%10]--;
            n/=10;
        }
        for(int i = 0 ; i< 10;i++)if(vis[i])return false;
        return true;
    }
    bool reorderedPowerOf2(int n) {
       // 1 2 4 8 16 32 64 128 256
       for(int i = 0 ; i < 30 ;i++){
        if(ok(1<<i,n))return true;
       }
       return false;
    }
};