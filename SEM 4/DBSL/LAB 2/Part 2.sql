--Q9
select name,dept_name from student;
/*
NAME                 DEPT_NAME
-------------------- --------------------
Zhang                Comp. Sci.
Shankar              Comp. Sci.
Brandt               History
Chavez               Finance
Peltier              Physics
Levy                 Physics
Williams             Comp. Sci.
Sanchez              Music
Snow                 Physics
Brown                Comp. Sci.
Aoi                  Elec. Eng.
Bourikas             Elec. Eng.
Tanaka               Biology
*/

--Q10
select * from instructor where dept_name='Comp. Sci.';
/*

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
45565 Katz                 Comp. Sci.                75000
83821 Brandt               Comp. Sci.                92000

*/

--Q11
select title from course where dept_name='Comp. Sci.' and credits=3;
/*

TITLE
--------------------------------------------------
Robotics
Image Processing
Database System Concepts
*/

--Q12
select course_id,title from takes natural join course where id=12345;
/*

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-190   Game Design
CS-315   Robotics
CS-347   Database System Concepts
*/

--Q13
select * from instructor where salary between 40000 and 90000;
/*

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
12121 Wu                   Finance                   90000
15151 Mozart               Music                     40000
32343 El Said              History                   60000
33456 Gold                 Physics                   87000
45565 Katz                 Comp. Sci.                75000
58583 Califieri            History                   62000
76543 Singh                Finance                   80000
76766 Crick                Biology                   72000
98345 Kim                  Elec. Eng.                80000
*/

--Q14
select id from instructor where id not in (select distinct id from teaches);
/*

ID
-----
33456
58583
76543
*/

--Q15
select s.name,c.title,sec.year from student s , course c,section sec where sec.room_number=303;
/*

no rows selected
*/

--Q16
select s.name,t.course_id,c.title c_name from student s,course c,takes t where t.id=s.id and c.course_id=t.course_id and t.year=2015;
/*

no rows selected
*/

select s.name,t.course_id,c.title c_name from student s,course c,takes t where t.id=s.id and c.course_id=t.course_id and t.year=2009;
/*

NAME                 COURSE_I C_NAME
-------------------- -------- --------------------------------------------------
Tanaka               BIO-101  Intro. to Biology
Bourikas             CS-101   Intro. to Computer Science
Brown                CS-101   Intro. to Computer Science
Williams             CS-101   Intro. to Computer Science
Levy                 CS-101   Intro. to Computer Science
Shankar              CS-101   Intro. to Computer Science
Zhang                CS-101   Intro. to Computer Science
Williams             CS-190   Game Design
Shankar              CS-190   Game Design
Shankar              CS-347   Database System Concepts
Zhang                CS-347   Database System Concepts

NAME                 COURSE_I C_NAME
-------------------- -------- --------------------------------------------------
Aoi                  EE-181   Intro. to Digital Systems
Peltier              PHY-101  Physical Principles
*/

--Q17
select name,salary inst_salary from instructor where salary >( select min(salary) from instructor where dept_name='Comp. Sci.');
/*

NAME                 INST_SALARY
-------------------- -----------
Wu                         90000
Einstein                   95000
Gold                       87000
Katz                       75000
Singh                      80000
Crick                      72000
Brandt                     92000
Kim                        80000
*/

--Q18
select name,dept_name from instructor where dept_name like '%ch%';
/*

no rows selected

*/

select name,dept_name from instructor where dept_name like '%st%';
/*

NAME                 DEPT_NAME
-------------------- --------------------
El Said              History
Califieri            History
*/

--Q19
select name,length(name) name_length from student;
/*

NAME                 NAME_LENGTH
-------------------- -----------
Zhang                          5
Shankar                        7
Brandt                         6
Chavez                         6
Peltier                        7
Levy                           4
Williams                       8
Sanchez                        7
Snow                           4
Brown                          5
Aoi                            3
Bourikas                       8
Tanaka                         6
*/

--Q20
select dept_name,substr(dept_name,3,3) char_3 from department; 
/*

DEPT_NAME            CHA
-------------------- ---
Biology              olo
Comp. Sci.           mp.
Elec. Eng.           ec.
Finance              nan
History              sto
Music                sic
Physics              ysi

*/

--Q21
select upper(name) from instructor;
/*

UPPER(NAME)
--------------------
SRINIVASAN
WU
MOZART
EINSTEIN
EL SAID
GOLD
KATZ
CALIFIERI
SINGH
CRICK
BRANDT
KIM
*/

--Q22
update department set budget=10000 where budget=NULL;
/*

0 rows updated.
*/

--Q23
select salary,round(salary/3,-2) rounded from instructor;
/*

    SALARY    ROUNDED
---------- ----------
     65000      21700
     90000      30000
     40000      13300
     95000      31700
     60000      20000
     87000      29000
     75000      25000
     62000      20700
     80000      26700
     72000      24000
     92000      30700
     80000      26700
*/



