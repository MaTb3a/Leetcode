class Solution {
public:
    pair<int,int> dp[28][29][29];
    bool vis[28][29][29];
    pair<int,int> solve(int l,int r,int n){
       

        if(dp[l][r][n].first != -1)return dp[l][r][n];
        if(l+r == n+1)return dp[l][r][n] =  {1,1};
        int mn = 1e9,mx = 0;

        for(int mask = 0 ; mask < (1<<(n/2)) ;mask++){
            vector<int>players;
            int new_l = l,new_r = r;

            for(int i = 0 ; i < (n/2) ; i++){
                
                int f = i+1,s = n-i;
                if( (f == l && s == r)  || (s == l && f == r)){
                    mn = min(mn,1);
                    mx = max(mx,1);
                    continue;
                }
                int winner = -1;
                if( f == l || f == r) winner = f;
                else if( s == l || s == r)winner = s;
                else winner = (mask & (1<<i)) ? f : s;
                players.push_back(winner);
            }
            if(n&1)players.push_back((n+1)/2);
            sort(players.begin(),players.end());

            int idxl = -1,idxr = -1;
            for(int i = 0 ; i < players.size();i++){
                if(players[i] == l)idxl = i+1;
                if(players[i] == r)idxr = i+1;
            }
            if(idxl != -1 && idxr != -1){
                pair<int,int>p = solve(idxl,idxr,players.size());
                mn = min(mn,p.first+1);
                mx = max(mx,p.second+1);
            }
        }
        return dp[l][r][n] = {mn,mx};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(dp,-1,sizeof dp);
        pair<int,int> p = solve(firstPlayer,secondPlayer,n);
        return {p.first,p.second};
    }
};