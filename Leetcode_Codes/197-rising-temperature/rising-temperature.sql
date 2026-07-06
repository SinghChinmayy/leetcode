-- Write your PostgreSQL query statement below
select w1.id
from weather as w1
join weather as w2
on w1.recordDate = w2.recordDate + INTERVAL '1 Day' and w2.temperature < w1.temperature;
