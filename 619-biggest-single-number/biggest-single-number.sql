# Write your MySQL query statement below
select max(num) as num
from mynumbers
where (num) in (
   select distinct num
   from mynumbers
   group by num
   having count(*)=1
)
