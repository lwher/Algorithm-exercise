class Solution(object):
    def largestRectangleArea(self, heights):
        n = len(heights)
        ans = 0
        top = -1
        L = [0] * n
        stack = [0] * n
        for i in range(n):
            while top > -1 and heights[stack[top]] >= heights[i]:
                top -= 1
            if top == -1:
                L[i] = -1
            else:
                L[i] = stack[top]
            top += 1
            stack[top] = i
        top = -1
        for i in range(n - 1, -1, -1):
            while top > -1 and heights[stack[top]] >= heights[i]:
                top -= 1
            if top == -1:
                R = n
            else:
                R = stack[top]
            top += 1
            stack[top] = i
            if ans < heights[i] * (R - L[i] - 1):
                ans = heights[i] * (R - L[i] - 1)
        return ans
        """
        :type heights: List[int]
        :rtype: int
        """
        