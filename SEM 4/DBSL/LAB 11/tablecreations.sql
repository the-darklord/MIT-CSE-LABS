create table log_change_takes
	(
	Time_Of_Change date,
	ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id		varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 grade		varchar(2),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id,sec_id, semester, year) references section on delete cascade,
	 foreign key (ID) references student on delete cascade
	);
	
create table old_data_instructor
	(ID			varchar(5), 
	 name			varchar(20) not null, 
	 dept_name		varchar(20), 
	 salary	numeric(8,2) check (salary > 29000),
	 primary key (ID),
	 foreign key (dept_name) references department
		on delete set null
	);
	
create table client_master
	(
		client_no numeric(5,0),
		name varchar(30),
		address varchar(50),
		bal_due numeric(10,2)
	);
	
create table auditclient
	(
		client_no numeric(5,0),
		name varchar(30),
		bal_due numeric(10,2),
		operation varchar(10),
		userid numeric(5,0),
		opdate date
	);
	
CREATE VIEW Advisor_Student AS 
SELECT Advisor.S_ID, Advisor.I_ID, Student.name S_NAME, Instructor.name I_NAME
FROM Advisor, Student, Instructor WHERE Advisor.S_ID = Student.ID AND Advisor.I_ID = Instructor.ID;