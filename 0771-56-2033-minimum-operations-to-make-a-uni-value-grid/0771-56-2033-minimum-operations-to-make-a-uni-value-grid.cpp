class Solution {
public:
    int frq[10001];
    int minOperations(vector<vector<int>>& grid, int x) {
        int mod = grid[0][0]%x, sz = grid.size() * grid[0].size();
        for(auto it : grid)
            for(auto val : it){
                if(val%x != mod)return -1;
                frq[val]++;
            }

        int md ,ans = 0;
        for(int i = 1 ; i < 10001 ;i++){
            ans+=frq[i];
            if(2*ans>=sz){
                md = i;break;
            }
        }
        ans = 0;
        for(int i = 1 ; i < 10001 ;i++)
            ans+= abs(i-md) * frq[i]; 
        
        return ans/x;

    }
};