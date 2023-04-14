set serveroutput on;
create or replace function dept_highest(dname varchar) 
return number as
inst_max number;
begin
	select max(salary) into inst_max from instructor where dept_name=dname;
	return inst_max;
end;
/