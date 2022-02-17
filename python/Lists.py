if __name__ == '__main__':
    N = int(input())

    mylist = []

    for _ in range (0,N):
        values = input().split()

        if values[0] == "insert":
            mylist.insert(int(values[1]),int(values[2]))
        elif values[0] == "print":      
            print (mylist)
        elif values[0] == "remove":
            mylist.remove(int(values[1]))
        elif values[0] == "append":
            mylist.append(int(values[1])) 
        elif values[0] == "sort":
            mylist.sort()
        elif values[0] == "pop":
            mylist.pop()
        elif values[0] == "reverse":
            mylist.reverse()

#https://www.hackerrank.com/challenges/python-lists/problem