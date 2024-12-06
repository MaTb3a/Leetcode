class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0;
        bitset<10001>vis;
        for(auto it : banned)vis[it] = 1;
        for(int i = 1 ; i <= n ;i++)// n
            if(!vis[i] && i <= maxSum)cnt++,maxSum-=i;
        return cnt;
        
    }
};