class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        for x,y in prerequisites:
            indegree[x]+=1
            adj[y].append(x)
        
        q = deque( i for i in range(numCourses) if indegree[i] == 0)
        ans = []
        
        while q:
            cur = q.popleft()
            ans.append(cur)
            for ch in adj[cur]:
                indegree[ch]-=1
                if indegree[ch] == 0:
                    q.append(ch)

        return True if len(ans) == numCourses else False