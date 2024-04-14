# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        if not root:
            return 0;
        sum = 0
        if root.left and not root.left.left and not root.left.right:
            sum+=root.left.val
        sum+=self.dfs(root.left)+self.dfs(root.right)
        return sum
        
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)