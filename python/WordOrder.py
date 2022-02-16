from collections import OrderedDict

dictionary = OrderedDict()
for _ in range(int(input())): 
    key = input()
    if not key in dictionary.keys():
        dictionary.update({key : 1})
        continue
    dictionary[key] += 1
    
print( len(dictionary.keys()) )
print( *dictionary.values() )

https://www.hackerrank.com/challenges/word-order/problem?isFullScreen=true