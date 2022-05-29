class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>>v;
        for(auto t : words){
            vector<int>tmp(26);
            for(auto ch : t)tmp[ch-'a']++;
            v.push_back(tmp);
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                bool ok =1;
                int a=0,b=0;
                for(int k=0;k<26;k++){
                    if(v[i][k] && v[j][k]){ok=0;break;}
                    a+=v[i][k];
                    b+=v[j][k];
                }
                if(ok)ans=max(ans,a*b);
                
            }
        }
        return ans;
        
    }
};