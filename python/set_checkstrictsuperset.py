A = set(map(int, input().split()))  
n = int(input()) 
strictsuperset = True 
for _ in range (n):
    B = set(map(int, input().split())) 
    if not A.issuperset(B):
        strictsuperset = False
print(strictsuperset) 

#https://www.hackerrank.com/challenges/py-check-strict-superset/problem