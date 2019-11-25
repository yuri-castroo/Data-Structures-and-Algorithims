# Generic binary tree node
class Node(object):
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

# Evluate the mathematical expression given as a binary tree
def evaluate(root):
    # If we have reached a leaf node, return it's digit value
    if root.data.isdigit():
        return int(root.data)
    # If this is an operator it must be an internal node
    # Evaluate the two children and apply the given operator
    elif root.data == '-':
        return evaluate(root.left) - evaluate(root.right)
    elif root.data == '+':
        return evaluate(root.left) + evaluate(root.right)
    elif root.data == '/':
        return evaluate(root.left) / evaluate(root.right)
    elif root.data == '*':
        return evaluate(root.left) * evaluate(root.right)
    elif root.data == '%':
        return evaluate(root.left) % evaluate(root.right)


 
import operator 
# Just for fun, here is the solution in single line
def evaluate_fun(r):
    return int(r.data) if r.data.isdigit() else { '+': operator.add,'-': operator.sub,'*': operator.mul,'/': operator.div,'%': operator.mod }[r.data](evaluate_fun(r.left),evaluate_fun(r.right))
