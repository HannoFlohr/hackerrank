a = int(input())
b = int(input())
print (a//b, a%b, divmod(a,b), sep='\n')

#https://www.hackerrank.com/challenges/python-mod-divmod/problem

print('{0}\n{1}\n({0}, {1})'.format(*divmod(int(input()), int(input())) ))