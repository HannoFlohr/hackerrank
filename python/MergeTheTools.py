def merge_the_tools(string, k):
    index = 0
    while index < len(string): 
        s = string[index:index+k]
        index += k
        print( "".join(dict.fromkeys(s)) )

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
	
#https://www.hackerrank.com/challenges/merge-the-tools/problem