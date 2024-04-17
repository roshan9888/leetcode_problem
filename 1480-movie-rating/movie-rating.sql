# Write your MySQL query statement below


(select name as results from MovieRating as m 
left join Users as u
on m.user_id = u.user_id
group by u.name
order by count(distinct m.movie_id) desc, u.name limit 1)
union all
(select mo.title from MovieRating as m
left join Movies as mo
on m.movie_id = mo.movie_id
where date_format(created_at, '%Y-%m') = '2020-02'
group by m.movie_id 
order by avg(m.rating) desc, mo.title limit 1
);