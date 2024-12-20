class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, l: TreeNode, r: TreeNode, level: int):
        if not l or not r:
            return
        if level % 2 == 1:
            l.val, r.val = r.val, l.val
        self.solve(l.left, r.right, level + 1)
        self.solve(l.right, r.left, level + 1)

    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        self.solve(root.left, root.right, 1)
        return root
