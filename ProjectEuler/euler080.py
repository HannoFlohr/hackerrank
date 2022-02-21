from decimal import *
from math import sqrt 

n,p = int(input()),int(input()) 
getcontext().prec = p+5 

result = 0
for a in range(n+1):
    if not sqrt(a)%1 == 0:
        root = str(Decimal(a).sqrt()).replace('.', '')[:p]
        digits = map(int, root)
        result += sum(digits)
        
print(result)

#https://www.hackerrank.com/contests/projecteuler/challenges/euler080/problem