class Solution(object):
    def maximumGap(self, nums):
        n = len(nums)
        if n < 2:
            return 0
        Max = nums[0]
        Min = nums[0]
        for x in nums:
            Max = max(Max, x)
            Min = min(Min, x)
        if Max == Min:
            return 0
        gap = 1.0 * (Max - Min) / (n - 1)
        answer = 0
        L = [Max] * (n + 1)
        R = [Min] * (n + 1)
        exist = [False] * (n + 1)
        for x in nums:
            k = int((x - Min) / gap)
            exist[k] = True
            L[k] = min(L[k], x)
            R[k] = max(R[k], x)
        lastx = Min
        for i in xrange(n + 1):
            if exist[i] == True:
                answer = max(answer, L[i] - lastx)
                lastx = R[i]
        return answer
            
        """
        :type nums: List[int]
        :rtype: int
        """
        