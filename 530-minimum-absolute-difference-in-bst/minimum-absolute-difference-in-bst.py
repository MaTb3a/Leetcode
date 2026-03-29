# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.v = []
        def solve(root):
            if not root:
                return
            self.v.append(root.val)
            solve(root.left)
            solve(root.right)
        solve(root)
        self.v.sort()
        ans = 1e9
        for i in range(1,len(self.v)):
            ans = min(ans,self.v[i] - self.v[i-1])
        return ans
