class Solution {
public:
    vector<int> calc_pre(string &s,char z){
        int n = s.size();
        vector<int>pre(n+1);
        for(int  i = 0 ; i < n;i++){
            pre[i+1]+=(z == s[i]) + pre[i];
        }
        return pre;
    }

    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        for(char x = '0' ; x <  '5';x++){
            for (char y = '0'; y < '5' ; y++){

                if(x == y)continue;
                
                vector<int>pre1 = calc_pre(s,x);
                vector<int>pre2 = calc_pre(s,y);
                int matrix[2][2];

                memset(matrix,-0x3f3f3f3f, sizeof matrix);
                int l = 0;
                
                for(int r = k ; r <= n;r++){
                    
                    while(r-l >= k && pre1[r] > pre1[l] && pre2[r] > pre2[l]){
                        int a = pre1[l]%2;
                        int b = pre2[l]%2;
                        matrix[a][b] = max(matrix[a][b],pre2[l] - pre1[l]);
                        l++;
                    }
                     int a = pre1[r]%2;
                     int b = pre2[r]%2;
                     int cur = matrix[a^1][b];
                     if(cur!= -0x3f3f3f3f)
                        ans=max(ans, pre1[r] - pre2[r] + cur);

                }

            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};