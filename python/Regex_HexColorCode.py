import re 

for _ in range(int(input())): 
    for hex in re.findall(r'(#[0-9a-fA-F]{3,6})[^\n ]', input()):
        print(hex)
		
#https://www.hackerrank.com/challenges/hex-color-code/problem