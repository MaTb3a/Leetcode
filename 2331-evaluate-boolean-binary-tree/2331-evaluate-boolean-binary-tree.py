# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        # 0 false
        # 1 true
        # 2 OR
        # 3 AND
        def solve(root):
            #base case
            if root.val == 0 or root.val == 1:
                return root.val
            if root.val == 2:
                return solve(root.left) or solve(root.right)
            if root.val == 3:
                return solve(root.left) and solve(root.right)
            return root
        return solve(root)