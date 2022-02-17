def minion_game(string):
    stuart, kevin, n = 0, 0, len(string)
    for i in range(n):
        if string[i] in 'AEIOU': kevin += n-i
        else: stuart += n-i
    
    if(kevin==stuart):  print('Draw')
    elif(kevin>stuart): print('Kevin', kevin)
    else:               print('Stuart', stuart) 

if __name__ == '__main__':
    s = input()
    minion_game(s)
	
#https://www.hackerrank.com/challenges/the-minion-game/problem