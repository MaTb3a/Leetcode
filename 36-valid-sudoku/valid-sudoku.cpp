class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short Col[9]={0};
        short Row[9]={0};
        short Block[9]={0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c == '.') continue;
                int x=(c-'0')%9, x2=1<<x, bidx=(i/3)*3+j/3; 
                if ((Row[i]>>x)&1||(Col[j]>>x)&1||(Block[bidx]>>x)&1) return 0;
                Row[i]|=x2, Col[j]|=x2, Block[bidx]|=x2;
            }
        }
        return 1;
    }
};