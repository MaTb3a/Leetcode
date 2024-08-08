class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
         vector<vector<int>> ans;
         ans.push_back({rStart,cStart});
         int dx[4] = {0,1,0,-1};
         int dy[4] = {1,0,-1,0}; 
         int dir = 0,steps = 0;
         while(ans.size() != rows * cols){
            if(!dir || dir == 2)steps++;
            for(int i = 0 ; i < steps ;i++){
                rStart += dx[dir];
                cStart += dy[dir];
                if(rStart >= 0 && rStart < rows  && cStart >=0 && cStart < cols)
                    ans.push_back({rStart,cStart});
            }
            dir++;
            dir%=4;
         }
         return ans;
    }
};