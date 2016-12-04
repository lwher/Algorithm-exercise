# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def dfs(self, t):
        if t == None:
            return -1e8, -1e8
        lmax, lmaxdep = self.dfs(t.left)
        rmax, rmaxdep = self.dfs(t.right)
        maxx = max(lmax, rmax)
        maxx = max(maxx, lmaxdep + rmaxdep + t.val)
        maxdep = max(lmaxdep, rmaxdep) + t.val
        maxdep = max(maxdep, t.val)
        maxx = max(maxx, maxdep)
        return maxx, maxdep
    
    def maxPathSum(self, root):
        res, maxdep = self.dfs(root)
        return res
        """
        :type root: TreeNode
        :rtype: int
        """
