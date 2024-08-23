class Solution {
public:
    string fractionAddition(string s) {
        int num = 0,den = 1;
        int n = s.size(), i = 0;
        while(i < n){
            int sign  = 1; // +;
            if(s[i] == '+' || s[i]=='-'){
                if(s[i]=='-')sign = -1;
                i++;
            }
            int x =0;
            while(i < n && isdigit(s[i]))
                x = x * 10 + (s[i++]-'0');
            
            i++;
            int y = 0;
            while(i < n && isdigit(s[i]))
                y = y * 10 + (s[i++]-'0');

            x*=sign;
            num = num * y + x * den;
            den*=y;
        }


        int g = gcd(num,den);
        return to_string(num/g) + "/" + to_string(den/g);
    }
};