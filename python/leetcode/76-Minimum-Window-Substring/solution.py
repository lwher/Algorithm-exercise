from collections import defaultdict 
class Solution(object):
    def minWindow(self, s, t):
        Q = defaultdict(int)
        Sum = defaultdict(int)
        need = 0
        for x in t:
            Q[x] += 1
            if Q[x] == 1:
                need += 1
        ls = len(s)
        l = 0
        gs = 0
        minlen = 1e9
        res = ""
        for r in range(ls):
            Sum[s[r]] += 1
            if Sum[s[r]] == Q[s[r]]:
                gs += 1
            while l <= r and Q[s[l]] < Sum[s[l]]:
                Sum[s[l]] -= 1
                l += 1
            if gs == need and r - l < minlen:
                minlen = r - l
                res = s[l : r + 1]
        return res

        """
        :type s: str
        :type t: str
        :rtype: str
        """