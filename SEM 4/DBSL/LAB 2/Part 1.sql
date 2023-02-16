--Q1
create table employee(
				EmpNo number(5) primary key,
				EmpName varchar(20) not null,
				Gender varchar(1) not null,
				Salary number(10) not null,
				Address varchar(20) not null
				);
				
alter table employee add (DNo number(5));
alter table employee add check(Gender in ('M','F'));

--Q2
create table department(
						DeptNo number(5) primary key,
						DeptName varchar(15) unique not null
						);

--Q3
alter table department add (Location varchar(20));
alter table employee add constraint FK_DNo foreign key(DNo) references department(DeptNo);

--Q4
insert into department values(1,'Account','Kurnool');
insert into department values(2,'Production','Manipal');
insert into department values(3,'Marketing','Coimbatore');
insert into department values(4,'Branch','Mangalore');
insert into department values(5,'Management','Mumbai');

insert into employee values(1,'Mihir','M',10000,'Kurnool',1);
insert into employee values(2,'Jithin','M',20000,'Coimbatore',3);
insert into employee values(3,'Prerana','F',5000,'Manipal',2);
insert into employee values(4,'Taksh','M',10000,'Mumbai',5);
insert into employee values(5,'Kamya','F',5000,'Mangalore',4);

--Q5
insert into department values(5,'Research','Hyderabad');
/*OP:-
insert into department values(5,'Research','Hyderabad')
*
ERROR at line 1:
ORA-00001: unique constraint (DBL57.SYS_C00183494) violated */

insert into employee values(6,'Hruthik','J',5000,'Kurnool',1);
/*OP:-
insert into employee values(6,'Hruthik','J',5000,'Kurnool',1)
*
ERROR at line 1:
ORA-02290: check constraint (DBL57.SYS_C00183730) violated */

--Q6
delete from department where DeptNo=5;
/*OP:-
delete from department where DeptNo=5
*
ERROR at line 1:
ORA-02292: integrity constraint (DBL57.FK_DNO) violated - child record found */

--Q7
alter table employee drop constraint FK_DNo;
alter table employee add constraint FK_DNo foreign key(DNo) references department(DeptNo) on delete cascade;

--Q8
alter table employee modify (constraint DEF_SALARY Salary default 10000);

insert into employee(EmpNo,EmpName,Gender,Address,DNo) values(6,'Krishna','M','Kurnool',1);

rename department to tdl;

/*

     EMPNO EMPNAME              G     SALARY ADDRESS                     DNO
---------- -------------------- - ---------- -------------------- ----------
         1 Mihir                M      10000 Kurnool                       1
         2 Jithin               M      20000 Coimbatore                    3
         3 Prerana              F       5000 Manipal                       2
         4 Taksh                M      10000 Mumbai                        5
         5 Kamya                F       5000 Mangalore                     4
         6 Krishna              M      10000 Kurnool                       1

*/

/*

    DEPTNO DEPTNAME        LOCATION
---------- --------------- --------------------
         1 Account         Kurnool
         2 Production      Manipal
         3 Marketing       Coimbatore
         4 Branch          Mangalore
         5 Management      Mumbai
*/






--Q24

alter table employee add (DOB date);
update employee set DOB='25-SEP-2003';
insert into employee values(7,'Sharel','F',10000,'Udupi',2,'12-FEB-2003');

select to_date(DOB,'DD-MON-YYYY') DOB from employee;
select to_date(DOB,'DD-MON-YY') DOB from employee;
select to_date(DOB,'DD-MM-YY') DOB from employee;

--Q25

select empname,to_char(DOB,'YEAR') DOB from employee;
select empname,to_char(DOB,'Year') DOB from employee;
select empname,to_char(DOB,'year') DOB from employee;

--Q26

select empname,to_char(DOB,'DAY') DOB from employee;
select empname,to_char(DOB,'Day') DOB from employee;

--Q27

select empname,to_char(DOB,'MONTH') DOB from employee;
select empname,to_char(DOB,'Month') DOB from employee;

--Q28

select last_day(DOB) DOB from employee;

--Q29

select round(months_between('16-FEB-2023',DOB)/12) AGE from employee;

--Q30

select next_day(DOB,'SATURDAY') NEXT_SAT from employee;

--Q31

select * from employee where to_char(DOB,'YYYY')='2003';

--Q32

select * from employee where cast(to_char(DOB,'YYYY') as int) between 2002 and 2004;

--Q33

select * from employee where round(months_between(cast(&X as date),DOB)/12)>=60;













