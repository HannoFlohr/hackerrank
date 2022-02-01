_ = int(input())
A = set(map(int, input().split()))
N = int(input())
for _ in range (N):
    command, value = input().split() 
    getattr(A, command)(map(int, input().split()))
print(sum(A)) 

#https://www.hackerrank.com/challenges/py-set-mutations/problem