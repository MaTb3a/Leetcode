class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>in(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i <numCourses ;i++){
            if(!in[i])q.push(i),cnt++;
        }
        while(q.size()){
            int node = q.front();q.pop();
            for(auto ch : adj[node]){
                in[ch]--;
                if(!in[ch]){
                    cnt++;
                    q.push(ch);
                }
                
            }
        }
        return cnt == numCourses;
    }
};