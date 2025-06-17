# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        if not root:
            return ''
        return str(root.val) + "," + self.serialize(root.left) + self.serialize(root.right)
        

    def add(self,root,key):
        
        if not root:
            return TreeNode(key)
        if key < root.val:
            root.left = self.add(root.left,key)
        else :
            root.right = self.add(root.right,key)
        return root
    
    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        root = None
        lst = [int(x) for x in data.split(',') if x]
        for x in lst:
            root = self.add(root,x)
        return root
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans