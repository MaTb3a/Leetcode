class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(char ch : n){
            mx=max(mx,ch-'0');
            if(mx == 9)return mx; 
        }
        return mx;
    }
};