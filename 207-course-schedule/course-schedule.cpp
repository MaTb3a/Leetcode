class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        queue<int>q;
        for(int i = 0 ; i < numCourses;i++)
            if(!indegree[i])q.push(i);
        
        while(q.size()){
            int x = q.front();q.pop();
            for(auto ch : adj[x]){
                indegree[ch]--;
                if(!indegree[ch])
                    q.push(ch);
            }
        }
        return accumulate(indegree.begin(),indegree.end(),0) == 0;
       
    }
};