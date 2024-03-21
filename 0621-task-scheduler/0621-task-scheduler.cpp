class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vis(26);
        for(auto t : tasks)vis[t-'A']++;
        priority_queue<int>pr;
        for(auto t : vis)if(t)pr.push(t);
        
        int ans = 0;
        while(pr.size()){
            int cycle = n+1;
            int cnt = 0;
            vector<int>store;
            while(cycle-- && pr.size()){
                if(pr.top()>1)store.push_back(pr.top()-1);
                pr.pop();
                cnt++;
            }
            for(auto t : store)pr.push(t);
            ans+=(pr.empty() ? cnt : n+1);
        }
        return ans;
    }
};