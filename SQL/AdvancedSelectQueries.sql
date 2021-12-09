SELECT CASE
    WHEN 2*GREATEST(A,B,C) >= (A+B+C)   THEN "Not A Triangle"
    WHEN A=B AND A=C                    THEN "Equilateral"
    WHEN A=B OR A=C OR B=C              THEN "Isosceles"
    ELSE "Scalene"
    END
FROM TRIANGLES
--https://www.hackerrank.com/challenges/what-type-of-triangle/problem

select concat(Name, '(', Substring(Occupation,1,1), ')') as Name
from OCCUPATIONS
order by Name;
select concat('There are a total of', ' ', count(Occupation), ' ', lower(Occupation), 's.') as total
from OCCUPATIONS
group by occupation
order by total
--https://www.hackerrank.com/challenges/the-pads/problem

set @r1=0, @r2=0, @r3=0, @r4=0; 
select min(Doctor), min(Professor), min(Singer), min(Actor)
from(
    select case
            when Occupation='Doctor'    then (@r1:=@r1+1)
            when Occupation='Professor' then (@r2:=@r2+1)
            when Occupation='Singer'    then (@r3:=@r3+1)
            when Occupation='Actor'     then (@r4:=@r4+1)
            end as rowNumber,
        case when Occupation='Doctor' then Name end as Doctor,
        case when Occupation='Professor' then Name end as Professor,
        case when Occupation='Singer' then Name end as Singer,
        case when Occupation='Actor' then Name end as Actor
    from OCCUPATIONS
    order by Name
) Temp
group by rowNumber
--https://www.hackerrank.com/challenges/occupations/problem

select case
    when P is NULL then concat(N, ' Root')
    when N in (select distinct P from BST) then concat(N, ' Inner')
    else concat(N, ' Leaf')
    end
from BST
order by N asc
--https://www.hackerrank.com/challenges/binary-search-tree-1/problem 

select c.company_code, c.founder, count(distinct l.lead_manager_code),
        count(distinct s.senior_manager_code), count(distinct m.manager_code), 
        count(distinct e.employee_code)
from Company c, Lead_Manager l, Senior_Manager s, Manager m, Employee e
where c.company_code = l.company_code
        and l.lead_manager_code = s.lead_manager_code
        and s.senior_manager_code = m.senior_manager_code
        and m.manager_code = e.manager_code
group by c.company_code, c.founder 
order by c.company_code
--https://www.hackerrank.com/challenges/the-company/problem