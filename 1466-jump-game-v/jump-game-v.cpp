class Solution {
public:
    vector<int>dp;
    void solve(int i,int d,vector<int>& arr){
        if(~dp[i])return;
        dp[i] = 1;
        for(int j = i -1 ; j >=0 && i - j <= d && arr[i] > arr[j] ; j--){
            solve(j,d,arr);
            dp[i] = max(dp[i],dp[j]+1);
        }
        for(int j = i+1 ; j < arr.size() && j - i <=d && arr[i] > arr[j];j++){
            solve(j,d,arr);
            dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp = vector<int>(n,-1);
        for(int i = 0 ;  i< n ;i++)
            solve(i,d,arr);
        return *max_element(dp.begin(),dp.end());
        
    }
};