class Solution(object):
    def GetMin(self, l, r):
        if l == r:
            return self.nums[l]
        if l + 1 == r:
            return min(self.nums[l], self.nums[r])
        mid = (l + r) >> 1
        if self.nums[mid] > self.nums[l]:
            return self.GetMin(mid, r)
        elif self.nums[mid] < self.nums[l]:
            return self.GetMin(l, mid)
        else:
            return min(self.GetMin(l, mid), self.GetMin(mid, r))
    
    def findMin(self, nums):
        n = len(nums)
        self.nums = nums
        if nums[0] < nums[-1]:
            return nums[0]
        return self.GetMin(0, n - 1)
        """
        :type nums: List[int]
        :rtype: int
        """
        