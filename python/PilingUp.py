from collections import deque 

for _ in range(int(input())):
    _,q = input(), deque(map(int, input().split())) 
    
    for c in reversed(sorted(q)):
        if q[-1] == c: 
            q.pop()
        elif q[0] == c: 
            q.popleft()
        else:
            print('No')
            break 
    else: print('Yes') 
	
#https://www.hackerrank.com/challenges/piling-up/problem