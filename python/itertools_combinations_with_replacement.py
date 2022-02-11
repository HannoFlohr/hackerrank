from itertools import combinations_with_replacement
s, k = input().split()
for c in combinations_with_replacement(sorted(s), int(k)):
    print(''.join(c))
	
#https://www.hackerrank.com/challenges/itertools-combinations-with-replacement/problem