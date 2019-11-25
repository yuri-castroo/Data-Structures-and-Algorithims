# Generic tree node class
class Node:
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data 
        self.children = []
 
# Print the ancestors of a target node
def printAncestors(root, target):
    # If we have reached a leaf that is not the target, return false
    if not root:
        return False
     
    # If we have found the target, return true
    if root.data == target:
        return True
 
    # If the target is located in the childrens subtree
    for child in root.children:
        if printAncestors(child, target):
            print root.data
            return True
 
    # Otherwise return False because we did not find the node
    return False
