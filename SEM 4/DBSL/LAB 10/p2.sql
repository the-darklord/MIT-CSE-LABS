set serveroutput on;
create or replace procedure dept_inst_courses(dname varchar) is
cursor inst is (select name from instructor where dept_name=dname);
cursor course is (select title from course where dept_name=dname);
begin
	dbms_output.put_line('Instructors');
	for i in inst loop
		dbms_output.put_line(i.name);
	end loop;
	dbms_output.put_line('Courses');
	for i in course loop
		dbms_output.put_line(i.title);
	end loop;
end;
/