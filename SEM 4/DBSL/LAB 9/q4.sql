set serveroutput on
declare
cursor c is (select * from student natural join takes where course_id='CS101' and tot_cred<30);
begin
	for i in c loop
		delete from takes where id=i.id and course_id=i.course_id;
		dbms_output.put_line(c%ROWCOUNT||' rows affected');
	end loop;
end;
/