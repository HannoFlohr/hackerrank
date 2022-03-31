def digit(A, B, n):
    #set first two lengths and check against n
    length_i = [len(A),len(B)]
    if len(A) >= n:
        return A[n-1]
    if len(B) >= n:
        return B[n-1] 
    
    #find first F(A,B) with length >= n
    i = 1
    while length_i[i] < n:
        i = i+1
        length_i.append(length_i[i-2] + length_i[i-1])

    #find digit n recursively using F(i) = F(i-2) + F(i-1)
    length_diff = n
    while i>1:
        if length_i[i-2] < length_diff:
            length_diff = length_diff - length_i[i-2]
            i = i-1;
        else :
            i = i-2;
    
    if i==0:
        return A[length_diff-1]
    else:
        return B[length_diff-1]
        
for _ in range(int(input())): 
    A, B, n = input().rstrip().split() 
    result = digit(A,B,int(n)) 
    print(result)

#https://www.hackerrank.com/contests/projecteuler/challenges/euler230/problem

# length of F(146) = 1454489111232772683678306641953 > 2^100  
# by far exceeds unsigned long long in c++ (same approach could be used using a BigInteger class in c++)