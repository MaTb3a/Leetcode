class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n= words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>tmp(26);
            for(auto ch : words[i])tmp[ch-'a']++;
            for(int j=i+1;j<n;j++){
                bool ok=1;
                for(auto t : words[j])
                    if(tmp[t-'a']){ok=0;break;}
                
                 if(ok)ans=max(ans,(int)(words[i].size()*words[j].size()));
                   
            }
        }
        return ans;

    }
       
        
            
};