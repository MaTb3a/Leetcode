class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(auto it : n)mx=max(mx,it-'0');
        return mx;
        
    }
};