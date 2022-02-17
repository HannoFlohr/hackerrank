from itertools import permutations

string, size = input().split()
print(*[''.join(i) for i in permutations(sorted(string),int(size))],sep='\n')

#https://www.hackerrank.com/challenges/itertools-permutations/problem