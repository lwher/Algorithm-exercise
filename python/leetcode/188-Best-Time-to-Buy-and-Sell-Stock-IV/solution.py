class Solution(object):
    def maxProfit(self, k, prices):
        n = len(prices)
        if n <= 0 or k <= 0:
            return 0
        if k > n / 2:
            res = 0
            for i in xrange(1, n):
                res += max(0, prices[i] - prices[i - 1])
            return res
        dp = [[[0] * 2 for x in xrange(k + 2)] for y in xrange(2)]
        for j in xrange(k + 2):
            for i in xrange(2):
                dp[i][j][0] = -1e9
                dp[i][j][1] = -1e9
        p = 0
        q = 1
        dp[q][1][0] = 0
        for i in xrange(1, n + 1): 
            for j in xrange(1, k + 2):
                dp[p][j][0] = dp[q][j][0]
                if i > 1:
                    dp[p][j][0] = max(dp[p][j][0], dp[q][j - 1][1] + prices[i - 1] - prices[i - 2])
                dp[p][j][1] = dp[q][j][0]
                if i > 1:
                    dp[p][j][1] = max(dp[p][j][1], dp[q][j][1] + prices[i - 1] - prices[i - 2])
            p ^= 1
            q ^= 1
        res = 0
        for j in xrange(k + 2):
            res = max(res, dp[q][j][0])
        return res
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """