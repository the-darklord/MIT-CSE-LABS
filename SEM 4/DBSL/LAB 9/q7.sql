set serveroutput on
declare
cursor c is (select distinct name from (select t.id from takes t,advisor a,teaches tt where a.s_id=t.id and a.i_id=tt.id) join student using (id));
begin
	for i in c loop
		dbms_output.put_line(i.name);
	end loop;
end;
/