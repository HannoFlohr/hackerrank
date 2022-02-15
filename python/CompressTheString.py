from itertools import groupby

for k,g in groupby(input()):
    print("({}, {})".format(len(list(g)), k), end=" ")  
	
#https://www.hackerrank.com/challenges/compress-the-string/problem