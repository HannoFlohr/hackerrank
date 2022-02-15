cube = lambda x: pow(x,3) 

def fibonacci(n):
    fibo = [0,1]
    for i in range(2,n):
        fibo.append(fibo[i-2]+fibo[i-1])
    return fibo[0:n]
        
if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))
	
#https://www.hackerrank.com/challenges/map-and-lambda-expression/problem