# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root:[TreeNode],num):
        if not root:
            return 0
        if not root.left and not root.right:
            return num*10+root.val        
        return self.dfs(root.left,num*10+root.val) + self.dfs(root.right,num*10+root.val)
        
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root,0)