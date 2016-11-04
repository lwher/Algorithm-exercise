class Solution(object):
    def firstMissingPositive(self, nums):
        L = len(nums)
        for i in range(L):
            while nums[i] != i + 1 and nums[i] > 0 and nums[i] <= L:
                w = nums[i] - 1
                if nums[w] == w + 1:
                    break
                nums[i] ^= nums[w]
                nums[w] ^= nums[i]
                nums[i] ^= nums[w]
        for i in range(L):
            if nums[i] != i + 1:
                return i + 1
        return L + 1
        """
        :type nums: List[int]
        :rtype: int
        """