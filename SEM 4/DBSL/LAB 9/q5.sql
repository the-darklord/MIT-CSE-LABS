set serveroutput on
declare
cursor c is (select * from studenttable) for update;
grade studenttable.lettergrade%TYPE;
begin
	for i in c loop
		update studenttable
		set lettergrade='F'
		where current of c;
	end loop;
	for i in c loop
		if i.gpa between 0 and 4 then grade :='F';
		elsif i.gpa between 4 and 5 then grade :='E';
		elsif i.gpa between 5 and 6 then grade :='D';
		elsif i.gpa between 6 and 7 then grade :='C';
		elsif i.gpa between 7 and 8 then grade :='B';
		elsif i.gpa between 8 and 9 then grade :='A';
		else grade :='A+';
		end if;
		update studenttable
		set lettergrade=grade
		where current of c;
	end loop;
end;
/