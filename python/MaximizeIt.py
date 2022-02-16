from itertools import product 

def f(x):
    return int(x)**2

k,mod = map(int, input().split()) 
a = []
for _ in range(k):
    a.append(list(map(f,input().split()[1:])))
    
max_sum = 0
for x in product(*a):
    cur_sum = sum(x) % mod
    if(max_sum < cur_sum):
        max_sum = cur_sum
print(max_sum)

#https://www.hackerrank.com/challenges/maximize-it/problem