W = input()
r = W[0]
c = int(W[1])
ans = 0
if (r == 'a' and (c == 1 or c == 8)) or (r == 'h' and (c == 1 or c == 8)):
	ans = 3
elif r == 'a' or r == 'h' or c == 1 or c == 8:
	ans = 5
else:
	ans = 8

print(ans)
