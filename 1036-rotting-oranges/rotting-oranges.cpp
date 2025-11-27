class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size(),m = grid[0].size(),fresh = 0;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 2)q.push({i,j});
                if(grid[i][j] == 1)fresh++;
            }
        }
        int minutes = 0;
        vector<int>dir = {-1,0,1,0,-1};
        while(q.size() && fresh){
            minutes++;
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(int i =0 ; i < 4;i++){
                    int dx = dir[i]+x;
                    int dy = dir[i+1]+y;
                    if(dx >=0 && dy >= 0 && dx < n && dy <m && grid[dx][dy] == 1){
                        q.push({dx,dy});
                        fresh--;
                        grid[dx][dy] = 2;
                    }
                }
            }
        }
        
        return fresh ? -1 : minutes;
    }
};