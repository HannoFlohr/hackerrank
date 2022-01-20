m,n = [set(input().split()) for _ in range(4)][1::2]
print('\n'.join(sorted(m^n, key=int)))

#https://www.hackerrank.com/challenges/symmetric-difference/problem