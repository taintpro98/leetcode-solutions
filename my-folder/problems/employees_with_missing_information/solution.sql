# Write your MySQL query statement below
select employees.employee_id
from employees 
left join salaries on employees.employee_id = salaries.employee_id
where salary is null
union
select salaries.employee_id
from employees
right join salaries on employees.employee_id = salaries.employee_id
where name is null
order by employee_id asc