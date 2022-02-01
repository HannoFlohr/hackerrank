K = int(input()) 
arr = list(map(int, input().split()))   
s = set(arr) 
print( ((sum(s)*K) - (sum(arr))) // (K-1) )
#solution: calculate the difference of the sum if there were K elements of all groups
#and the sum we are given. resulting in (k-1)*room number of captain, so divide by that

#https://www.hackerrank.com/challenges/py-the-captains-room/problem