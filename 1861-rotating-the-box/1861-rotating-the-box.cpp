class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(); // row
        int m = box[0].size(); // col

        vector<vector<char>>v(m,vector<char>(n,'.'));
        // rotate
        for(int i = 0 ; i < n ;i++){
            int lst = m -1;
            for(int j = m -1 ; j >= 0 ;j--){
                //v[j][n-i-1] = box[i][j];
                if(box[i][j] == '*')lst = j - 1, v[j][n-i-1] = box[i][j];
                if(box[i][j] == '#'){
                    v[lst][n-i-1] = box[i][j];
                    lst--;
                }
            }
        }

        return v;

    }
};