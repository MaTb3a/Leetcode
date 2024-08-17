class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<long long>old(m);
        for(int j = 0 ; j < m ; j++)
            old[j] = points[0][j];

        for(int i = 1 ; i < n ; i++){
              vector<long long>l(m),r(m);
              l[0] = old[0];
              r[m-1] = old[m-1];

            for(int j = 1 ; j < m ;j++)
                l[j] = max(old[j],l[j-1]-1);
            
            for(int j = m-2; j >= 0 ; j--)
                r[j] = max(old[j],r[j+1]-1);

            for(int j = 0 ; j < m ;j++)
                old[j] = max(l[j],r[j]) + points[i][j];

        }
        return *max_element(old.begin(),old.end());

    }
};