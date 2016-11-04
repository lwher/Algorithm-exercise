class Solution(object):
    def match(self, s, p):
        l = len(s)
        for i in range(l):
            if not(s[i] == p[i] or p[i] == '?'):
                return False
        return True

    def isMatch(self, s, p):
        s = '#$%' + s + '#$%'
        p = '#$%' + p + '#$%'
        ls = len(s)
        lp = len(p)
        newp = p.split('*')
        L = []
        for x in newp:
            L.append(len(x))
        if ls < L[0] or not(self.match(s[:L[0]], newp[0])):
            return False
        now = 1
        i = L[0]
        while i < ls:
            if ls - i >= L[now] and self.match(s[i : i + L[now]], newp[now]):
                i += L[now]
                now += 1
            else:
                i += 1
        if now < len(newp):
            return False
        else:
            return True
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
