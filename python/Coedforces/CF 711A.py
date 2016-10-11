n = int(input())
s = []
for i in range(n):
	s.append(input())
flag = False
for i in range(n):
	if "OO" in s[i]:
		s[i] = s[i].replace("OO", "++", 1)
		print("YES")
		print("\n".join(s))
		flag = True
		break
if flag == False:
	print("NO")
