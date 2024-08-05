class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int> >>pr;
        for(int i = 0 ; i < n ;i++)
            pr.push({nums[i],i});
        int ans = 0 , mod = 1e9+7;
        for(int i = 1 ; i <= right ; i++){
            pair<int,int>cur = pr.top();
            pr.pop();
            if( i >= left)
                ans = (ans+cur.first)%mod;
            if(cur.second +1 < n){
                cur.first += nums[cur.second+1];
                cur.second++;
                pr.push(cur);
            }
        }
        return ans;
    }
};