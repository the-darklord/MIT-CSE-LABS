create or replace trigger log_client
before update or delete on client_master
for each row
begin
	case
	when updating then
	insert into auditclient values(:OLD.client_no,:OLD.name,:OLD.bal_due,'UPDATE',1,current_date);
	when deleting then
	insert into auditclient values(:OLD.client_no,:OLD.name,:OLD.bal_due,'DELETE',1,current_date);
	end case;
end;
/