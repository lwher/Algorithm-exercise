class Solution(object):
    def trap(self, height):
        lmax, rmax = [], []
        maxh = 0
        for x in height:
            lmax.append(maxh)
            maxh = max(maxh, x)
        maxh = 0
        for x in height[::-1]:
            rmax.append(maxh)
            maxh = max(maxh, x)
        rmax = rmax[::-1]
        res = 0
        for i in range(len(height)):
            t = min(lmax[i], rmax[i])
            res += max(0, t - height[i])
        return res
        """
        :type height: List[int]
        :rtype: int
        """
