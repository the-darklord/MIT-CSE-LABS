set serveroutput on
declare
issue_d date;
return_d date;
days number(10);
fine number(10);
begin

issue_d :='&issue_date';
return_d :='&return_date';
days := return_d-issue_d;

if days>=0 and days<=7 then fine := 0;
elsif days>=7 and days<=15 then fine := days*1;
elsif days>=16 and days<=30 then fine := days*2;
else fine := days*5;
end if;

dbms_output.put_line('Fine is '||fine);

end;
/