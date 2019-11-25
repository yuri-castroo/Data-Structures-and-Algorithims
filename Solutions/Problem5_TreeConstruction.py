# Generic binary node object
class Node:
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Recursively build a tree based on preorder and inorder traversals
def buildTree(preorder, inorder):
    # If there are no nodes left in the traversal we have reached, return none
    if not preorder and not inorder:
        return None
    # If we are down to a single node in the preorder and inorder traversal, create the leaf node
    elif preorder == inorder and len(preorder) == 1:
        return Node(preorder[0])
    # Otherwise we are at an internal node
    else:
        # The first node in the preorder traversal is the head of this subtree
        # Create a node and initialize it with that data
        head = Node(preorder[0])

        # split inorder into left and right based on root from preorder traversal
        in_split_index = inorder.index(root_data)
        in_left = [] if in_split_index == 0 else inorder[0:in_split_index]
        in_right = [] if in_split_index == len(inorder)-1 else inorder[in_split_index+1:]

        # split preorder into left and right based on length of inorder splits
        pre_left = [] if not in_left else preorder[1:1+len(in_left)]
        pre_right = [] if not in_right else preorder[-1*len(in_right):]

        # Recursively Built the left and right nodes
        head.left = buildTree(pre_left, in_left)
        head.right = buildTree(pre_right, in_right)

        # Return the created node
        return head
