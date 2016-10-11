n = int(input())
num = [[int(x) for x in input().split()] for y in range(n)]
if n == 1:
	print(1)
	exit(0)

sum1 = 0
sum2 = 0

sumx = [0] * n
sumy = [0] * n

for x in range(n):
	for y in range(n):
		if num[x][y] == 0:
			nx = x
			ny = y
		if x == y: 
			sum1 += num[x][y]
		if x + y == n - 1:
			sum2 += num[x][y]
		sumx[x] += num[x][y]
		sumy[y] += num[x][y]


if nx == 1:
	sum = sumx[0]
else:
	sum = sumx[1]

ans = sum - sumx[nx]

if ans < 1:
	print(-1)
	exit(0)

if nx == ny:
	sum1 += ans

if nx + ny == n - 1:
	sum2 += ans

if sum1 != sum or sum2 != sum:
	print(-1)
	exit(0)

for x in range(n):
	now = sumx[x]
	if nx == x:
		now += ans
	if now != sum:
		print(-1)
		exit(0)

for y in range(n):
	now = sumy[y]
	if ny == y:
		now += ans
	if now != sum:
		print(-1)
		exit(0)

print(ans)

	


