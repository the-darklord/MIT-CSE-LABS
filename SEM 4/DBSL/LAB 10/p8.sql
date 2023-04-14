set serveroutput on;
create or replace procedure simp_comp(principle in number,rate in number,years in number,times in number,SI out numeric,CI out numeric,tot_sum in out numeric) as
begin
	SI :=(principle*rate*years)/100;
	CI :=principle*power((1+rate/times),times*years);
	tot_sum := principle + SI + CI;
end;
/