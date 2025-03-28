class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size() , m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>>pr;
        vector<pair<int,int>>QIdx;
        for(int i = 0 ; i < queries.size();i++)QIdx.push_back({queries[i],i});
        sort(QIdx.begin(), QIdx.end());

        int cnt = 0;
        vector<int>ans(queries.size());
        vector<int>dir={1,0,-1,0,1};
        pr.push({-grid[0][0], {0,0}});
        grid[0][0] = 0;
        for(auto [q,idx] : QIdx){
            while(pr.size() && -pr.top().first < q){
                auto [x,y] = pr.top().second;
                pr.pop();
                cnt++;
                for(int i = 0 ; i < 4 ;i++){
                    int dx =x+dir[i], dy = y+dir[i+1];
                    if(dx < 0 || dy < 0 || dx >=n || dy >=m || !grid[dx][dy] )continue;
                    pr.push({-grid[dx][dy],{dx,dy}});
                    grid[dx][dy] = 0;
                }
            }
            ans[idx] = cnt;
        }

        return ans;
    }   
};