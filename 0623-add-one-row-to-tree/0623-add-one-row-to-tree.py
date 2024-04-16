# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root,level,val,depth):
        if not root:
            return 
        if level == depth-1:
            L = root.left
            R = root.right
            root.left = TreeNode(val,L,None)
            root.right = TreeNode(val,None,R)
        self.dfs(root.left,level+1,val,depth)
        self.dfs(root.right,level+1,val,depth)
        
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth ==1:
            return TreeNode(val,root,None)
        self.dfs(root,1,val,depth)
        return root