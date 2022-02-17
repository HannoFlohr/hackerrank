import calendar

month, day, year = input().split()
res = calendar.weekday(int(year), int(month), int(day))
print ( calendar.day_name[res].upper() ) 

https://www.hackerrank.com/challenges/calendar-module/problem