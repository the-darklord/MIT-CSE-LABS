--Q1
select bdate,address from employee where fname ='John' and minit='B' and lname='Smith';
/*
BDATE     ADDRESS
--------- ------------------------------
09-JAN-65 731 Fondren, Houston, TX
*/

select fname,minit,lname,address from employee e,department d where e.dno=d.dnumber and dname='Research';

/*


FNAME           M LNAME           ADDRESS
--------------- - --------------- ------------------------------
John            B Smith           731 Fondren, Houston, TX
Franklin        T Wong            638 Voss, Houston, TX
Ramesh          K Narayan         975 Fire Oak, Humble, TX
Joyce           A English         5631 Rice, Houston, TX
*/

--Q2
select pnumber,dnumber,lname,address,bdate from employee e, department d,project p where e.dno=d.dnumber and p.dnum=d.dnumber and d.mgr_ssn = employee.ssn and plocation='Stafford';

/*
   PNUMBER    DNUMBER LNAME           ADDRESS                        BDATE
---------- ---------- --------------- ------------------------------ ---------
        10          4 Wallace         291 Berry, Bellaire, TX        20-JUN-41
*/

--Q3
select distinct salary from employee;

/*
    SALARY
----------
     38000
     43000
     55000
     30000
     40000
     25000
     37000
*/

--Q4
select e.fname,e.lname,s.fname,s.lname from employee e,employee s where e.super_ssn=s.ssn;
/*

FNAME           LNAME           FNAME           LNAME
--------------- --------------- --------------- ---------------
Richard         Marini          Richard         Marini
Joyce           English         Franklin        Wong
Ramesh          Narayan         Franklin        Wong
John            Smith           Franklin        Wong
Ahmad           Jabbar          Jennifer        Wallace
Alicia          Zelaya          Jennifer        Wallace
Jennifer        Wallace         James           Borg
Franklin        Wong            James           Borg

*/
--Q5
select pnumber from project,employee where lname='Smith';

/*
   PNUMBER
----------
         1
         2
         3
        10
        20
        30
*/

--Q6
select * from employee where address like '%Houston%';

/*
FNAME           M LNAME           SSN       BDATE
--------------- - --------------- --------- ---------
ADDRESS                        S     SALARY SUPER_SSN        DNO
------------------------------ - ---------- --------- ----------
John            B Smith           123456789 09-JAN-65
731 Fondren, Houston, TX       M      30000 333445555          5

Franklin        T Wong            333445555 08-DEC-65
638 Voss, Houston, TX          M      40000 888665555          5

Joyce           A English         453453453 31-JUL-72
5631 Rice, Houston, TX         F      25000 333445555          5


FNAME           M LNAME           SSN       BDATE
--------------- - --------------- --------- ---------
ADDRESS                        S     SALARY SUPER_SSN        DNO
------------------------------ - ---------- --------- ----------
Ahmad           V Jabbar          987987987 29-MAR-69
980 Dallas, Houston, TX        M      25000 987654321          4

James           E Borg            888665555 10-NOV-37
450 Stone, Houston, TX         M      55000                    4
*/

--Q7
select fname,salary*1.1 from employee e,department d,project p where pname='ProductX' and e.dno=d.dnumber and d.dnumber=p.dnum;
/*

FNAME           SALARY*1.1
--------------- ----------
John                 33000
Franklin             44000
Ramesh               41800
Joyce                27500
*/

--Q8
select * from employee e,department d where e.dno=d.dnumber and dnumber=5 and salary between 30000 and 40000;
/*

FNAME           M LNAME           SSN       BDATE
--------------- - --------------- --------- ---------
ADDRESS                        S     SALARY SUPER_SSN        DNO DNAME
------------------------------ - ---------- --------- ---------- ---------------
   DNUMBER MGR_SSN   MGR_START
---------- --------- ---------
John            B Smith           123456789 09-JAN-65
731 Fondren, Houston, TX       M      30000 333445555          5 Research
         5 333445555 22-MAY-88

Franklin        T Wong            333445555 08-DEC-65
638 Voss, Houston, TX          M      40000 888665555          5 Research
         5 333445555 22-MAY-88

FNAME           M LNAME           SSN       BDATE
--------------- - --------------- --------- ---------
ADDRESS                        S     SALARY SUPER_SSN        DNO DNAME
------------------------------ - ---------- --------- ---------- ---------------
   DNUMBER MGR_SSN   MGR_START
---------- --------- ---------

Ramesh          K Narayan         666884444 15-SEP-62
975 Fire Oak, Humble, TX       M      38000 333445555          5 Research
         5 333445555 22-MAY-88
*/

