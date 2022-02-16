from itertools import combinations
n = int(input()) 
l = input().split()
k = int(input())

total_combinations = list(combinations(l, k))
combinations_with_k = filter(lambda c: 'a' in c, total_combinations)
print( round(len(list(combinations_with_k))/len(total_combinations), 3) )

#https://www.hackerrank.com/challenges/iterables-and-iterators/problem