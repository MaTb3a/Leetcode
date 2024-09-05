class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s = accumulate(rolls.begin(),rolls.end(),0);
        int sz = rolls.size()+n;
        int missSum = sz*mean - s;
        if(missSum > 6*n || missSum < n)return {}; // corner cases 
        auto [q,r] = div(missSum,n);
        vector<int>v(n,q);
        fill(v.begin(),v.begin()+r,q+1);
        return v;
    }
};