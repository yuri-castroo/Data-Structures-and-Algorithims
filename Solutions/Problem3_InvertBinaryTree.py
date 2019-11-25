# Definition for a binary tree node.
class Node(object):
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None

def invertTree(self, root):
    # if we have reached a leaf, return none
    if root == None:
        return None

    # Otherwise, swap and invert the children's subtrees
    temp = root.left
    root.left = self.invertTree(root.right)
    root.right = self.invertTree(temp)

    # Return inverted subtree
    return root
