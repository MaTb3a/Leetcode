class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(auto t : nums)mp[t]++;
        int mx=0,cnt=0,lst=-2e9;
        for(auto t : mp ){
            if(t.first-lst==1)cnt++;
            else cnt=1;
            lst=t.first;
            mx=max(mx,cnt);
        }
        return mx;
    }
};