c = input()
n = int(input())

for i in range(0, n):
	s = input()
	cnt = 0
	for ch in s:
		if(ch.lower() == c.lower()): cnt = cnt + 1
	if(cnt >= 3):
		print(s)