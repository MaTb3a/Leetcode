class Solution {
public:
    int flip(int x){
        if(x == 0 || x == 1 || x == 8)
            return x;
        else if(x == 2)
            return 5;
        else if(x== 5)
            return 2;
        else if(x== 9)
            return 6;
        else if(x== 6)
            return 9;
        else 
            return -1;
    }
    bool rotate(int x){
        string s = to_string(x);
        string d = "";
        for(int i = 0 ; i < s.size();i++){
            if(flip(s[i]-'0') == -1)
                return false;
            d+=to_string(flip(s[i]-'0'));
        }
        return d != s;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1 ; i <= n;i++){
            cnt+=rotate(i);
        }
        return cnt;
    }
};