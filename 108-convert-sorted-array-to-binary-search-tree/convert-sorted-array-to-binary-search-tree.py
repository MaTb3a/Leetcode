# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        #.       0
        #     -3     5 
        # -10,.      ,,9

        def solve(l,r):
            # base case 
            if l > r:
                return None
            md = (l+r)//2
            L = solve(l,md-1)
            R = solve(md+1,r)
            root = TreeNode(nums[md],L,R)
            return root
        return solve(0,len(nums)-1)
