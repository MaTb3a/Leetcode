class Solution {
public:
    bool solve(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j])i++,j--;
            else return 0;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0 ; i < n;i++)
            for(int j = i ; j < n ;j++)
                cnt+=solve(i,j,s);
        return cnt;
    }
};