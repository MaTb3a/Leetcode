# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def solve(root):
            if not root:
                return 0
            left = solve(root.left)
            right = solve(root.right)
            self.ans += abs(left) + abs(right)
            return root.val + left+right - 1
        self.ans = 0
        solve(root)
        return self.ans