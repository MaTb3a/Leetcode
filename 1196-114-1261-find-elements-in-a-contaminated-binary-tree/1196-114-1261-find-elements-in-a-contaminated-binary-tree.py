class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class FindElements:
    def __init__(self, root: TreeNode):
        self.root = root
        self.st = set()
        self.recover(root, 0) 
    def recover(self, node, val):
        if not node:
            return
        node.val = val
        self.st.add(val)
        self.recover(node.left, 2 * val + 1)
        self.recover(node.right, 2 * val + 2)

    def find(self, target: int) -> bool:
        return target in self.st
    