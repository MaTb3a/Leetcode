class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char ch : s){
            int x = ch-'a'+1; 
            sum += x/10 + x%10;
        }
        k--;
        int ans =0;
        while(k--){
            ans = 0;
            while(sum)
                ans+=sum%10,sum/=10;
            sum = ans;
        }
        return sum;
    }
};