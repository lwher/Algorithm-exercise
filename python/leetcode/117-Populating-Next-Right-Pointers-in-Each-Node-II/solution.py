# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        prehead = root
        prenow = root
        nexthead = None
        nextnow = None
        while prehead != None:
            while prenow != None:
                if prenow.left != None:
                    if nexthead == None:
                        nexthead = prenow.left
                        nextnow = nexthead
                    else:
                        nextnow.next = prenow.left
                        nextnow = prenow.left
                if prenow.right != None:
                    if nexthead == None:
                        nexthead = prenow.right
                        nextnow = nexthead
                    else:
                        nextnow.next = prenow.right
                        nextnow = prenow.right
                prenow = prenow.next
            prehead = nexthead
            prenow = prehead
            nexthead = None
