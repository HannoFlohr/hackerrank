import numpy

def arrays(arr):
    return numpy.array(numpy.flipud(arr), float)

arr = input().strip().split(' ')
result = arrays(arr)
print(result)

#https://www.hackerrank.com/challenges/np-arrays/problem