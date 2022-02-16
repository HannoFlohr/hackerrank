import re

for _ in range(int(input())):
    ccn = input().strip()   
    try: 
        assert re.match(r'^(\d{4}-){3}\d{4}$', ccn) or re.match(r'^\d{16}$', ccn)
        ccn = re.sub(r'-', '', ccn)
        assert re.match(r'^[4-6]', ccn)
        assert not re.search(r'(\d)\1{3,}', ccn)      
    except:
        print('Invalid')
    else:
        print('Valid') 
		
#https://www.hackerrank.com/challenges/validating-credit-card-number/problem