class Solution {
public:
    int solve(int n,long long cur,long long nxt){
        int dif = 0;
        while(cur <= n){
            dif += min((long long)n+1,nxt) - cur;
            cur*=10;nxt*=10;
        }
        return dif;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k){
            int cnt = solve(n,cur,cur+1);
            if(cnt <= k)k-=cnt,cur++;
            else cur*=10,k--;
        }
        return cur;
    }
};