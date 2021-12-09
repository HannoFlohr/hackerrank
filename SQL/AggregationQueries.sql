select count(NAME)
from CITY
where POPULATION > 100000
--https://www.hackerrank.com/challenges/revising-aggregations-the-count-function/problem

select sum(POPULATION)
from CITY
where DISTRICT = 'California'
--https://www.hackerrank.com/challenges/revising-aggregations-sum/problem

select avg(POPULATION)
from CITY
where DISTRICT = 'California'
--https://www.hackerrank.com/challenges/revising-aggregations-the-average-function/problem

select floor(avg(POPULATION))
from CITY
--https://www.hackerrank.com/challenges/average-population/problem

select sum(POPULATION)
from CITY
where COUNTRYCODE = 'JPN'
--https://www.hackerrank.com/challenges/japan-population/problem

select max(POPULATION) - min(POPULATION) 
from CITY
--https://www.hackerrank.com/challenges/population-density-difference/problem

select ceil(avg(Salary) - avg(replace(Salary,'0',''))) 
from EMPLOYEES
--https://www.hackerrank.com/challenges/the-blunder/problem

select salary * months as earnings, count(*)
from Employee
group by 1
order by earnings desc limit 1;
--https://www.hackerrank.com/challenges/earnings-of-employees/problem

select round(sum(LAT_N),2), round(sum(LONG_W),2)
from STATION
--https://www.hackerrank.com/challenges/weather-observation-station-2/problem

select round(sum(LAT_N),4)
from STATION
where LAT_N > 38.7880 
    AND LAT_N < 137.2345
--https://www.hackerrank.com/challenges/weather-observation-station-13/problem

select round(max(LAT_N),4) from STATION
where LAT_N < 137.2345
--https://www.hackerrank.com/challenges/weather-observation-station-14/problem

select round(LONG_W,4) from STATION
where LAT_N = (select max(LAT_N) from STATION where LAT_N < 137.2345)
--https://www.hackerrank.com/challenges/weather-observation-station-15/problem

select round(min(LAT_N),4) from STATION
where LAT_N > 38.7780
--https://www.hackerrank.com/challenges/weather-observation-station-16/problem

select round(LONG_W,4) from STATION
where LAT_N = (select min(LAT_N) from STATION where LAT_N > 38.7780)
--https://www.hackerrank.com/challenges/weather-observation-station-17/problem

select round((max(LAT_N)-min(LAT_N) + max(LONG_W)-min(LONG_W)), 4)
from STATION
--https://www.hackerrank.com/challenges/weather-observation-station-18/problem

select round( 
    sqrt( power(max(LAT_N)-min(LAT_N), 2) + power(max(LONG_W)-min(LONG_W), 2) )
    , 4)
from STATION
--https://www.hackerrank.com/challenges/weather-observation-station-19/problem

set @index:=-1;
select round(avg(LAT_N), 4)
from (select @index:=@index+1 as idx, lat_n
        from STATION
        order by lat_n)
        as l
where l.idx in (floor(@index/2), ceil(@index/2))
--https://www.hackerrank.com/challenges/weather-observation-station-20/problem
