from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        if len(data.split('\n')) > 1:
            print('>>> Multi-line Comment')
        else:
            print('>>> Single-line Comment')
        if data.strip():
            print(data) 
            
    def handle_data(self, data):
        if data.strip():
            print('>>> Data\n'+data) 
            
html = ""       
for _ in range(int(input())):
    html += input().rstrip() + '\n'
    
parser = MyHTMLParser()
parser.feed(html)
parser.close()

#https://www.hackerrank.com/challenges/html-parser-part-2/problem