from collections import namedtuple

n = int(input())
fields = input().split()
marks = 0
for i in range (n):
    student = namedtuple('student',fields) 
    f1, f2, f3, f4 = input().split()
    s = student(f1,f2,f3,f4)
    marks += int(s.MARKS) 
print ( '{:.2f}'.format(marks/n) ) 

#https://www.hackerrank.com/challenges/py-collections-namedtuple/problem