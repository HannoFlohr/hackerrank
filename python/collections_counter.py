from collections import Counter
n = input()
sizes = Counter(map(int,input().split()))
x = int(input())

earned = 0
for i in range(x):
    s, p = map(int,input().split())
    if s in sizes and sizes[s] > 0:
        earned += int(p) 
        sizes[s] -= 1

print (earned) 

#https://www.hackerrank.com/challenges/collections-counter/problem