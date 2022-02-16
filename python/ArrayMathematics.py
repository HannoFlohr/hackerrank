import numpy
n,m = map(int, input().split())
a,b = ( numpy.array([input().split() for _ in range(n)], int) for _ in range(2) )
print(numpy.add(a,b))
print(numpy.subtract(a,b))
print(numpy.multiply(a,b))
print(numpy.floor_divide(a,b))
print(numpy.mod(a,b))
print(numpy.power(a,b))

#https://www.hackerrank.com/challenges/np-array-mathematics/problem