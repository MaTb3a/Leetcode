class Solution {
public:
    int n, m;
    void dfs(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>& ocean){
        if(x<0 || y<0 || x>=n || y>=m )
            return;
        if(!ocean[x][y]){

            ocean[x][y]=1;
            if(x&&heights[x-1][y]>=heights[x][y])dfs(x-1,y,heights,ocean);
            if(y&&heights[x][y-1]>=heights[x][y])dfs(x,y-1,heights,ocean);
            if(x+1<n&&heights[x+1][y]>=heights[x][y])dfs(x+1,y,heights,ocean);
            if(y+1<m&&heights[x][y+1]>=heights[x][y])dfs(x,y+1,heights,ocean);
        }   
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>Atlantic(n,vector<bool>(m,0));
        vector<vector<bool>>Pacific(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((!i || !j) && !Atlantic[i][j])
                     dfs(i,j,heights,Atlantic);
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i==n-1 || j==m-1) && !Pacific[i][j])
                     dfs(i,j,heights,Pacific);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(Atlantic[i][j] && Pacific[i][j])
                    ans.push_back({i,j});
        return ans;
        

    }
};