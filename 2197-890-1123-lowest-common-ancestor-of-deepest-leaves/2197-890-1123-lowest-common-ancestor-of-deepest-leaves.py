# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def mxdepth(root):
            if not root:
                return 0
            return max(mxdepth(root.left),mxdepth(root.right))+1
        def dfs(root,d,mxd):
            if not root:
                return None
            if d == mxd:
                return root
            l = dfs(root.left,d+1,mxd)
            r = dfs(root.right,d+1,mxd)
            if l and r:
                return root
            return l if l else r
        return dfs(root,1,mxdepth(root))