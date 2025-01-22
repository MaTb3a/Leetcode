class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() ,  m = isWater[0].size();
        bitset<1024000>vis;
        queue<int>q;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(isWater[i][j])isWater[i][j] = 0,q.push((i<<10)+j),vis[(i<<10)+j] = 1;

        vector<int>dir={-1,0,1,0,-1};
        while(q.size()){
            int idx = q.front(),x = idx>>10, y = idx & ((1<<10)-1);
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int dx = dir[i]+x;
                int dy = dir[i+1]+y;
                if(dx < 0 || dy < 0 || dx >=n || dy >= m || vis[(dx<<10)+dy] )continue;
                vis[(dx<<10)+dy] = 1;
                isWater[dx][dy] = isWater[x][y] +1;
                q.push((dx<<10)+dy);

            }

        }
        return isWater;

    }
};