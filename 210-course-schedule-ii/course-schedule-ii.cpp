class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses;i++)
            if(inDegree[i] == 0)
                q.push(i);
        
        vector<int>ans,empty;

        while(q.size()){
            int x = q.front();q.pop();
            ans.push_back(x);
            for(int ch : adj[x]){
                inDegree[ch]--;
                if(!inDegree[ch]){
                    q.push(ch);
                }
            }
        }
        
        return (ans.size() != numCourses ? empty : ans);
    }
};