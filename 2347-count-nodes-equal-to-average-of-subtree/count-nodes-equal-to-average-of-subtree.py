# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.ans = 0
        def solve(root):
            if not root:
                return [0,0]
            l = solve(root.left) 
            r = solve(root.right)
            s = root.val + l[0] + r[0]
            cnt = 1 + l[1] + r[1]
            if s // cnt == root.val:
                self.ans+=1
            return [s,cnt]

        solve(root)
        return self.ans
            
            