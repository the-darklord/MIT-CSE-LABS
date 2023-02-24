--Q1

(select course_id,title from course natural join section where semester='Fall' and year=2009)
union all
(select course_id,title from course natural join section where semester='Spring' and year=2010);
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-101   Intro. to Computer Science
CS-315   Robotics
CS-319   Image Processing
CS-319   Image Processing
CS-347   Database System Concepts
FIN-201  Investment Banking
HIS-351  World History
MU-199   Music Video Production
PHY-101  Physical Principles
*/

--Q2

(select course_id,title from course natural join section where semester='Fall' and year=2009)
intersect
(select course_id,title from course natural join section where semester='Spring' and year=2010);
/*


COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/

--Q3

(select course_id,title from course natural join section where semester='Fall' and year=2009)
minus
(select course_id,title from course natural join section where semester='Spring' and year=2010);
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-347   Database System Concepts
PHY-101  Physical Principles
*/

--Q4

(select course_id from course)
minus
(select course_id from takes);
/*

COURSE_I
--------
BIO-399
*/

--Q5

select course_id,title from course natural join section where semester='Fall' and year=2009 and course_id in
(select course_id from course natural join section where semester='Spring' and year=2010);
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/

--Q6

select count(distinct id) total from takes t where course_id in (select course_id from teaches where id=10101);
/*

     TOTAL
----------
        6
*/

--Q7

select course_id,title from course natural join section where semester='Fall' and year=2009 and course_id not in
(select course_id from course natural join section where semester='Spring' and year=2010);
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-347   Database System Concepts
PHY-101  Physical Principles
*/

--Q8

select name from student where name in 
(select name from instructor);
/*
NAME
--------------------
Brandt
*/

--Q9

select name,dept_name from instructor where salary > some (select salary from instructor where dept_name='Biology');
/*

NAME                 DEPT_NAME
-------------------- --------------------
Einstein             Physics
Brandt               Comp. Sci.
Wu                   Finance
Gold                 Physics
Kim                  Elec. Eng.
Singh                Finance
Katz                 Comp. Sci.
*/

--Q10

select name,dept_name from instructor where salary > all (select salary from instructor where dept_name='Biology');
/*

NAME                 DEPT_NAME
-------------------- --------------------
Katz                 Comp. Sci.
Singh                Finance
Kim                  Elec. Eng.
Gold                 Physics
Wu                   Finance
Brandt               Comp. Sci.
Einstein             Physics
*/

--Q11

select dept_name,avg(salary) Avg_Sal from instructor group by dept_name having avg(salary) >= all (select avg(salary) from instructor group by dept_name);
/*

DEPT_NAME               AVG_SAL
-------------------- ----------
Physics                   91000
*/

--Q12

select dept_name from department where budget < all (select avg(salary) from instructor);
/*

DEPT_NAME
--------------------
History
Physics
*/

--Q13

select c.course_id,c.title from course c,section s where c.course_id=s.course_id and s.semester='Fall' and s.year=2009 and exists
(select * from section s where c.course_id=s.course_id and s.semester='Spring' and s.year=2010);
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/

--Q14

select s.name from student s where exists(select * from takes t where s.id=t.id and s.dept_name='Biology');
/*

NAME
--------------------
Tanaka

*/

--Q15

select unique course_id from course c where 1>=(select count(course_id) from section s where c.course_id=s.course_id and year=2009 group by course_id);
/*

COURSE_I
--------
BIO-101
CS-101
CS-347
EE-181
PHY-101
*/

--Q16

select name,dept_name from student s where 2<=(select count(id) from takes t where s.id=t.id and s.dept_name='Comp. Sci.' group by id);
/*

NAME                 DEPT_NAME
-------------------- --------------------
Zhang                Comp. Sci.
Shankar              Comp. Sci.
Williams             Comp. Sci.
Brown                Comp. Sci.
*/

--Q17

select dept_name,AVG_SAL from (select dept_name,avg(salary) AVG_SAL from instructor group by dept_name having avg(salary)>42000);
/*

DEPT_NAME               AVG_SAL
-------------------- ----------
Elec. Eng.                80000
Physics                   91000
Comp. Sci.           77333.3333
Finance                   85000
Biology                   72000
History                   61000
*/

--Q18
create view Phy_Dept as select building,room_number from section natural join course where dept_name='Physics' and semester='Fall' and year=2009;

--Q19
 select * from Phy_Dept;
 /*
 
BUILDING        ROOM_NU
--------------- -------
Watson          100
 */
 
 --Q20
 create view dept_tot_sal as select dept_name,sum(salary) tot_salary from instructor group by dept_name;
 select * from dept_tot_sal;
 /*
 
DEPT_NAME            TOT_SALARY
-------------------- ----------
Elec. Eng.                80000
Physics                  182000
Comp. Sci.               232000
Finance                  170000
Biology                   72000
Music                     40000
History                  122000

 */