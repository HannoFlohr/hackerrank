select sum(CITY.POPULATION) from CITY, COUNTRY 
where CITY.COUNTRYCODE = COUNTRY.CODE and COUNTRY.CONTINENT = 'Asia'
--https://www.hackerrank.com/challenges/asian-population/problem

select CITY.NAME from CITY, COUNTRY
where CITY.COUNTRYCODE = COUNTRY.CODE and COUNTRY.CONTINENT = 'Africa'
--https://www.hackerrank.com/challenges/african-cities/problem

select COUNTRY.CONTINENT, floor(avg(CITY.POPULATION)) from CITY, COUNTRY
where CITY.COUNTRYCODE = COUNTRY.CODE
group by COUNTRY.CONTINENT
--https://www.hackerrank.com/challenges/average-population-of-each-continent/problem

select case when G.Grade >7 then S.Name else NULL end as Names, G.Grade , S.Marks 
from Students S 
inner join Grades G on S.Marks >= G.Min_Mark and S.Marks <= G.Max_Mark 
order by Grade desc, Names, Marks;
--https://www.hackerrank.com/challenges/the-report/problem

select H.hacker_id, H.name
from Submissions S
join Challenges C   on S.challenge_id = C.challenge_id
join Difficulty D   on C.difficulty_level = D.difficulty_level
join Hackers H      on S.hacker_id = h.hacker_id
where S.score = D.score
    and C.difficulty_level = D.difficulty_level
group by H.hacker_id, H.name having count(S.hacker_id) > 1
order by count(S.hacker_id) desc, S.hacker_id asc
--https://www.hackerrank.com/challenges/full-score/problem

select w.id, wp.age, w.coins_needed, w.power 
from Wands as w 
join Wands_Property as wp on (w.code = wp.code) 
where wp.is_evil = 0 
    and w.coins_needed = (select min(coins_needed) 
        from Wands as w1 join Wands_Property 
        as wp1 on (w1.code = wp1.code) 
        where w1.power = w.power 
            and wp1.age = wp.age) 
order by w.power desc, wp.age desc
--https://www.hackerrank.com/challenges/harry-potter-and-wands/problem

select c.hacker_id, h.name, count(c.hacker_id) as hacker_count
from Hackers h 
inner join Challenges c on c.hacker_id = h.hacker_id
group by c.hacker_id, h.name
having 
    hacker_count in (select helper.helper_count
                     from(select hacker_id, count(challenge_id) as helper_count
                          from Challenges
                          group by hacker_id
                          order by helper_count desc
                          ) as helper
                     group by helper.helper_count
                     having count(helper.helper_count) = 1
                    )
or 
    hacker_count = (select max(helper.helper_count)
                    from(select hacker_id, count(challenge_id) as helper_count
                         from Challenges
                         group by hacker_id
                         order by helper_count desc
                        ) as helper
                   )
order by hacker_count desc, c.hacker_id
--https://www.hackerrank.com/challenges/challenges/problem

select h.hacker_id, h.name, sum(score) as scores
from Hackers as h
inner join (select hacker_id, max(score) as score
            from Submissions
            group by challenge_id, hacker_id) as max_score
on h.hacker_id=max_score.hacker_id
group by h.hacker_id, h.name
having scores > 0
order by scores desc, h.hacker_id
--https://www.hackerrank.com/challenges/contest-leaderboard/problem
