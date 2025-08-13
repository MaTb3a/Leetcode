class Solution {
public:
    bool isPowerOfThree(int n) {

        int st = 0,ed = 20,cur=-1,md;
        while(st<=ed){
            md = (st+ed)/2;
            cout<<md<<"\n";
            if(pow(3,md) <= n){
                cur = md;
                st = md+1;
            }
            else ed = md -1;
        }
        return cur!= -1 && pow(3,cur) == n;
    }
};