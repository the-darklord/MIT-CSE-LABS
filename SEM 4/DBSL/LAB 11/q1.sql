create or replace trigger log_takes_insert_update
after insert  on takes
for each row
begin
case
	when inserting then
	insert into log_change_takes values(current_date,:NEW.ID,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
	when updating then
	insert into log_change_takes values(current_date,:NEW.ID,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
end case;
end;
/

create or replace trigger log_takes_update_delete
before update or delete on takes
for each row
begin
	case
	when updating then
	insert into log_change_takes values(current_date,:OLD.ID,:OLD.course_id,:OLD.sec_id,:OLD.semester,:OLD.year,:OLD.grade);
	when deleting then
	insert into log_change_takes values(current_date,:OLD.ID,:OLD.course_id,:OLD.sec_id,:OLD.semester,:OLD.year,:OLD.grade);
end case;
end;
/