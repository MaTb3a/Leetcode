class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>deg(n);
        for(auto it : favorite)deg[it]++;
        queue<int>q;
        for(int i = 0 ; i < n;i++)
            if(!deg[i])q.push(i);
        vector<int>chain(n,1);

        while(q.size()){
            int x = q.front();q.pop();
            int y = favorite[x];
            chain[y] = max(chain[y],chain[x]+1);
            deg[y]--;
            if(!deg[y])q.push(y);
        }

        int mx = 0, meetings = 0;
        for(int i = 0 ; i < n;i++){
            if(!deg[i])continue;
            int cur = i , len = 0;
            while(deg[cur]){
                len++;
                deg[cur]=0;
                cur = favorite[cur];
            }
            if(len > 2)mx=max(mx,len);
            else meetings+=chain[i] + chain[favorite[i]];
        }
        return max(mx,meetings);


    }
};