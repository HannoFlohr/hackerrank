import re
import email.utils as eu 

pattern = re.compile(r"^[a-zA-Z][\w\-.]*@[a-zA-Z]+\.[a-zA-Z]{1,3}$") 

for _ in range(int(input())): 
    name, email = eu.parseaddr(input()) 
    if pattern.match(email):
        print(eu.formataddr((name, email)))    

#https://www.hackerrank.com/challenges/validating-named-email-addresses/problem