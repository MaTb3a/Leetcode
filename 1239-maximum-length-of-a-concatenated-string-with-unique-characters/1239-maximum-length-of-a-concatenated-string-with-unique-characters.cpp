class Solution {
public:
    bool check(string &s,vector<bool> &vis){
        for(int i = 0 ;i < s.size();i++){
            if(vis[s[i]-'a'])return false;
            vis[s[i]-'a']=1;
        }
        return true;
    }
   
    int maxLength(vector<string>& arr) {
        int ans = 0 , n = arr.size();
        
        for(int i = 0 ; i < (1<<n); i++){
            bool ok = true;
            vector<bool>vis(26);
            for(int j = 0 ; j < n ;j++){
                if(i & (1<<j)){
                    if(!check(arr[j],vis))ok=false;
                }
            }
            if(ok)ans=max(ans,(int)count(vis.begin(),vis.end(),1));
        }
        return ans;
        
    }
};