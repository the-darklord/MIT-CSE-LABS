set serveroutput on;
create or replace procedure dept_student_courses(dname varchar) is
cursor stud is (select name from student where dept_name=dname);
cursor course is (select title from course where dept_name=dname);
begin
	dbms_output.put_line('Students');
	for i in stud loop
		dbms_output.put_line(i.name);
	end loop;
	dbms_output.put_line('Courses');
	for i in course loop
		dbms_output.put_line(i.title);
	end loop;
end;
/