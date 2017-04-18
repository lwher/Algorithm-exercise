class Solution(object):
    def calculateMinimumHP(self, dungeon):
        n = len(dungeon)
        if n <= 0:
            return 1
        m = len(dungeon[0])
        if m <= 0:
            return 1
        dp = [[0] * m for x in xrange(n)]
        for i in xrange(n - 1, -1, -1):
            for j in xrange(m - 1, -1, -1):
                if i == n - 1 and j == m - 1:
                    tmp = 1
                else:
                    tmp = 1e9
                if i < n - 1:
                    tmp = min(tmp, dp[i + 1][j])
                if j < m - 1:
                    tmp = min(tmp, dp[i][j + 1])
                dp[i][j] = max(tmp - dungeon[i][j], 1)
        return dp[0][0]
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        