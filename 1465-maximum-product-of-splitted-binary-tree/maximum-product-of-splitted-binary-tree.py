# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    total_sum = 0
    ans = 0
    def dfs(self,root):
            if not root:
                return 0
            subSum = root.val + self.dfs(root.left) + self.dfs(root.right)
            self.ans = max(self.ans,(self.total_sum - subSum) * subSum)
            return subSum
  
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        
        
        self.total_sum = self.dfs(root)
        self.dfs(root)
        return self.ans%1000000007
        
            