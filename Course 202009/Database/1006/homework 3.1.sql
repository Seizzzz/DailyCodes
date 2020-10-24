--3.1 a
select course_id
from course
where dept_name = "Comp. Sci." and credits = 3;

--3.1 b
select ID
from student natural join takes
where course_id in(select course_id from teaches natural join instructor where name = "Einstein");

--3.1 c
select max(salary)
from instructor;

--3.1 d
select name
from instructor
where salary in(select max(salary) from instructor);

--3.1 e
select course_id, sec_id, count(name)
from student natural join takes
where year = "2009" and semester = "Fall"
group by course_id, sec_id;

--3.1 f
select count(name) as cnt
from student natural join takes
where year = "2009" and semester = "Fall"
group by course_id, sec_id
order by cnt desc limit 1;

--3.1 g
select course_id, sec_id
from student natural join takes
where year = "2009" and semester = "Fall"
group by course_id, sec_id
order by count(name) desc limit 1