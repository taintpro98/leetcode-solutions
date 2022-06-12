# Write your MySQL query statement below
# select employee_id, salary as bonus
# from employees
# where employee_id in 
# (
#     select employee_id
#     from employees
#     where mod(employee_id, 2) = 1 and substring(name, 1, 1) != 'M'
# ) 
# union
# select employee_id, 0 as bonus
# from employees
# where employee_id not in
# (
#     select employee_id
#     from employees
#     where mod(employee_id, 2) = 1 and substring(name, 1, 1) != 'M'
# ) 
select employee_id,
case when name not like 'M%' and employee_id%2 != 0 then salary else 0 end as bonus
from employees
order by employee_id