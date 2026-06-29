class Solution {
public:
    string convert(string s, int numRows) {
        // i , j 
        // j < n
        // i+1, j -1 & j >= 0
        // j < n 
      //  if(numRows == 1)return s;
        int idx = 0,n = s.size();
        if(numRows == 1)return s;

        vector<string>v(numRows,string(n,' '));
        int i = 0,j = 0;
        while(idx < n){
            while(i < numRows && idx < n)v[i++][j] =s[idx++];
            i = numRows -2;
            if( idx >=n)break;
            while(i >= 0 && idx < n)v[i--][++j] = s[idx++];
            i = 1;
        }
        string ans ="";
        for(int ii = 0 ; ii < v.size();ii++){
            for(int jj = 0 ; jj < v[0].size();jj++)
                if(v[ii][jj]!=' ')ans+=v[ii][jj];
            
        }
        return ans;
    }
};