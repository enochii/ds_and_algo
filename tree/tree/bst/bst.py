"""
naive implementation for binary search tree
insert, search

"""
import unittest

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        pass

class Bst(object):
    def __init__(self):
        self.root = None

    def get_root(self):
        return self.root

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            return self._insert(self.root, data)
    def _insert(self, r, data):
        """
        here r is not None
        :param data: the value of the new node
        :return: return false if already exist else true
        """
        if data == r.data:
            return False
        elif data > r.data:
            if r.right is None:
                r.right = Node(data)
                return True
            else:
                return self._insert(r.right, data)
        else:
            if r.left is None:
                r.left = Node(data)
                return True
            else:
                return self._insert(r.left, data)
