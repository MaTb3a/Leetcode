# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def solve(l,r):
            if l > r:
                return None
            md = (l+r)//2
            node = TreeNode(nums[md])
            L = solve(l,md-1)
            R = solve(md+1,r)
            node.left = L
            node.right = R
            return node
        return solve(0,len(nums)-1)