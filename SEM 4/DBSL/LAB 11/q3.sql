create or replace trigger log_instructor_check
before insert or update of salary on instructor
for each row
declare
sal instructor.salary%TYPE;
budg department.budget%TYPE;
begin
	IF LENGTH(TRIM(TRANSLATE(:NEW.name, 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ' '))) > 0 then
		RAISE_APPLICATION_ERROR(-20100,'Name must contain only alphabets');
ELSE
    IF :NEW.salary < 1 THEN
        RAISE_APPLICATION_ERROR(-20100,'Salary must be greater than 0');
    ELSE
        SELECT SUM(salary) INTO sal FROM instructor WHERE dept_name = :NEW.dept_name;
        SELECT budget INTO budg FROM department WHERE dept_name = :NEW.dept_name;
        IF sal + :NEW.salary > budg THEN
            RAISE_APPLICATION_ERROR(-20100,'Not enough department budget');
        END IF;
    END IF;
END IF;
end;
/