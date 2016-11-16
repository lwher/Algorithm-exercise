class Solution(object):
    def minMoves(self, nums):
        minx = nums[0]
        for x in nums:
            if x < minx:
                minx = x
        res = 0
        for x in nums:
            res += x - minx
        return res
        """
        :type nums: List[int]
        :rtype: int
        """