set serveroutput on
declare
cid teaches.course_id%TYPE;
cursor c is (select * from teaches natural join instructor where course_id=cid);
begin
	cid :='&Course_Id';
	for i in c loop
		dbms_output.put_line(i.ID||'   '||i.name);
	end loop;
end;
/