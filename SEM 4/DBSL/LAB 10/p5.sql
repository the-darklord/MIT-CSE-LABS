set serveroutput on;
create or replace function sqr(num number) 
return number as
begin
	return num*num;
end;
/