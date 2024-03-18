class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end());
        int n = 1 , mx = points[0][1];
        for(int i = 1 ; i < points.size();i++){
            if(points[i][0] <= mx) mx=min(mx,points[i][1]);
            else mx = points[i][1],n++;
        }
        return n;
    }
};