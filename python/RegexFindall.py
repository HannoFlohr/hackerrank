import re
consonants = '[qwrtypsdfghjklzxcvbnm]'
match = re.findall('(?<=' + consonants + ')([aeiou]{2,})' + consonants, input(), re.I)
print( '\n'.join(match or ['-1']) )

#https://www.hackerrank.com/challenges/re-findall-re-finditer/problem