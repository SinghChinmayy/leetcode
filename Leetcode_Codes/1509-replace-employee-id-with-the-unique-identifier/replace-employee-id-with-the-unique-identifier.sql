-- Write your PostgreSQL query statement below
select t2.unique_id, t1.name
from Employees as t1
LEFT JOIN EmployeeUNI as t2
ON t1.id = t2.id;