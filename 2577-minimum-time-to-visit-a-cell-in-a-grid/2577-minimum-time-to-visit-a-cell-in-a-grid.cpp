class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int minimumTime(vector<vector<int>>& grid) { 
        if(grid[0][1] > 1 && grid[1][0] > 1)return -1;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        // time ,    x.  y
        priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>>>,greater<>>pr;
        pr.push({0,{0,0}});
        while(pr.size()){
            int curTime = pr.top().first;
            int x = pr.top().second.first;
            int y = pr.top().second.second;
            pr.pop();
            if(x == n -1 && y == m -1)return curTime;
            if(vis[x][y])continue;
            vis[x][y] = 1;
            for(int i = 0 ; i < 4;i++){
                int ddx = dx[i]+x;
                int ddy = dy[i]+y;
                if(ddx < 0 || ddy <0 || ddx >=n || ddy >= m)continue;
                int wastedTime = ((grid[ddx][ddy] - curTime)&1) ? 0 : 1;
                int mxTime = max(curTime+1,wastedTime+grid[ddx][ddy]);
                pr.push({mxTime,{ddx,ddy}});

            }

        }
        return -1;

    }
};