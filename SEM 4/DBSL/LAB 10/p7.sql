set serveroutput on;
create or replace package q7 as
procedure dept_inst(dname varchar);

function dept_highest(dname varchar) 
return number;
end q7;
/

create or replace package body q7 as
procedure dept_inst(dname varchar) is
cursor inst is (select name from instructor where dept_name=dname);
begin
	dbms_output.put_line('Instructors');
	for i in inst loop
		dbms_output.put_line(i.name);
	end loop;
end;

function dept_highest(dname varchar) 
return number as
inst_max number;
begin
	select max(salary) into inst_max from instructor where dept_name=dname;
	return inst_max;
end;
end q7;
/