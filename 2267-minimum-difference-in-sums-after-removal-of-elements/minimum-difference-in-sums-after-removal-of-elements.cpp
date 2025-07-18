class Solution {
public:
  
    
    long long minimumDifference(vector<int>& nums) {
       
        int sz = nums.size(), n = sz / 3;
        vector<long long> l(sz),r(sz);
        long long ans = 1e18;
        priority_queue<int> prL, prR;
        long long suml = 0, sumr = 0;
        for (int i = 0,j = sz - 1 ; i < sz; i++,j--) {
            suml += nums[i];
            sumr += nums[j];
            prL.push(nums[i]);
            prR.push(-nums[j]);

            if (prL.size() > n) {
                suml -= prL.top();
                prL.pop();
                sumr -= -prR.top();
                prR.pop();
            }
            l[i] = suml;
            r[j] = sumr;
        }
     
        for (int i = n; i <= sz - n; i++) {
            ans = min(ans, l[i - 1] - r[i]);
        }
        return ans;
    }
};