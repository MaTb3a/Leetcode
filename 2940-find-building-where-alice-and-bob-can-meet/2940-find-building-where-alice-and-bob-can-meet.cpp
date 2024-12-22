class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<vector<pair<int,int>>>v(n);
        vector<int>ans(m,-1);
        for(int i = 0 ; i < m ;i++){
            int x = queries[i][0],y = queries[i][1];
            if(x > y) swap(x,y);
            if(x == y || heights[x] < heights[y])ans[i] = y;
            else v[y].push_back({max({heights[x],heights[y]}),i});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pr;
        for(int i = 0 ; i < n;i++){
            for(auto it : v[i])pr.push(it);
            while(pr.size() && pr.top().first < heights[i]){
                ans[pr.top().second] = i;
                pr.pop();
            }
        }
        return ans;
    }
};