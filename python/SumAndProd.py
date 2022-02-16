import numpy
n,_ = map(int, input().split()) 
arr = numpy.array( [input().split() for _ in range(n)], int )
print( numpy.prod( numpy.sum(arr,axis=0), axis=0 ) )

#https://www.hackerrank.com/challenges/np-sum-and-prod/problem