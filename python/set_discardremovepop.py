n = int(input())
s = set(map(int, input().split()))
N = int(input()) 
for _ in range (N):
    command, *value = input().split()
    getattr(s,command)(*(map(int, value))) 
print(sum(s))

#https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem