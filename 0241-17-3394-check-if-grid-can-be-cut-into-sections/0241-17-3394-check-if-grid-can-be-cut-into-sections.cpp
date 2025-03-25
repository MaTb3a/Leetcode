class Solution {
public:
    bool check(vector<vector<int>>& v,int d){
        sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
            return a[d] < b[d];
        });
        int cnt = 0 , mx = v[0][d+2];
        for(int i = 1 ; i < v.size();i++){
            cnt+=(mx <= v[i][d]);
            mx = max(mx,v[i][d+2]);
        }
        return cnt >=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles,0) || check(rectangles,1);
    }
};