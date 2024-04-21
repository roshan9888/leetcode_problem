# Write your MySQL query statement below
-- select P.project_id,round(avg(sum(experience_years)/sum(project_id)),2) as average_years
-- from Project P
-- left join Employee E
-- on P.employee_id=E.employee_id
-- group by P.project_id;

SELECT P.project_id, ROUND(AVG(E.experience_years), 2) AS average_years
FROM Project P
LEFT JOIN Employee E ON P.employee_id = E.employee_id
GROUP BY P.project_id;