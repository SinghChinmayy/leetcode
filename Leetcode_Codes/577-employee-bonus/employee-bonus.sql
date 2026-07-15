-- Write your PostgreSQL query statement below
select e.name as name, b.bonus as bonus
from Employee as e
left join bonus as b
on e.empId = b.empId
where b.bonus < 1000
or b.bonus is null;