# Write your MySQL query statement below

select coalesce(round(sum(1)/(select count(distinct player_id) from activity),2) ,0)as fraction
from activity a1
join activity a2
on a1.player_id=a2.player_id
and date_sub(a1.event_date,interval 1 day)=a2.event_date
where (a2.player_id, a2.event_date )
in
(select
    player_id, min(event_date)
    from
    activity
    group by player_id
)
;
