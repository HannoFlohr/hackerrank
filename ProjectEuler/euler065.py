n = int(input())
#to store the last three numerators of the sequence
nums = [0,1,2] 

for i in range(2,n+1): 
    #e = [2;1,2,1,1,4,1,1,6,1,...,1,2k,1,...]
    sequenceNumber = 1
    if i%3==0: sequenceNumber = int((i/3)*2)

    #update last numerators and generate the next one
    nums[0]=nums[1]
    nums[1]=nums[2]
    if(sequenceNumber==1):
        nums[2] = nums[0] + nums[1]
    else: 
        nums[2] = nums[0] + nums[1] * sequenceNumber
       
num = nums[2]
sum_digits = 0
while num: 
    sum_digits, num = sum_digits+num%10, num//10
    
print(sum_digits)
#https://www.hackerrank.com/contests/projecteuler/challenges/euler065/problem