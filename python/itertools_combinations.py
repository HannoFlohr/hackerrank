from itertools import combinations
s, k = input().split() 
for i in range(int(k)):
    for j in combinations(sorted(s), i+1):
        print (''.join(j)) 
		
#https://www.hackerrank.com/challenges/itertools-combinations/problem?isFullScreen=true