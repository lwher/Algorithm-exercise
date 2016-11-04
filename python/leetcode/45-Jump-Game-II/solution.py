class Solution(object):
    def jump(self, nums):
        dp = [0]
        l = 0
        L = len(nums)
        for i in range(L):
            x = i + nums[i]
            while l < x:
                l += 1
                t = dp[i] + 1
                dp.append(t)
        return dp[L - 1]
        """
        :type nums: List[int]
        :rtype: int
        """
