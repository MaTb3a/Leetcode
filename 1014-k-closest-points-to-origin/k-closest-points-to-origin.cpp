class Solution {
public:
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
            return 1LL*a[0]*a[0] + a[1]*a[1] <  1LL*b[0]*b[0] + b[1]*b[1]; 
        });
        points.erase(points.begin()+k,points.end());
        return points;
    }
};