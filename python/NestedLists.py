nlist = []
scores = []

for i in range(int(input())):
    name = input()
    score = float(input())

    nlist += [[name,score]]
    scores += [score]

res = sorted(list(set(scores)))[1] 

for a,b in sorted(nlist):
    if b==res:
        print (a)

#https://www.hackerrank.com/challenges/nested-list/problem