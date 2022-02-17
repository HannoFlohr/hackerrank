from collections import Counter
chars = Counter(input()).items()
for c in sorted(chars, key=lambda i: (-i[1],i[0]))[:3] :
    print (c[0], c[1])

#https://www.hackerrank.com/challenges/most-commons/problem