from html.parser import HTMLParser
class MyHTMLParser(HTMLParser): 
    def handle_starttag(self, tag, attrs):
        print(tag)
        for a in attrs:
            print('->', a[0], '>', a[1])
            
htmlParser = MyHTMLParser()
for _ in range(int(input())):
    htmlParser.feed(input()) 
	
#https://www.hackerrank.com/challenges/detect-html-tags-attributes-and-attribute-values/problem