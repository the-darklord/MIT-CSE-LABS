set serveroutput on
declare
num number;
begin
	num := '&Number';
	dbms_output.put_line('Square of '||num||' is '||sqr(num));
end;
/