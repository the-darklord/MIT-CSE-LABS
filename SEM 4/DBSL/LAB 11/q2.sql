create or replace trigger log_instructor_salary_update
before update of salary on instructor
for each row
begin
	insert into old_data_instructor values(:OLD.ID,:OLD.name,:OLD.dept_name,:OLD.salary);
end;
/