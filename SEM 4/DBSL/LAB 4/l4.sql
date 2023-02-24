--Q1
select course_id,count(ID) from takes natural join course group by course_id;
/*

COURSE_I  COUNT(ID)
-------- ----------
HIS-351           1
EE-181            1
CS-101            7
CS-347            2
FIN-201           1
CS-319            2
BIO-101           1
PHY-101           1
CS-315            2
CS-190            2
MU-199            1
BIO-301           1
*/

--Q2
select dept_name,count(distinct ID) from takes natural join course group by dept_name having count(distinct ID)>10;
/*

no rows selected
*/

--Q3
select dept_name,count(course_id) from course group by dept_name;
/*

DEPT_NAME            COUNT(COURSE_ID)
-------------------- ----------------
Elec. Eng.                          1
Physics                             1
Comp. Sci.                          5
Finance                             1
Biology                             3
History                             1
Music                               1
*/

--Q4
 select dept_name,avg(salary) from instructor group by dept_name having avg(salary)>42000;
 /*
 
DEPT_NAME            AVG(SALARY)
-------------------- -----------
Elec. Eng.                 80000
Physics                    91000
Comp. Sci.            77333.3333
Finance                    85000
Biology                    72000
History                    61000
*/

--Q5
select course_id,sec_id,count(ID) from section natural join takes where semester='Spring' and year=2009 group by course_id,sec_id;
/*

COURSE_I SEC_ID    COUNT(ID)
-------- -------- ----------
EE-181   1                 1
CS-190   2                 2
*/

--Q6
select * from prereq order by course_id;
/*

COURSE_I PREREQ_I
-------- --------
BIO-301  BIO-101
BIO-399  BIO-101
CS-190   CS-101
CS-315   CS-101
CS-319   CS-101
CS-347   CS-101
EE-181   PHY-101
*/

--Q7
select * from instructor order by salary desc;
/*

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
22222 Einstein             Physics                   95000
83821 Brandt               Comp. Sci.                92000
12121 Wu                   Finance                   90000
33456 Gold                 Physics                   87000
98345 Kim                  Elec. Eng.                80000
76543 Singh                Finance                   80000
45565 Katz                 Comp. Sci.                75000
76766 Crick                Biology                   72000
10101 Srinivasan           Comp. Sci.                65000
58583 Califieri            History                   62000
32343 El Said              History                   60000
15151 Mozart               Music                     40000
*/

--Q8
select max(sal_sum) from (select sum(salary) sal_sum from instructor group by dept_name);
/*

MAX(SAL_SUM)
------------
      232000
*/

--Q9
select avg_sal from(select avg(salary) avg_sal,dept_name from instructor group by dept_name having avg(salary)>42000);
/*

   AVG_SAL
----------
     80000
     91000
77333.3333
     85000
     72000
     61000
*/

--Q10
select max(enrol) from (select course_id,sec_id,count(ID) enrol from section natural join takes where semester='Spring' and year=2009 group by course_id,sec_id);
/*

MAX(ENROL)
----------
         2
*/

--Q11
select distinct name from teaches, instructor where teaches.id = instructor.id and course_id in (select distinct course_id from takes,student where dept_name='Comp. Sci.' and student.id = takes.id);
/*

NAME
--------------------
Srinivasan
Brandt
Katz
*/

--Q12
 select sal_avg from(select avg(salary) sal_avg from instructor group by dept_name having avg(salary)>50000 and count(distinct id)>5);
/*

no rows selected
*/

--Q13
with max_bud(maxbud) as (select max(budget) maxbud from department) select budget from department,max_bud where budget=maxbud;
/*

    BUDGET
----------
    120000
*/

--Q14
with tot_sal(dept_name,tot) as (select dept_name,sum(salary) tot from instructor group by dept_name) , avg_tot_sal(avgtotsal) as (select avg(tot) from tot_sal) select dept_name,tot from tot_sal,avg_tot_sal where tot>avgtotsal;
/*

DEPT_NAME                   TOT
-------------------- ----------
Physics                  182000
Comp. Sci.               232000
Finance                  170000
*/

--Q15
with en_count(sec_id,encount) as (select sec_id,count(ID) enrol from section natural join takes where semester='Fall' and year=2009 group by sec_id) select sec_id,max(encount) from en_count group by sec_id;
/*

SEC_ID   MAX(ENCOUNT)
-------- ------------
1                   9
*/

--Q16
with Fin_TotCred(totcred) as (select tot_cred from student where dept_name='Finance') select dept_name,sum(tot_cred) from student,Fin_TotCred group by dept_name having sum(tot_cred)> sum(totcred);
/*

DEPT_NAME            SUM(TOT_CRED)
-------------------- -------------
Biology                        120
*/

--Q17
delete from instructor where dept_name = 'Finance';

--Q18
delete from course where dept_name='Comp. Sci.';

--Q19
update student set dept_name ='IT' where dept_name = 'Comp. Sci';

--Q20
update instructor set salary=
case
when salary<=100000 then salary*1.05
else salary*1.03
end

--OR

update instructor set salary=salary*1.03 where salary>100000;
update instructor set salary=salary*1.03 where salary<=100000;

--Q21
insert into student select ID,name,dept_name,0 from instructor;

--Q22
delete from instructor where salary < (select avg(salary) from instructor);