import numpy
numpy.set_printoptions(legacy='1.13') 
arr = numpy.array(input().split(), float)
print( *(f(arr) for f in [numpy.floor, numpy.ceil, numpy.rint]), sep='\n' )

#https://www.hackerrank.com/challenges/floor-ceil-and-rint/problem