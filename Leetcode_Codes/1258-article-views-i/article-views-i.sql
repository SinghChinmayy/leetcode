-- Write your PostgreSQL query statement below
select distinct author_id as id from views
where views.author_id = views.viewer_id;