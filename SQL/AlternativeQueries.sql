set @n=21;
select repeat('* ', @n:=@n-1) from information_schema.tables;
--https://www.hackerrank.com/challenges/draw-the-triangle-1/problem

set @n=0;
select repeat('* ', @n:=@n+1) from information_schema.tables
where @n<20;
--https://www.hackerrank.com/challenges/draw-the-triangle-2/problem

select group_concat(primes separator '&')
from(
    select @p:=@p+1 as primes 
    from information_schema.tables t1, information_schema.tables t2, (select @p:=1) as tmp 
) as tmpPrimes
where primes<=1000 
and not exists(
    select * from(
        select @n:=@n+1 as number
        from information_schema.tables t1, information_schema.tables t2, (select @n:=1) as tmpN
        limit 1000
    ) as numbers
    where floor(primes/number)=(primes/number) 
        and number<primes
        and number>1
)
--https://www.hackerrank.com/challenges/print-prime-numbers/problem?isFullScreen=true