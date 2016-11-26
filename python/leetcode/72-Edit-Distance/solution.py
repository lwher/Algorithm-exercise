class Solution(object):
    def minDistance(self, word1, word2):
        la = len(word1); lb = len(word2)
        if la == 0 or lb == 0:
            return la + lb
        dp = [[1e9] * (lb + 1) for _ in range(la + 1)]
        dp[0][0] = 0
        for i in range(la + 1):
            for j in range(lb + 1):
                if i > 0 and j > 0:
                    if word1[i - 1] == word2[j - 1]:
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
                    else:
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1)
                if i > 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)
                if j > 0:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1)
        return dp[la][lb]
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """