import re 

text = ''
for _ in range(int(input())):
    text += input() + '\n'
    
text = re.sub(r'(?<=\s)&&(?=\s)', 'and', text)    
text = re.sub(r'(?<=\s)\|\|(?=\s)', 'or', text)
print (text)

#https://www.hackerrank.com/challenges/re-sub-regex-substitution/problem