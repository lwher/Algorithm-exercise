class Solution(object):
	def find_rank_num(self, nums1, nums2, K):
		n = len(nums1)
		m = len(nums2)

		if n == 0:
			return nums2[K - 1]
		if m == 0:
			return nums1[K - 1]
		
		if K == n + m:
			if nums1[n - 1] > nums2[m - 1]:
				return nums1[n - 1]
			else:
				return nums2[m - 1]

		if n <= K and nums2[K - n] >= nums1[n - 1]:
			if n < K and nums1[n - 1] < nums2[K - n - 1]:
				return nums2[K - 1 - n]
			else:
				return nums1[n - 1]

		if n > K and nums2[0] >= nums1[K - 1]:
			return nums1[K - 1]

		if m <= K and nums1[K - m] >= nums2[m - 1]:
			if m < K and nums1[K - m - 1] >= nums2[m - 1]:
				return nums1[K - m - 1]
			else:
				return nums2[m - 1]

		if m > K and nums1[0] >= nums2[K - 1]:
			return nums2[K - 1]

		if m < K:
			l = K - m - 1
		else:
			l = 0

		if n > K:
			r = K - 1;
		else:
			r = n - 1;

		while l + 1 < r:
			mid = (l + r) / 2
			ptr = K - mid - 1
			if (nums2[K - mid - 1] >= nums1[mid]):
				l = mid
			else:
				r = mid
		if (r < n - 1 and nums1[r + 1] >= nums2[K - r - 2]) and nums2[K - r - 1] >= nums1[r]:
			w = r
		else:
			w = l

		if nums1[w] >= nums2[K - w - 2]:
			return nums1[w]
		else:
			return nums2[K - w - 2]



	def findMedianSortedArrays(self, nums1, nums2):
		n = len(nums1)
		m = len(nums2)
		if (n + m) % 2 == 1:
			return (float)(self.find_rank_num(nums1, nums2, (n + m) // 2 + 1))
		else:
			return (float)(self.find_rank_num(nums1, nums2, (n + m) // 2 + 1) + self.find_rank_num(nums1, nums2, (n + m) // 2)) * 0.5

		"""
		:type nums1: List[int]
	 	:type nums2: List[int]
		:rtype: float
		"""