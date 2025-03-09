class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(),cnt = 1,ans = 0;
        for(int i = 1; i < n+k-1;i++){
            cnt = (colors[i>=n ? i-n : i] ^ colors[(i-1)>= n ? (i-1)-n : (i-1)]) ? cnt+1 : 1;
            ans+=(cnt>=k);
        }
        return ans;
    }
};