_,_ = input().split() 
arr = input().split()
a = set(input().split())
b = set(input().split())
print( sum([(i in a) - (i in b) for i in arr]) ) 

#https://www.hackerrank.com/challenges/no-idea/problem