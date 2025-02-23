class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> TreeNode:
        stk = []
        root = TreeNode(preorder[0])
        stk.append(root)
        i, j = 1, 0
        
        while stk:
            cur = stk[-1]
            if cur.val == postorder[j]:
                stk.pop()
                j += 1
                continue
            node = TreeNode(preorder[i])
            if not cur.left:
                cur.left = node
            else:
                cur.right = node
            stk.append(node)
            i += 1
        return root
