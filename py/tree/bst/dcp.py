"""
deepst common parent of x and y (both x and y are values.the dcp just need to let root
down step by step, and the position that root is between x and y is the final result
"""
from tree.bst.bst import Node, Bst

def dcp(tree, x, y):
    root = tree.get_root()
    if x > y:
        temp = x
        x = y
        y = temp

    assert root is not None
    #assert x < root.data < y

    while root is not None:
        if x <= root.data <= y:
            return root.data
        elif y < root.data:#
            root = root.left
        elif x > root.data:
            root = root.right


    print(x, " and ", y, "are not all in tree ", tree)
    return False

#test
test_tree = Bst()
test_tree.insert(2)
test_tree.insert(9)
test_tree.insert(11)
test_tree.insert(1)
test_tree.insert(-1)
test_tree.insert(5)
test_tree.insert(4)
test_tree.insert(3)
test_tree.insert(6)
print(dcp(test_tree, 3, 6))
print(dcp(test_tree, 3, 11))
print(dcp(test_tree, 3, -1))