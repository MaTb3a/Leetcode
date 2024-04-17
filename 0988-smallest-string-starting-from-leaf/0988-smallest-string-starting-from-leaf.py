class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.smallest_string = ""
        self.dfs(root, "")
        return self.smallest_string

    def dfs(self, root, current_string):
        if not root:
            return

        current_string = chr(root.val + ord('a')) + current_string

        if not root.left and not root.right:
            if not self.smallest_string or self.smallest_string > current_string:
                self.smallest_string = current_string

        if root.left:
            self.dfs(root.left, current_string)
        
        if root.right:
            self.dfs(root.right, current_string)