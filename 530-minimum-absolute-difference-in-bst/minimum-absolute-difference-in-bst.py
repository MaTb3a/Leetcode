# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.ans = float("inf")
        self.prev = -1
        def solve(root):
            if root:
                solve(root.left)
                if self.prev != -1:
                    self.ans = min(self.ans,abs(root.val-self.prev))
                self.prev = root.val
                solve(root.right)
        solve(root)
        return self.ans
