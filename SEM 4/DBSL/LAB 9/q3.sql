set serveroutput on
declare
cursor c is (select course_id,title,dept_name,credits,name,building,room_number,time_slot_id,count from(select course_id,title,dept_name,credits,name,sec_id,semester,year,count from (select ID,name,course_id,sec_id,semester,year,count from (select course_id,sec_id,semester,year,tt.ID,count(distinct t.ID) count from takes t join teaches tt using(course_id,sec_id,semester,year) group by course_id,sec_id,semester,year,tt.ID) join instructor using(ID)) join course using(course_id)) join section using(course_id,sec_id,semester,year));
begin
	for i in c loop
		dbms_output.put_line('-----------------------------------------------------------------------------');
		dbms_output.put_line(i.course_id||'|'||i.title||'|'||i.dept_name||'|'||i.credits||'|'||i.name||'|'||i.building||'|'||i.room_number||'|'||i.time_slot_id||'|'||i.count);
		dbms_output.put_line('-----------------------------------------------------------------------------');
	end loop;
end;
/