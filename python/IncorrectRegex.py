import re

for _ in range(int(input())):
    try:
        print(bool(re.compile(input()))) 
    except re.error:
        print('False') 
		
#https://www.hackerrank.com/challenges/incorrect-regex/problem