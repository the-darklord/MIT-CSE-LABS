set serveroutput on
declare
SI numeric(10,2);
CI numeric(10,2);
tot_sum numeric(10,2);
begin
	simp_comp(10000,5,2,3,SI,CI,tot_sum);
	dbms_output.put_line('Simple Interest '||SI);
	dbms_output.put_line('Compound Interest '||CI);
	dbms_output.put_line('Tot Sum '||tot_sum);
end;
/