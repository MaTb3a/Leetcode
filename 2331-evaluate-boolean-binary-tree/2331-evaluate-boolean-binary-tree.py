# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if not root.left and not root.right:
            return root.val != 0

        l = self.evaluateTree(root.left)
        r = self.evaluateTree(root.right)
        if root.val == 2:
            ans = l or r
        else:
            ans = l and r

        return ans