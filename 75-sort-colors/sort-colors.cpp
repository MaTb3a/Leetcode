class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = count(nums.begin(),nums.end(),0);
        int one = count(nums.begin(),nums.end(),1);
        int two = count(nums.begin(),nums.end(),2);
        cout<<zero<<" "<<one<<" "<<two<<"\n";
        for(int i = 0 ;  i < nums.size();i++){
            if(zero)nums[i] = 0,zero--;
            else if(one)nums[i]=1,one--;
            else nums[i] = 2,two--;
        }

    }
};