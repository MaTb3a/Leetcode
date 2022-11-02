class Solution {
public:
    bool isOK(string a,string b){
        int cnt=0;
        for(int i=0;i<8;i++){
            cnt+=a[i]!=b[i];
        }
        return cnt==1;
    }
    unordered_map<string,vector<string>>g;
    
    int BFS(string start,string end){
        int ans=1;
        queue<string>q;
        q.push(start);
        while(q.size()){
            int cnt=q.size();
            while(cnt--){
                string cur=q.front();q.pop();
                for(auto child : g[cur]){
                    if(isOK(cur,child)){
                        if(child==end)return ans;
                        q.push(child);
                    }
                }
            }
             ans++;
        }
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;

        for(auto t : bank){
            if(isOK(start,t))
                g[start].push_back(t);
        }
        for(int i=0;i<bank.size();i++){
            for(int j=i+1;j<bank.size();j++){
                if(isOK(bank[i],bank[j]))
                    g[bank[i]].push_back(bank[j]);
            }
        }
        return BFS(start,end);
    }
};