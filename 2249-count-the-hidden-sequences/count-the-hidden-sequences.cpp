class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int l = 0, r = 0, cur = 0;
        for (int d : differences) {
            cur += d;
            l = min(l, cur);
            r = max(r, cur);
            if (r - l > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (r - l) + 1;
    }
};