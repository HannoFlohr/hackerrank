s = set()
for _ in range(int(input())):
    s.add(input())
print (len(s))

# one line solution
print ( len(set([str(input()) for _ in range(int(input()))])) )

# https://www.hackerrank.com/challenges/py-set-add/problem