class Solution {
public:
    vector<string>v;
    vector<vector<string>>ans;
    int visCol[10];
    int d1[20];
    int d2[20];
    void solve(int r,int n){
        if(r==n){
            ans.push_back(v);
            return;
        }
        for(int c=0;c<n;c++){
            if(!visCol[c] && !d1[r+c] && !d2[r-c+9]){
                visCol[c] = d1[r+c] = d2[r-c+9] = 1;
                string s=string(n,'.'); s[c]='Q';
                v.push_back(s);
                solve(r+1,n);
                visCol[c] = d1[r+c] = d2[r-c+9] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(visCol,0,sizeof visCol);
        memset(d1,0,sizeof d1);
        memset(d2,0,sizeof d2);
        v.clear();
        ans.clear();
        solve(0,n);
        return ans;
    }
};