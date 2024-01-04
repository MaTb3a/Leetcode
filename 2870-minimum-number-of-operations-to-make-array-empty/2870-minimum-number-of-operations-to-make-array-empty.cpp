class Solution {
public:
    int vis[1000001];
    int minOperations(vector<int>& nums) {
        
        for(auto t: nums)vis[t]++;
        int cnt=0;
        for(int i = 1;i<1000001;i++)
            if(vis[i]==1)return -1;
            else cnt+=ceil(vis[i]/3.0);
        return cnt;
    }
};