class Solution {
public:
    bool ok(vector<int>& nums, int md,int p){
        int i = 0,cnt=0;
        while(i<nums.size()-1){
            if(nums[i+1] - nums[i] <= md){
                cnt++;
                i+=2;
            }
            else i++;
        }
        cout<<md<<" "<<cnt<<" "<<p<<endl;
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int st = 0 , ed = 1e9 , cur = -1 , md;
        while(st<=ed){
            md = (st + ed)/2;
            if(ok(nums,md,p)){ed=md-1;cur=md;}
            else st =md+1;
        }
        return cur;

    }
};