from collections import deque

class Solution:
    def minimumOperations(self, root):
        q = deque([root])
        swp = 0
        
        while q:
            n = len(q)
            v = []
            
            for _ in range(n):
                cur = q.popleft()
                v.append(cur.val)
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
            
            sorted_v = sorted(v)
            idx_map = {val: i for i, val in enumerate(v)}
            
            for i in range(n):
                if v[i] != sorted_v[i]:
                    idx = idx_map[sorted_v[i]]
                    idx_map[v[i]] = idx
                    v[i], v[idx] = v[idx], v[i]
                    swp += 1
        
        return swp
