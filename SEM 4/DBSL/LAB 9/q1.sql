set serveroutput on
declare
dname department.dept_name%TYPE;
cursor c is (select * from instructor where dept_name=dname) for update;
begin
	dname :='&Department_Name';
	for i in c loop
		insert into salary_raise values(i.ID,current_date,(i.salary*1.05)-i.salary);
		update instructor
		set salary=salary*1.05
		where current of c;
		dbms_output.put_line(c%ROWCOUNT || ' rows updated');
	end loop;
end;
/