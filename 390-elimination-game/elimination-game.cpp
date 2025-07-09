class Solution {
public:

/*

int f = 1, cnt = 0;
        while (n>1){
            if (!(cnt&1) || n & 1) {
                f += (1 << cnt);
            }
            n /= 2; cnt++;
        }
        return f;
*/
    int lastRemaining(int n) {
        int ans = 1;
        for(int i =0 ; n >1 ;i++){
            if(i%2 == 0 || n&1)ans+=(1<<i);
            n/=2;
        }
        return ans;
    }
};