class Solution {
public:
    int countOnes(int x){
        int cnt = 0;
        while(x){
            cnt+=(x&1);
            x>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int x,int y){
            int cx = countOnes(x);
            int cy = countOnes(y);
            if(cx != cy)
                return cx < cy;
            return x < y;
        });
        return arr;
    }
};