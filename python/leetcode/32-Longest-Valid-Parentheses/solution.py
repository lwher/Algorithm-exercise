class Solution(object):
    def longestValidParentheses(self, s):
        L = len(s)
        l = [-1] * 2 * (L + 1)
        p = L + 1
        res = 0
        for i in range(L):
            x = s[i]
            if x == '(':
                p -= 1
                if l[p + 1] == -1:
                    l[p + 1] = i 
            else:
                p += 1
                l[p - 1] = -1
                if l[p] != -1 and i - l[p] + 1 > res:
                    res = i - l[p] + 1
        return res
        """
        :type s: str
        :rtype: int
        """