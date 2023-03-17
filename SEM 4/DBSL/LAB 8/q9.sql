set serveroutput on
declare
out_of_range exception;
grade char(2);
x number := 0;
pl_row StudentTable%ROWTYPE;
begin

loop

x := x+1;

if x > 6 then exit;
end if;

select * into pl_row
from StudentTable
where rollno=x;

if pl_row.gpa>=0 and pl_row.gpa<4 then grade :='F';
elsif pl_row.gpa>=4 and pl_row.gpa<5 then grade :='E';
elsif pl_row.gpa>=5 and pl_row.gpa<6 then grade :='D';
elsif pl_row.gpa>=6 and pl_row.gpa<7 then grade :='C';
elsif pl_row.gpa>=7 and pl_row.gpa<8 then grade :='B';
elsif pl_row.gpa>=8 and pl_row.gpa<9 then grade :='A';
elsif pl_row.gpa>=9 and pl_row.gpa<10 then grade :='A+';
else raise out_of_range;
end if;

update StudentTable
set LetterGrade = grade
where rollno = x;

dbms_output.put_line('Grade for '||pl_row.gpa||' is '||grade);

end loop;

exception
when out_of_range then dbms_output.put_line('GPA out of range');
when others then dbms_output.put_line('ERROR');
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

