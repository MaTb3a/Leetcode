class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, oddEven = 0, evenOdd = 0;
        for(int i = 0 ; i < nums.size();i++){
            odd+=(nums[i]&1);
            even+=!(nums[i]&1);
            if(i){
                oddEven+= ((nums[i-1]&1) && !(nums[i]&1));
                evenOdd+= (!(nums[i-1]&1) && (nums[i]&1));
            }
        }
        return max({odd,even,oddEven*2,evenOdd*2,oddEven+evenOdd+1});
    }
    // 1,5,9,4,2 
    // 1 1 1 0 0

    //1,3
    // 1 1

    // 1,2,1,1,2,1,2
    // 1 0 1 1 0 1 0

    // 1,2,3,4
    // 1 0 1 0

    // odd, even , oddeven, even odd

};