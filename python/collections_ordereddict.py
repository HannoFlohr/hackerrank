from collections import OrderedDict

items = OrderedDict()
for _ in range( int(input()) ): 
    i,j,q = input().rpartition(' ') 
    items[i] = items.get(i,0) + int(q) 
for i,q in items.items(): 
    print (i,q) 

#https://www.hackerrank.com/challenges/py-collections-ordereddict/problem