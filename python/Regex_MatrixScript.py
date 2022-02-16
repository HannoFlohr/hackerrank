import re
n, m = map(int, input().split()) 
script, decoded = [], ""
for _ in range(n):
    script.append(input())  

for z in zip(*script):
    decoded += "".join(z)
print(re.sub(r"(?<=\w)([^\w]+)(?=\w)", " ", decoded))

#https://www.hackerrank.com/challenges/matrix-script/problem