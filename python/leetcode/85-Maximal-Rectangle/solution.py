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
        
    def maximalRectangle(self, matrix):
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        if m == 0:
            return 0
        height = [[0] * m for _ in range(2)]
        p = 0
        q = 1
        res = 0
        for x in matrix:
            for y in range(m):
                if x[y] == '1':
                    height[q][y] = height[p][y] + 1
                else:
                    height[q][y] = 0
            p ^= 1
            q ^= 1
            tmp = self.largestRectangleArea(height[p])
            if tmp > res:
                res = tmp
        return res
        """
        :type matrix: List[List[str]]
        :rtype: int
        """