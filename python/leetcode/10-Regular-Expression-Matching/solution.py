class Solution(object):
    def isMatch(self, s, p):
        newp = ''
        has_star = []
        for x in p:
            if x == '*':
                has_star[-1] = True
            else:
                newp += x
                has_star.append(False)
        ls = len(s)
        lp = len(newp)
        f = [([False] * (lp + 1)) for x in range(ls + 1)]
        f[0][0] = True
        for j in range(1, lp + 1):
                if has_star[j - 1] == True:
                    if f[0][j - 1] == True:
                        f[0][j] = True
        for i in range(1, ls + 1):
            for j in range(1, lp + 1):
                if has_star[j - 1] == True:
                    f[i][j] = f[i][j - 1]
                    x = i
                    while x > 0 and (s[x - 1] == newp[j - 1] or newp[j - 1] == '.'):
                        if f[x - 1][j - 1] == True:
                            f[i][j] = True
                        x -= 1  
                else:
                    if newp[j - 1] == s[i - 1] or newp[j - 1] == '.':
                        f[i][j] = f[i - 1][j - 1]
        return f[ls][lp]
        """
        :type s: str
        :type p: str
        :rtype: bool
        """