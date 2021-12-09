SELECT * 
FROM CITY 
WHERE 
    COUNTRYCODE = 'USA'
    AND POPULATION > 100000 
--https://www.hackerrank.com/challenges/revising-the-select-query/problem

SELECT NAME 
FROM CITY 
WHERE 
    COUNTRYCODE = 'USA'
    AND POPULATION > 120000 	
--https://www.hackerrank.com/challenges/revising-the-select-query-2/problem

SELECT * 
FROM CITY
--https://www.hackerrank.com/challenges/select-all-sql/problem

SELECT *
FROM CITY
WHERE ID = '1661'
--https://www.hackerrank.com/challenges/select-by-id/problem

SELECT * 
FROM CITY
WHERE COUNTRYCODE = 'JPN'
--https://www.hackerrank.com/challenges/japanese-cities-attributes/problem

SELECT NAME
FROM CITY
WHERE COUNTRYCODE = 'JPN'
--https://www.hackerrank.com/challenges/japanese-cities-name/problem

SELECT CITY, STATE 
FROM STATION
--https://www.hackerrank.com/challenges/weather-observation-station-1/problem

SELECT DISTINCT CITY
FROM STATION
WHERE ID%2=0
--https://www.hackerrank.com/challenges/weather-observation-station-3/problem

SELECT COUNT(CITY) - COUNT(DISTINCT CITY)
FROM STATION
--https://www.hackerrank.com/challenges/weather-observation-station-4/problem

SELECT CITY, LENGTH(CITY) FROM STATION
ORDER BY LENGTH(CITY) DESC, CITY ASC LIMIT 1;
SELECT CITY, LENGTH(CITY) FROM STATION
ORDER BY LENGTH(CITY) ASC, CITY ASC LIMIT 1;
--https://www.hackerrank.com/challenges/weather-observation-station-5/problem

SELECT DISTINCT CITY FROM STATION
WHERE CITY REGEXP '^[a, e, i, o, u]'
--https://www.hackerrank.com/challenges/weather-observation-station-6/problem

SELECT DISTINCT CITY FROM STATION
WHERE RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-7/problem

SELECT DISTINCT CITY FROM STATION
WHERE LEFT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u')
AND RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-8/problem

SELECT DISTINCT CITY FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-9/problem

SELECT DISTINCT CITY FROM STATION
WHERE RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-10/problem

SELECT DISTINCT CITY FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
OR RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-11/problem

SELECT DISTINCT CITY FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
AND RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
--https://www.hackerrank.com/challenges/weather-observation-station-12/problem

SELECT NAME FROM STUDENTS
WHERE MARKS > 75
ORDER BY RIGHT(NAME, 3), ID ASC
--https://www.hackerrank.com/challenges/more-than-75-marks/problem

SELECT NAME FROM EMPLOYEE 
ORDER BY NAME
--https://www.hackerrank.com/challenges/name-of-employees/problem

SELECT name FROM Employee
WHERE salary > 2000
AND months < 10
ORDER BY employee_id
--https://www.hackerrank.com/challenges/salary-of-employees/problem
