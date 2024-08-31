# Write your MySQL query statement below
-- select d.name as Department,e.name as Employee,e.salary as salary,
-- dense_rank() over (partition by e.departmentId order by e.salary desc) as rn
-- from employee e 
-- join department d
-- on e.departmentId=d.id

SELECT 
    d.name AS Department,
    rs.name AS Employee,
    rs.salary AS Salary
FROM 
    (SELECT 
        e.name, 
        e.salary, 
        e.departmentId, 
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rn
    FROM 
      employee e
    ) rs
JOIN 
    department d 
ON 
    rs.departmentId = d.id
WHERE 
    rs.rn <= 3;