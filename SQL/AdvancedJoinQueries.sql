select Start_Date, min(End_Date)
from(
    select Start_Date from Projects
    where Start_Date not in (select End_Date from Projects) 
    ) a,
    (select End_Date from Projects
     where End_Date not in (select Start_Date from Projects)
    ) b
where Start_Date < End_Date
group by Start_Date
order by datediff(min(End_Date), Start_Date), start_date
--https://www.hackerrank.com/challenges/sql-projects/problem

select S.Name
from( 
    Students S 
    join Friends F on S.ID=F.ID
    join Packages P1 on S.ID=P1.ID
    join Packages P2 on F.Friend_ID=p2.ID
    )
where P2.Salary>P1.Salary
order by P2.Salary
--https://www.hackerrank.com/challenges/placements/problem

select F1.X, F1.Y from Functions F1
inner join Functions F2 on F1.X=F2.Y and F1.Y=F2.X
group by F1.X, F1.Y
having count(F1.x)>1 or F1.X<F1.Y
order by F1.X
--https://www.hackerrank.com/challenges/symmetric-pairs/problem

select CON.contest_id, CON.hacker_id, CON.name, sum(total_submissions),
        sum(total_accepted_submissions), sum(total_views), sum(total_unique_views)
from Contests CON
join Colleges COL on CON.contest_id=COL.contest_id
join Challenges CHA on COL.college_id = CHA.college_id
left join
    (select challenge_id, sum(total_views) as total_views, sum(total_unique_views) as total_unique_views
     from View_Stats
     group by challenge_id) VS
     on CHA.challenge_id = VS.challenge_id
left join
    (select challenge_id, sum(total_submissions) as total_submissions, 
        sum(total_accepted_submissions) as total_accepted_submissions
     from Submission_Stats
     group by challenge_id) SS
     on CHA.challenge_id = SS.challenge_id
     
group by CON.contest_id, CON.hacker_id, CON.name
having sum(total_submissions)!=0 or sum(total_accepted_submissions)!=0 or
        sum(total_views)!=0 or sum(total_unique_views)!=0
order by contest_id
--https://www.hackerrank.com/challenges/interviews/problem

select submission_date,
    (select count(distinct hacker_id)
        from Submissions S2
        where S2.submission_date = S1.submission_date
            and (select count(distinct S3.submission_date) 
                    from Submissions S3
                    where S3.hacker_id = S2.hacker_id
                        and S3.submission_date < S1.submission_date) = dateDiff(S1.submission_date, '2016-03-01')
    ),
    (select hacker_id 
        from Submissions S2
        where S2.submission_date = S1.submission_date
     group by hacker_id
     order by count(submission_id) desc, hacker_id limit 1
    ) as data, 
    (select name
        from Hackers 
        where hacker_id=data
    )
from (select distinct submission_date from Submissions) S1
group by submission_date
--https://www.hackerrank.com/challenges/15-days-of-learning-sql/problem    