--Q9
select e.fname,e.minit,e.lname,p.pname from employee e,project p,department d where e.dno=p.dnum and e.dno=d.dnumber and p.dnum=d.dnumber order by d.dname,e.lname,e.fname;
/*

FNAME           M LNAME           PNAME
--------------- - --------------- ---------------
James           E Borg            Computerization
James           E Borg            Newbenefits
Ahmad           V Jabbar          Newbenefits
Ahmad           V Jabbar          Computerization
Richard         K Marini          Newbenefits
Richard         K Marini          Computerization
Jennifer        S Wallace         Newbenefits
Jennifer        S Wallace         Computerization
Alicia          J Zelaya          Newbenefits
Alicia          J Zelaya          Computerization
Joyce           A English         ProductZ

FNAME           M LNAME           PNAME
--------------- - --------------- ---------------
Joyce           A English         ProductY
Joyce           A English         ProductX
Ramesh          K Narayan         ProductX
Ramesh          K Narayan         ProductZ
Ramesh          K Narayan         ProductY
John            B Smith           ProductZ
John            B Smith           ProductY
John            B Smith           ProductX
Franklin        T Wong            ProductZ
Franklin        T Wong            ProductY
Franklin        T Wong            ProductX
*/

--Q10
select ssn,fname,minit,lname from employee where super_ssn is null;
/*

SSN       FNAME           M LNAME
--------- --------------- - ---------------
888665555 James           E Borg
*/

--Q11
select fname,minit,lname from employee e,dependent d where e.fname=d.dependent_name and e.sex=d.sex;
/*

no rows selected
*/

--Q12
select fname from employee where ssn not in (select essn from dependent);
/*

FNAME
---------------
Richard
Ahmad
Alicia
James
Joyce
Ramesh
*/

--Q13
select distinct fname from employee e,department d ,dependent dd where d.mgr_ssn=dd.essn and dd.essn=e.ssn;
/*

FNAME
---------------
Franklin
Jennifer
*/

--Q14
select fname,ssn,pnumber from employee e,project p where e.dno=p.dnum and p.pnumber in (1,2,3);
/*

FNAME           SSN          PNUMBER
--------------- --------- ----------
John            123456789          3
John            123456789          2
John            123456789          1
Franklin        333445555          3
Franklin        333445555          2
Franklin        333445555          1
Ramesh          666884444          3
Ramesh          666884444          2
Ramesh          666884444          1
Joyce           453453453          3
Joyce           453453453          2

FNAME           SSN          PNUMBER
--------------- --------- ----------
Joyce           453453453          1
*/

--Q15
select sum(salary) Sum,max(salary) Max,min(salary) Min,avg(salary) Avg from employee;
/*

       SUM        MAX        MIN        AVG
---------- ---------- ---------- ----------
    318000      55000      25000 35333.3333
*/

--Q16
with  Res_Dept_Sal(sal) as (select salary from employee e,department d where e.dno=d.dnumber and d.dname='Research') select sum(sal),max(sal),min(sal),avg(sal) from Res_Dept_Sal; 
/*

  SUM(SAL)   MAX(SAL)   MIN(SAL)   AVG(SAL)
---------- ---------- ---------- ----------
    133000      40000      25000      33250
*/

--Q17
select pnumber,pname,count(distinct ssn) from employee e, project p where e.dno=p.dnum group by pnumber,pname;
/*

   PNUMBER PNAME           COUNT(DISTINCTE.SSN)
---------- --------------- --------------------
        10 Computerization                    5
        30 Newbenefits                        5
         1 ProductX                           4
         2 ProductY                           4
         3 ProductZ                           4
*/

--Q18
select pnumber,pname,count(distinct ssn) from employee e, project p where e.dno=p.dnum group by pnumber,pname having count(distinct ssn)>2;
/*

   PNUMBER PNAME           COUNT(DISTINCTSSN)
---------- --------------- ------------------
        30 Newbenefits                      5
         2 ProductY                         4
        10 Computerization                  5
         1 ProductX                         4
         3 ProductZ                         4
*/

--Q19
select dnumber,count(distinct ssn) from employee e, department d where e.dno=d.dnumber and salary>40000 group by dnumber having count(distinct ssn)>5;
/*

no rows selected
*/
