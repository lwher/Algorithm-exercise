# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        if root == None:
            return []
        PostorderSeq = []
        point_stack = []
        state_stack = []
        top = 1
        point_stack.append(root)
        state_stack.append(True)
        while top > 0:
            now = point_stack[-1]
            if state_stack[-1] == False:
                PostorderSeq.append(now.val)
                point_stack.pop()
                state_stack.pop()
                top -= 1
            else:
                state_stack[-1] = False                
                if now.right != None:
                    point_stack.append(now.right)
                    state_stack.append(True)
                    top += 1
                if now.left != None:
                    point_stack.append(now.left)
                    state_stack.append(True)
                    top += 1
        return PostorderSeq
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        