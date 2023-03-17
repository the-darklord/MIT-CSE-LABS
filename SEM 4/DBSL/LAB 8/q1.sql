set serveroutput on
declare
pl_rollno StudentTable.gpa%TYPE;
pl_row StudentTable%ROWTYPE;
begin
pl_rollno := &RollNum;

select * into pl_row
from StudentTable
where rollno=pl_rollno;

dbms_output.put_line('Details for '||pl_row.rollno||' are '||pl_row.gpa);
end;
/

/*
Enter value for rollnum: 3
old   5: pl_rollno := &RollNum;
new   5: pl_rollno := 3;
Details for 3 are 3.4

PL/SQL procedure successfully completed.
*/