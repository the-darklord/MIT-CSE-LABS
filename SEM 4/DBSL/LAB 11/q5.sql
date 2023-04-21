Create or replace trigger advisor_delete
INSTEAD OF DELETE on Advisor_Student
FOR EACH ROW
BEGIN
delete from advisor where s_id= :OLD.s_id and i_id= :OLD.i_id;
END;
/