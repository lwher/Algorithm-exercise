class Solution(object):
    def half_search(self, L, R, x, nums):
        l = L
        r = R
        while l + 1 < r:
            mid = (l + r) >> 1
            if nums[mid] == x:
                return mid
            if nums[mid] < x:
                l = mid
            else:
                r = mid
        if nums[l] == x:
            return l
        elif nums[r] == x:
            return r
        else:
            return -1


    def search(self, nums, target):
        L = len(nums)
        l = 0
        r = L - 1
        if nums[L - 1] > nums[0]:
            return self.half_search(0, L - 1, target, nums)
        while l + 1 < r:
            mid = (l + r) >> 1
            if nums[mid] > nums[L - 1]:
                l = mid
            else:
                r = mid
        res = self.half_search(0, l, target, nums)
        if res != -1:
            return res
        return self.half_search(r, L - 1, target, nums)

        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

