class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];
    }
    static int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);

        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=P[i][1];
            for(int j = i+1; j<n; j++){
                const int yj=P[j][1];
                if (yj>=yi && y>yj){
                    ans++;
                    y=yj;
                }
            }
        }
        return ans;
    }

};