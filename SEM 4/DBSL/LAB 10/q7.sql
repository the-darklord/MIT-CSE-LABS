set serveroutput on;
declare
cursor c is (select dept_name from department);
begin
	for i in c loop
		q7.dept_inst(i.dept_name);
		dbms_output.put_line('Maximum Salary of '||i.dept_name||' is '||q7.dept_highest(i.dept_name));
	end loop;
end;
/