from datetime import datetime

timeformat = '%a %d %b %Y %H:%M:%S %z'

for _ in range (int(input())): 
    print( int(abs((datetime.strptime(input(),timeformat) - datetime.strptime(input(),timeformat)).total_seconds())) )
	
#https://www.hackerrank.com/challenges/python-time-delta/problem