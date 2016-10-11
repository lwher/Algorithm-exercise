class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        A = int(a, 2)
        B = int(b, 2)
        C = A + B
        Ans = bin(C)
        Ans = Ans[2:]
        return Ans