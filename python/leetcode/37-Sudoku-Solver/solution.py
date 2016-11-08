class Solution(object):

    def DfsSolve(self, x, y):
        if x == 9:
            return True
        if y == 8:
            tx = x + 1; ty = 0
        else:
            tx = x; ty = y + 1
        if self.myboard[x][y] != 0:
            return self.DfsSolve(tx, ty)
        else:
            for p in range(9, 0, -1):
                if self.xmark[x][p] == False and self.ymark[y][p] == False and self.zmark[self.belong[x][y]][p] == False:
                    self.xmark[x][p] = True
                    self.ymark[y][p] = True
                    self.zmark[self.belong[x][y]][p] = True
                    self.myboard[x][y] = p
                    if self.DfsSolve(tx, ty) == True:
                        return True
                    self.xmark[x][p] = False
                    self.ymark[y][p] = False
                    self.zmark[self.belong[x][y]][p] = False
                    self.myboard[x][y] = 0
        return False

    def solveSudoku(self, board):
        self.myboard = board
        self.xmark = [[False] * 10 for _ in range(10)]
        self.ymark = [[False] * 10 for _ in range(10)]
        self.zmark = [[False] * 10 for _ in range(10)]
        self.belong = [[] for _ in range(10)]
        for x in range(9):
            for y in range(9):
                self.belong[x].append((x // 3) * 3 + y // 3)
                if board[x][y] == '.':
                    self.myboard[x][y] = 0
                else:
                    self.myboard[x][y] = int(board[x][y])
                    self.xmark[x][self.myboard[x][y]] = True
                    self.ymark[y][self.myboard[x][y]] = True
                    self.zmark[self.belong[x][y]][self.myboard[x][y]] = True
        self.DfsSolve(0, 0)
        for x in range(9):
            for y in range(9):
                board[x][y] = str(self.myboard[x][y])
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
