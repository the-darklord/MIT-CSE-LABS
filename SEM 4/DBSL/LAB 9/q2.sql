set serveroutput on
declare
cursor c is (select * from(select * from student order by tot_cred));
begin
	for i in c loop
		if c%ROWCOUNT>10 then exit;
		end if;
		dbms_output.put_line('ID : '||i.ID||'  Name : '||i.name||'  Department Name : '||i.dept_name||'  Total Credits : '||i.tot_cred);
	end loop;
end;
/