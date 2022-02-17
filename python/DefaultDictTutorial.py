from collections import defaultdict

d = defaultdict(list)
n, m = map(int,input().split())

for i in range (1,int(n)+1):
    d[input()].append(i) 

for _ in range (int(m)):
    i = input()
    if i in d:
        print( " ".join( map(str,d[i])) ) 
    else:
        print (-1) 

#https://www.hackerrank.com/challenges/defaultdict-tutorial/problem