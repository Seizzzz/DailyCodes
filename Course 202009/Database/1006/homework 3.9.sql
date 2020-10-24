--3.9 a
select employee_name, city
from employee natural join works
where company_name = "First Bank Corporation";

--3.9 b
select employee_name, street, city
from employee natural join works
where company_name = "First Bank Corporation" and salary > 10000;

--3.9 c
select employee_name
from employee natural join works
where company_name != "First Bank Corporation"

--3.9 d
select employee_name
from employee, (select max(salary) as mx from employee natural join works where company_name = "Small Bank Corporation") as tmp
where salary > tmp.mx

--3.9 e
select distinct company_name
from company, (select distinct city from company where company_name = "Small Bank Corporation") as city_at
where city in tmp;

--3.9 f
select company_name
from works
group by company_name
order by count(employee_name) desc limit 1;

--3.9 g
select company_name
from (select company_name, avg(salary) as num from works group by company_name) as tmp1, (select avg(salary) as std from works where company_name = "First Bank Corporation") as tmp2
where tmp1.num > tmp2.std;