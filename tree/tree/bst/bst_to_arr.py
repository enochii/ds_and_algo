from tree.bst.bst import Node, Bst

"""
actually, it's almost the same as inorder travelsal
"""

def bst_to_arr(root, res):
    if root is None:
        pass
    else:
        bst_to_arr(root.left, res)
        res.append(root.data)
        bst_to_arr(root.right, res)

test_tree = Bst()
test_tree.insert(2)
test_tree.insert(9)
test_tree.insert(11)
test_tree.insert(1)
test_tree.insert(-1)
test_tree.insert(5)

l = []
bst_to_arr(test_tree.get_root(), l)

print(l)