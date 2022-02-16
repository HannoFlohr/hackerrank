n,m = map(int, input().split()) 
data = [input() for _ in range(n)]
k = int(input()) 
for d in sorted(data, key=lambda d: int(d.split()[k])):
    print(d)
	
#https://www.hackerrank.com/challenges/python-sort-sort/problem