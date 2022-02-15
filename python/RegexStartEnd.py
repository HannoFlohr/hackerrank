import re

S,k = input(), input() 
m = re.compile(k).search(S)

if not m: print('(-1, -1)')

while m:
    print("({0}, {1})".format(m.start(), m.end()-1) ) 
    m = re.compile(k).search(S,m.start()+1) 
	
#https://www.hackerrank.com/challenges/re-start-re-end/problem?isFullScreen=true