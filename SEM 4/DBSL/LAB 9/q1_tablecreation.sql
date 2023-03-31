create table salary_raise(ID varchar(5),raise_date date,raise_amount numeric(8,2));
alter table salary_raise add constraint fk_id foreign key(ID) references instructor(ID);