class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v(n);
        if(n&1)v[n/2] = 0;
        for(int i = 1 ; i <= n/2;i++){
            v[i-1] = -i;
            v[n-i] = i;
        }
        return v;
    }
};