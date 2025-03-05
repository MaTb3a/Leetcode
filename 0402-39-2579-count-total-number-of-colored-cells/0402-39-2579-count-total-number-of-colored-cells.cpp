class Solution {
public:
    long long coloredCells(int n) { 
        return 1 + 2LL * (n-1) *n ;
    }
};