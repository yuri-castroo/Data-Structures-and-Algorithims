# Generic binary tree node object
class Node(object):
    def __init__(self, left, right):
        self.left = left
        self.right = right

# Compute the maximum depth of the tree 
def maximumDepth(node):
    if not node:
        # if we have reached a leaf, return 0
        return 0
    else:
        # Add 1 to the maximum depth of both children's subtrees
        return 1 + max(maximumDepth(node.left), maximumDepth(node.right))

def minimumDepth(node):
    if not node:
        # if we have reached a leaf, return 0
        return 0
    else:
        # Add 1 to the minimum depth of both children's subtrees
        return 1 + min(minimumDepth(node.left), minimumDepth(node.right))

# Return the differenceo of the maximum and minimum depths in a tree
def maximumDepthDifference(root):
    return maximumDepth(root) - minimumDepth(root)

