class Solution {
public:
    int n,m;
    // int bfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& ids,int id,int n,int m){
    //     queue<pair<int,int>>q;
    //     q.push({x,y});
    //     ids[x][y] = id;
    //     int cnt = 1;
    //     vector<int>dir={-1,0,1,0,-1};
    //     while(q.size()){
    //         auto[x,y] = q.front();q.pop();
    //         for(int i = 0 ; i < 4 ;i++){
    //             int dx = dir[i] + x;
    //             int dy = dir[i+1] + y;
    //             if(dx < 0 || dy < 0 || dx >=n || dy >= m || !grid[dx][dy] || ids[dx][dy])continue;
    //             ids[dx][dy] = id;
    //             cnt++;
    //             q.push({dx,dy});
    //         }
    //     }
    //     return cnt;
    // }

    vector<int>dir={-1,0,1,0,-1};
    int dfs(int x,int y,vector<vector<int>>& grid,int id){
        if(x < 0 || y < 0 || x >= n || y >=n || grid[x][y] != 1)return 0;
        grid[x][y] = id;
        int cnt = 1;
        for(int i = 0 ; i < 4 ;i++)
            cnt+=dfs(x+dir[i],y+dir[i+1],grid,id);
        return cnt;
    }
    int check(int x,int y,unordered_map<int,int>&mp,vector<vector<int>>& grid){
        int cnt = 1,vis[4] = {-1,-1,-1,-1};
         for(int i = 0 ; i < 4 ;i++){
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            if(dx < 0 || dy < 0 || dx >= n || dy >=n || find(vis,vis+i,grid[dx][dy]) != vis+i)continue;
            cnt+=mp[grid[dx][dy]];
            vis[i] = grid[dx][dy];
         }
         return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid.size();
        int mx = 0, id = 2;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m ;j++)
                if(grid[i][j] ==1){
                    mp[id] = dfs(i,j,grid,id);
                    mx = max(mx,mp[id++]);
                }
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m ;j++)
                if(!grid[i][j])
                    mx=max(mx,check(i,j,mp,grid));
        return mx;
                

    }
};