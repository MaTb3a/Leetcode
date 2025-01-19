class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size() , m = heightMap[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        priority_queue<pair<int,pair<int,int>>>pr;
        for(int i = 0 ; i < n;i++)
            for(int j = 0 ; j < m ;j++)
                if(i== 0 || j == 0 || i== n-1 || j == m-1)
                    pr.push({-heightMap[i][j],{i,j}}),vis[i][j] = true;
        int ans = 0, level = 0;
        int dir[5] ={-1,0,1,0,-1};
        while(pr.size()){
            auto [x,y] = pr.top().second;
            level = max(level,-pr.top().first);
            pr.pop();
            for(int i = 0 ; i < 4 ;i++){
                int ddx = dir[i] + x;
                int ddy = dir[i+1] + y;
                if(ddx < 0 || ddy < 0 || ddx >=n || ddy >= m || vis[ddx][ddy])continue;
                vis[ddx][ddy] = true;
                pr.push({-heightMap[ddx][ddy],{ddx,ddy}});
                ans+= max(0,level - heightMap[ddx][ddy]);
            }
        }
        return ans;
        
    }
};