class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int x,int y){
            int cx = __builtin_popcount(x);
            int cy = __builtin_popcount(y);
            if(cx != cy)
                return cx < cy;
            return x < y;
        });
        return arr;
    }
};