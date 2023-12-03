class Solution {
public:
    inline int dist(int x1,int y1,int x2,int y2){
        return max(abs(x1-x2),abs(y1-y2));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1 ; i < points.size();i++)
            ans+=dist(points[i-1][0],points[i-1][1],points[i][0],points[i][1]);
        return ans;
    }
};