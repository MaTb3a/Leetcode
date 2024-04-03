class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    int n,m;
    bool vis[16][16]={0};
    bool solve(int x,int y,int idx,string &s,vector<vector<char>>& board){
        if(idx==s.size())return true;
        bool ret = false;
        vis[x][y] = 1;
        for(int i = 0 ; i < 4 ;i++){
            int ddx = dx[i] + x;
            int ddy = dy[i] + y;
            if(ddx >= 0 && ddy >= 0 && ddx < n && ddy < m && !vis[ddx][ddy] && board[ddx][ddy] == s[idx]){
                ret|=solve(ddx,ddy,idx+1,s,board);
            }
        }
        vis[x][y]=0;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();
        for(int i = 0 ; i < n;i++)
            for(int j = 0 ; j < m ; j++)
                if(board[i][j] == word[0])
                    if(solve(i,j,1,word,board))return true;
        return false;
    }
};