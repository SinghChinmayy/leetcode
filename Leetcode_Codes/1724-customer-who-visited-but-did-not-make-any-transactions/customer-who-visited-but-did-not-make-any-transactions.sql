-- Write your PostgreSQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans
from visits as v
left join Transactions as t
on v.visit_id = t.visit_id
where t.transaction_id is NULL
group by v.customer_id;
