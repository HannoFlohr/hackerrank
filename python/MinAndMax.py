import numpy
n,_ = map(int, input().split())
arr = numpy.array([list(map(int,(input().split()))) for _ in range(n)]) 
print(numpy.max(numpy.min(arr, axis=1), axis=None)) 

#https://www.hackerrank.com/challenges/np-min-and-max/problem