class Solution {
public:
    bool solve(string &s, string &locked,bool forward){
        int cnt = 0 , magic = 0;
        int n =  s.size();
        for(int i = 0 ; i < n ;i++){
            int idx = forward ? i : n - i - 1;
            if(locked[idx]=='0'){
                magic++;
                continue;
            }
            if((s[idx]=='(' && forward) || (s[idx]==')' && !forward) )cnt++;
            else{
                if(cnt)cnt--;
                else if(magic)magic--;
                else return false;
            }            
        }
        return true;
    }
    bool canBeValid(string s, string locked) {
        if(s.size()&1)return 0;
        return solve(s,locked,1) & solve(s,locked,0);


    }
};