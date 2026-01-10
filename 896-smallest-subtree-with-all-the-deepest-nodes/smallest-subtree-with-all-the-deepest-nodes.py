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
        while q:
            sz = len(q)
            last = []
            for _ in range(sz):
                node = q.popleft()
                last.append(node)
                if node.left:
                    q.append(node.left)
                    parent[node.left] = node
                if node.right:
                    q.append(node.right)
                    parent[node.right] = node
          
            if len(last):
                level = last[::]

        level = set(level)
        while len(level) > 1:
            level = {parent[node] for node in level}
       
               
        
        return level.pop()


            
