import numpy
n = int(input()) 
a,b = ( numpy.array([input().split() for _ in range(n)], int) for _ in range(2) )
print(numpy.dot(a,b))

#https://www.hackerrank.com/challenges/np-dot-and-cross/problem