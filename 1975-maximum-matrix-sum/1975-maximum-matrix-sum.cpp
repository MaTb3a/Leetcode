class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mn = 1e9,cnt = 0;
        for(auto row : matrix){
            for(auto x : row){
                sum+=abs(x);
                mn = min(mn,abs(x));
                cnt+=(x<0);
            }
        }
        return sum - (cnt&1 ? 2*mn : 0);
    }
};