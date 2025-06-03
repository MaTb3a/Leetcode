class Solution:

    def dfs(self,u,adj,cur_list,vis,reverse_dic):
        vis[u] = 1
        for v in adj[u]:
            if vis[v] == 0:
                self.dfs(v,adj,cur_list,vis,reverse_dic)
        
        cur_list.append(reverse_dic[u])
    
    def topo_logical_sort(self,adj,n,reverse_dic,owner):
        vis = [0]*n
        ans = []
        for i in range(n):
            if vis[i] == 0:
                cur_list = []
                self.dfs(i,adj,cur_list,vis,reverse_dic)
                cur_list.sort()
                cur_list.insert(0,owner[cur_list[0]])
                ans.append(cur_list)

        return ans
        
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        dic = {}
        reverse_dic = {}
        owner= {}
        n = len(accounts)
        idx = 0
        for i in range(n):
            for j in range(1,len(accounts[i])):
                if accounts[i][j] not in dic:
                    owner[accounts[i][j]] = accounts[i][0]
                    dic[accounts[i][j]] = idx
                    reverse_dic[idx] = accounts[i][j]
                    idx+=1

        adj = [[] for _ in range(idx)]

        for i in range(n):
            for j in range(2,len(accounts[i])):
                x = dic[accounts[i][j]]
                y = dic[accounts[i][j-1]]
                adj[x].append(y)
                adj[y].append(x)

        
        return self.topo_logical_sort(adj,idx,reverse_dic,owner)
               
                
        
      