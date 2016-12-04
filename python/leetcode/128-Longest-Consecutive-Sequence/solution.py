class Solution(object):
    def longestConsecutive(self, nums):
        hash_map = {}
        for x in nums:
            hash_map[x] = 0
        res = 1
        for x in nums:
            if hash_map[x] == 1:
                continue
            l = x; r = x;
            while(l - 1 in hash_map):
                l -= 1
                hash_map[l] = 1
            while(r + 1 in hash_map):
                r += 1
                hash_map[r] = 1
            res = max(res, r - l + 1)
        return res
            
        """
        :type nums: List[int]
        :rtype: int
        """
