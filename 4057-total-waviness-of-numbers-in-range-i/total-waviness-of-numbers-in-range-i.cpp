class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i = max(100,num1); i <=num2;i++){
            string s = to_string(i);
            for(int j = 1 ; j < s.size()-1;j++){
                cnt+=(s[j] > s[j-1] && s[j] > s[j+1]);
                cnt+=(s[j] < s[j-1] && s[j] < s[j+1]);
            }
        }
        return cnt;
    }
};