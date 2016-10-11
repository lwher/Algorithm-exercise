import math
n = int(input())
T = input()
num = [int(x) for x in T.split()]
num.sort()
p = math.ceil(n / 2)
print(num[p - 1])