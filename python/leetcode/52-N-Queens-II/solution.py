class Solution(object):

    def DfsSolve(self, x):
        if x == self.n:
            self.res += 1
            return
        for y in range(self.n):
            if self.ymark[y] == False and self.xpymark[x + y] == False and self.xdymark[x - y + self.n] == False:
                self.ymark[y] = True
                self.xpymark[x + y] = True 
                self.xdymark[x - y + self.n] = True
                self.board[x][y] = True
                self.DfsSolve(x + 1)
                self.ymark[y] = False
                self.xpymark[x + y] = False 
                self.xdymark[x - y + self.n] = False
                self.board[x][y] = False

    def totalNQueens(self, n):
        self.ymark = [False] * n
        self.xpymark = [False] * n * 2
        self.xdymark = [False] * n * 2
        self.res = 0
        self.n = n
        self.board = [[False] * n for _ in range(n)]  
        self.DfsSolve(0)
        return self.res
        """
        :type n: int
        :rtype: List[List[str]]
        """
