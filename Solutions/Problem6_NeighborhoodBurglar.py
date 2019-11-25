# Generic tree node object
class Node(object):
    def __init__(self, data, children=None):
        self.data = data
        self.children = children

# Determine the node with the highest value at each layer of a tree
def rob(root):
    # Initialize a queue with the root node, at row 1
    # Use a tuple to store the current row
    queue = [(1, root)]
    # Initialize a dictionary to keep track of the maximum value per row
    max_value = {}

    # While there are still nodes left to visit
    while queue:
        # Pop a node off of the queue
        house = queue.pop(0)

        # Update the maximum value of the current row with new max
        if house[0] in max_value:
            max_value[house[0]] = max(house[1].data, max_value[house[0]])
        else:
            max_value[house[0]] = house[1].data

        # If this node has children, add those children to the queue
        if house[1].children:
            # Create the required tuples to link current row and node and add them to the queue
            queue += map(lambda x : (house[0]+1, x), house[1].children)

    # Sum and return the maximum values per neighborhood
    print max_value
    return sum(max_value.values())
