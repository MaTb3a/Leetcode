class Solution {
public:
    

    int maxProduct(vector<string>& words) {
        int n = words.size();
        int mx = 0;
        vector<vector<int>>v;
        
        for(int i = 0 ;i < n ;i++){
            vector<int>vis(26,0);
            string s = words[i];
            for(int j = 0 ; j < s.size();j++){
                char ch = s[j];
                vis[ch-'a']=1;         
            }
            v.push_back(vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool ok = 1;
                for(int k=0;k<26;k++){
                    if(v[i][k]==1 && v[j][k]==1 )ok=0;
                }
                if(ok){
                    mx=max(mx,(int)(words[i].size() * words[j].size() ));
                }
            }
        }
        return mx;
    }
       
        
            
};