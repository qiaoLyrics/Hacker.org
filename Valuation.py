# 不会用shell转str -> int，郁闷..

l = input()
ans = 0
i = 0
while i < len(l) : 
	ch = l[i]
	if '0' <= ch and ch <= '9' : ans += ord(ch) - ord('0')
	elif ch == 'x' : 
		l = l[:i] + l[i+1:]
		i = max(0, i-3)
	i += 1
print(ans)
