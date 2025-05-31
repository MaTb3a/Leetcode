class Solution {
public:
    
   

    int snakesAndLadders(vector<vector<int>>& board) {
       int n = board.size();
        
        vector<pair<int,int>>cells(n*n+1);
        vector<int>column(n),dist(n*n+1,-1);
        iota(column.begin(),column.end(),0);
        
        int cnt = 1;
        for(int i = n-1 ;i >= 0 ;i--){
            for(int col : column)
                cells[cnt++] = {i,col};
            
            reverse(column.begin(),column.end());
        }
        dist[1]=0;
        queue<int>q;
        q.push(1);
        while(q.size()){
            auto cur = q.front();q.pop();
            for(int i=cur+1;i<=min(cur+6,n*n);i++){
                auto [row,col] = cells[i];
                int nxt = board[row][col] == -1 ? i : board[row][col];
                if(dist[nxt]==-1){
                    dist[nxt] = dist[cur]+1;
                    q.push(nxt);
                }
            }
        }
        return dist[n*n];
        
    }
};