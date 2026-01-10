# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        parent = {}
        level = [root]
        q = deque([root])
        parent[root] = root
        while q:
            sz = len(q)
            last = []
            for _ in range(sz):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    parent[node.left] = node
                    last.append(node.left)
                if node.right:
                    q.append(node.right)
                    parent[node.right] = node
                    last.append(node.right)
          
            if len(last):
                level = last[::]
    
        while len(set(level)) != 1:
            for i in range(len(level)):
                level[i] = parent[level[i]]
               
        
        return level[0]


            
