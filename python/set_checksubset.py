t = int(input()) 
for _ in range (t):
    _,a = (int(input()), set(map(int, input().split()))) 
    _,b = (int(input()), set(map(int, input().split()))) 
    print(a.issubset(b)) 
	
#https://www.hackerrank.com/challenges/py-check-subset/problem