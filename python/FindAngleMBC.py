import math
AB = int(input())
BC = int(input())
print ( int(round(math.degrees(math.atan2(AB,BC)))), chr(176), sep='')

#https://www.hackerrank.com/challenges/find-angle/problem

import math
print ( int(round(math.degrees(math.atan2(int(input()),int(input()))))), chr(176), sep='')