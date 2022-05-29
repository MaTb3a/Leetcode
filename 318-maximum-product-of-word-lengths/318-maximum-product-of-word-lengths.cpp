class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n= words.size();
        vector<int>mask;
        for(int i=0;i<n;i++){
            int cur=0;
            for(auto t : words[i])
                cur |=(1<<(t-'a'));
            mask.push_back(cur);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( (mask[i]&mask[j])==0)
                    ans=max(ans,(int)(words[i].size() * words[j].size()));
            }
        }
        return ans;
        
        
    }
       
        
            
};