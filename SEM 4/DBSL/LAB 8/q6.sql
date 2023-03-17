set serveroutput on
declare
pl_row StudentTable%ROWTYPE;
x number := 1;
maxgpa StudentTable.gpa%TYPE;
begin

select gpa into maxgpa
from StudentTable
where rollno=x;

loop

x := x+1;

if x>5 then exit;
end if;

select * into pl_row
from StudentTable
where rollno=x;

if pl_row.gpa > maxgpa then maxgpa := pl_row.gpa;
end if;

end loop;

select * into pl_row
from StudentTable
where gpa=maxgpa;

dbms_output.put_line('Max GPA is '||pl_row.gpa||' for RollNo '||pl_row.rollno);

end;
/

/*
Max GPA is 9.5 for RollNo 5

PL/SQL procedure successfully completed.

*/