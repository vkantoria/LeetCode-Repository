# Write your MySQL query statement below
  select distinct email as Email from Person where email in(select  email  from Person group by email having count(email)>1);