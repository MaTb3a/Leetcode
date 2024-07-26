class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>dist(n,vector<int>(n,0x3f3f3f3f));
        
    for(int i = 0 ; i < n ;i++)
            dist[i][i] = 0;
                
    for(int i = 0 ; i < edges.size();i++)
        dist[edges[i][0]][edges[i][1]] = edges[i][2],dist[edges[i][1]][edges[i][0]] = edges[i][2];
        
    for(int k = 0 ; k < n ;k++)
        for(int i = 0 ; i < n; i++)
            for(int j = 0 ; j < n ; j++)
		        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        vector<int>v(n);
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < n ; j++ )
                v[i]+=(distanceThreshold >= dist[i][j]);
        
         
        
        int ans = 0;
        for(int i = 0 ; i < n ;i++)
            if(v[i]==*min_element(v.begin(),v.end()))ans = i;
        return ans;
    }
};