# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.prev = -1
        self.ans = float("inf")

        def solve(root): # O(n) | Memory O(h)
            if not root:
                return 
            solve(root.left)
            if self.prev != -1 :
                self.ans = min(self.ans,root.val - self.prev)
            self.prev = root.val
            solve(root.right)
            

        solve(root)
        return self.ans

   


        



