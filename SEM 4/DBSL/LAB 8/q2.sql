set serveroutput on
declare
grade char(2);
pl_gpa StudentTable.gpa%TYPE;
begin

pl_gpa :=&gpa;

if pl_gpa>=0 and pl_gpa<4 then grade :='F';
elsif pl_gpa>=4 and pl_gpa<5 then grade :='E';
elsif pl_gpa>=5 and pl_gpa<6 then grade :='D';
elsif pl_gpa>=6 and pl_gpa<7 then grade :='C';
elsif pl_gpa>=7 and pl_gpa<8 then grade :='B';
elsif pl_gpa>=8 and pl_gpa<9 then grade :='A';
else grade :='A+';
end if;
dbms_output.put_line('Grade for '||pl_gpa||' is '||grade);
end;
/

/*
Enter value for gpa: 6
old   6: pl_gpa :=&gpa;
new   6: pl_gpa :=6;
Grade for 6 is C

PL/SQL procedure successfully completed.
*/