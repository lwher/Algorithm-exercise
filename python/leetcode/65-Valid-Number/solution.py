class Solution(object):

    def gettype(self, x):
        if x >= '0' and x <= '9':
            return 0
        elif x == '+' or x == '-':
            return 1
        elif x == ' ':
            return 2
        elif x == 'e':
            return 3
        elif x == '.':
            return 4
        else:
            return 5

    def isNumber(self, s):
        trans = [[2, 3, 0, -1, 4, -1],
                 [1, -1, 7, 5, -1, -1],
                 [2, -1, 7, 5, 1, -1],
                 [2, -1, -1, -1, 4, -1],
                 [1, -1, -1, -1, -1, -1],
                 [6, 8, -1, -1, -1, -1],
                 [6, -1, 7, -1, -1, -1],
                 [-1, -1, 7, -1, -1, -1],
                 [6, -1, -1, -1, -1, -1]]
        now = 0
        for x in s:
            if now == -1:
                break
            now = trans[now][self.gettype(x)]
        if now == 1 or now == 2 or now == 6 or now == 7:
            return True
        else:
            return False

        """
        :type s: str
        :rtype: bool
        """
