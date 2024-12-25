from collections import deque
from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode], dep: int):
        if not root:
            return
        if len(self.ans) == dep:
            self.ans.append(root.val)
        else:
            self.ans[dep] = max(self.ans[dep], root.val)
        self.dfs(root.left, dep + 1)
        self.dfs(root.right, dep + 1)

    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        # Solution #1: BFS
        q = deque([root])
        ans = []
        while q:
            sz = len(q)
            mx = float('-inf')
            for _ in range(sz):
                node = q.popleft()
                mx = max(mx, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(mx)

        # Solution #2: DFS
        self.ans = []
        self.dfs(root, 0)
        return self.ans
