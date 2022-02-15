from collections import deque
d = deque()
for _ in range(int(input())): 
    command, *values = input().split()
    getattr(d, command)(*values)
print(*d) 

#https://www.hackerrank.com/challenges/py-collections-deque/problem