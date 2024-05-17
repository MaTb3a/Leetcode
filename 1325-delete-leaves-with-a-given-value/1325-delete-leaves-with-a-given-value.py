# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def solve(root,target):
            if not root:
                return
            solve(root.left,target)
            
            solve(root.right,target)
            
            if root.left and root.left.val == target and not root.left.left and not root.left.right:
                root.left = None
            if root.right and root.right.val == target and not root.right.left and not root.right.right:
                root.right = None
        solve(root,target)
        if root and root.val == target and not root.left and not root.right:
            root = None
        return root