class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 1 ; i < num.size()-1;i++)
            if(num[i] == num[i-1] && num[i] == num[i+1]){
                ans= max(ans,string(3,num[i]));
            }
        return ans;
    }
};