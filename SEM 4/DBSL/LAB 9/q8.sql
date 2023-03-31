set serveroutput on
declare
cursor c is (select * from instructor where dept_name='Biology');
sal instructor.salary%TYPE := 0;
bud department.budget%TYPE;
begin
	select budget into bud from department where dept_name='Biology';
	savepoint original;
	update instructor set salary=salary*1.2 where dept_name='Biology';
	for i in c loop
		sal := sal + i.salary;
	end loop;
	if sal > bud then rollback to original;
	else commit;
	end if;
end;
/