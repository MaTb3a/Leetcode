class Solution {
public:
    long long dp[16][2];
    long long solve(int i,bool tight,string num,int &limit, string &s){
        if(i == num.size())return 1;
        long long &ret = dp[i][tight];
        if(~ret)return ret;
        ret =0;
        int mxDigit = tight ? num[i] - '0' : limit;

        if(i >= num.size() - s.size()){
            int d = s[i - (num.size() - s.size())] - '0'; // 9
            if(d <= mxDigit)ret+=solve(i+1, tight && (d == mxDigit) , num,limit,s);//5
        }
        else 
            for(int d = 0 ; d <= min(limit,mxDigit);d++) // 4
                ret+=solve(i+1, tight && (d == mxDigit) , num,limit,s);
        return ret;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        memset(dp,-1,sizeof dp);
        long long ed = finish >= stoll(s) ? solve(0,1,to_string(finish),limit,s) : 0 ;
        memset(dp,-1,sizeof dp);
        long long st = start-1 >= stoll(s) ? solve(0,1,to_string(start-1),limit,s) : 0;
        return ed - st;

    }
};