class Solution {
public:
    int BS(int st,int ed,int target,vector<int>& nums){
        if(st > ed)return -1;
        int md = (st+ed)/2;
        if(nums[md] == target)return md;
        if(nums[md] < target)
            return BS(md+1,ed,target,nums);
        else
            return BS(st,md-1,target,nums);
    }
    int search(vector<int>& nums, int target) {
        int k = 0;
        for(int i = 0 ; i < nums.size()-1;i++)
            if(nums[i] > nums[i+1]){
                k = i;break;
            }
        //cout<<k<<"\n";
        return max(BS(0,k,target,nums),BS(k+1,nums.size()-1,target,nums));
       
    }
};