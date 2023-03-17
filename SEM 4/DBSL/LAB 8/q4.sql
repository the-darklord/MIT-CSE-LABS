set serveroutput on
declare
grade char(2);
x number := 0;
pl_gpa StudentTable.gpa%TYPE;
begin

loop

x := x+1;

if x > 5 then exit;
end if;

select gpa into pl_gpa
from StudentTable
where rollno=x;

if pl_gpa>=0 and pl_gpa<4 then grade :='F';
elsif pl_gpa>=4 and pl_gpa<5 then grade :='E';
elsif pl_gpa>=5 and pl_gpa<6 then grade :='D';
elsif pl_gpa>=6 and pl_gpa<7 then grade :='C';
elsif pl_gpa>=7 and pl_gpa<8 then grade :='B';
elsif pl_gpa>=8 and pl_gpa<9 then grade :='A';
else grade :='A+';
end if;
dbms_output.put_line('Grade for '||pl_gpa||' is '||grade);


end loop;
end;
/

/*
Grade for 5.8 is D
Grade for 6.5 is C
Grade for 3.4 is F
Grade for 7.8 is B
Grade for 9.5 is A+

PL/SQL procedure successfully completed.
*/