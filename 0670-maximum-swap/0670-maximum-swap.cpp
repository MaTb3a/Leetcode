class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int mx = s.size()-1 , idx1 = -1 , idx2 = -1 ;
        int n = s.size();
        for(int i = n -1 ; ~i ;i--){
            if(s[i]  > s[mx]) mx = i;
            else if(s[i] < s[mx]){
                idx1 = i;
                idx2 = mx;
            }
        }
        if(~idx1)swap(s[idx1],s[idx2]);
        return stoi(s);
    }
};