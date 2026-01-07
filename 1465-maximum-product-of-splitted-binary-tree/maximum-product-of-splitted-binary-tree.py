# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    total_sum = 0
    def dfs(self,root):
            if not root:
                return 
            self.total_sum+=root.val
            if root.left:
                self.dfs(root.left)
                root.val+=root.left.val
            if root.right:
                self.dfs(root.right)
                root.val+=root.right.val
    def solve(self,root):
        if not root:
            return 0
        ret = 0
        ret = max(ret,(self.total_sum-root.val)*root.val)
        if root.left:
            ret = max(ret,self.solve(root.left))
        if root.right:
            ret = max(ret,self.solve(root.right))
        return ret
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        
        
            
        self.dfs(root)
        return self.solve(root)%1000000007
        
            