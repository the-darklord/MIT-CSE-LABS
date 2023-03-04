drop table prereq;
drop table time_slot;
drop table advisor;
drop table takes;
drop table student;
drop table teaches;
drop table section;
drop table instructor;
drop table course;
drop table department;
drop table classroom;
drop table dependent;
drop table works_on;
drop table project;
drop table dept_locations;
drop table department1;
drop table employee1;
drop table employee;
drop table dept_locations;


-- It creates a table named EMPLOYEE
CREATE TABLE EMPLOYEE1
(
    Fname     VARCHAR(15) NOT NULL,
    Minit     CHAR, 
    Lname     VARCHAR(15) NOT NULL,
    Ssn       CHAR(9)     NOT NULL,
    Bdate     DATE,
    Address   VARCHAR(30),
    Sex       CHAR,
    Salary    DECIMAL(10,2),
    Super_ssn CHAR(9),
    Dno       INT         NOT NULL,
    PRIMARY KEY (Ssn)    
);

-- The following script creates a new table named DEPARTMENT
CREATE TABLE DEPARTMENT1
(
    Dname          VARCHAR(15) NOT NULL,
    Dnumber        INT         NOT NULL,
    Mgr_ssn        CHAR(9)     NOT NULL,
    Mgr_start_date DATE,
    PRIMARY KEY (Dnumber),
    UNIQUE (Dname),
    FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE1(Ssn)
);

-- The following script creates a new table named DEPT_LOCATIONS
CREATE TABLE DEPT_LOCATIONS
(
    Dnumber   INT         NOT NULL,
    Dlocation VARCHAR(15) NOT NULL,
    PRIMARY KEY (Dnumber, Dlocation),
    FOREIGN key (Dnumber) REFERENCES DEPARTMENT1 (Dnumber)
);

-- The following script creates a new table named PROJECT
CREATE TABLE PROJECT
(
    Pname     VARCHAR(15) NOT NULL,
    Pnumber   INT         NOT NULL,
    Plocation VARCHAR(15),
    Dnum      INT         NOT NULL,
    PRIMARY KEY(Pnumber),
    UNIQUE(Pname),
    FOREIGN KEY(Dnum) REFERENCES DEPARTMENT1(Dnumber)
);

-- The following script creates a new table named WORKS_ON
CREATE TABLE WORKS_ON
(
    Essn  CHAR(9)      NOT NULL,
    Pno   INT          NOT NULL,
    Hours DECIMAL(3,1) NOT NULL,
    PRIMARY KEY(Essn, Pno),
    FOREIGN KEY(Essn) REFERENCES EMPLOYEE1(Ssn),
    FOREIGN KEY(Pno)  REFERENCES PROJECT(Pnumber)
);

-- The following script creates a new table named DEPENDENT
CREATE TABLE DEPENDENT
(
    Essn           CHAR(9)     NOT NULL,
    Dependent_name VARCHAR(15) NOT NULL,
    Sex            CHAR,
    Bdate          DATE,
    Relationship   VARCHAR(8),
    PRIMARY KEY(Essn, Dependent_name),
    FOREIGN KEY(Essn) REFERENCES EMPLOYEE1(Ssn)
);

-- **********************************************************************************************
-- INSERT operations

-- The following script adds a new tuple to the EMPLOYEE relation
INSERT INTO EMPLOYEE1
VALUES ('Richard', 'K', 'Marini', '653298653', TO_DATE('1962-12-30','YYYY-MM-DD'), '98 Oak Forest, Katy, TX', 'M', 37000, '653298653', 4);
INSERT INTO EMPLOYEE1
VALUES ('John', 'B', 'Smith', '123456789', TO_DATE('1965-01-09','YYYY-MM-DD'), '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
INSERT INTO EMPLOYEE1
VALUES ('Franklin', 'T', 'Wong', '333445555', TO_DATE('1965-12-08','YYYY-MM-DD'), '638 Voss, Houston, TX', 'M', 40000, '888665555', 5);
INSERT INTO EMPLOYEE1
VALUES ('Alicia', 'J', 'Zelaya', '999887777', TO_DATE('1968-01-19','YYYY-MM-DD'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);
INSERT INTO EMPLOYEE1
VALUES ('Jennifer', 'S', 'Wallace', '987654321', TO_DATE('1941-06-20','YYYY-MM-DD'), '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4);
INSERT INTO EMPLOYEE1
VALUES ('Ramesh', 'K', 'Narayan', '666884444', TO_DATE('1962-09-15','YYYY-MM-DD'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);
INSERT INTO EMPLOYEE1
VALUES ('Joyce', 'A', 'English', '453453453', TO_DATE('1972-07-31','YYYY-MM-DD'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);
INSERT INTO EMPLOYEE1
VALUES ('Ahmad', 'V', 'Jabbar', '987987987', TO_DATE('1969-03-29','YYYY-MM-DD'), '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);
INSERT INTO EMPLOYEE1
VALUES ('James', 'E', 'Borg', '888665555', TO_DATE('1937-11-10','YYYY-MM-DD'), '450 Stone, Houston, TX', 'M', 55000, NULL, 4);


-- The following script adds a new tuple to the DEPARTMENT relation
INSERT INTO DEPARTMENT1
VALUES ('Research', 5, '333445555', TO_DATE('1988-05-22','YYYY-MM-DD'));
INSERT INTO DEPARTMENT1
VALUES ('Administration', 4, '987654321', TO_DATE('1995-01-01','YYYY-MM-DD'));
INSERT INTO DEPARTMENT1
VALUES ('Headquarters', 1, '888665555', TO_DATE('1981-06-19','YYYY-MM-DD'));

-- The following script adds a new tuple to the DEPT_LOCATIONS relation
INSERT INTO DEPT_LOCATIONS
VALUES (1, 'Houston');
INSERT INTO DEPT_LOCATIONS
VALUES (4, 'Stafford');
INSERT INTO DEPT_LOCATIONS
VALUES (5, 'Bellaire');
INSERT INTO DEPT_LOCATIONS
VALUES (5, 'Sugarland');
INSERT INTO DEPT_LOCATIONS
VALUES (5, 'Houston');

-- The following script adds a new tuple to the PROJECT relation
INSERT INTO PROJECT
VALUES ('ProductX', 1,' Bellaire', 5);
INSERT INTO PROJECT
VALUES ('ProductY', 2, 'Sugarland', 5);
INSERT INTO PROJECT
VALUES ('ProductZ', 3, 'Houston', 5);
INSERT INTO PROJECT
VALUES ('Computerization', 10, 'Stafford', 4);
INSERT INTO PROJECT
VALUES ('Reorganization', 20, 'Houston', 1);
INSERT INTO PROJECT
VALUES ('Newbenefits', 30, 'Starfford', 4);

-- The following script adds a new tuple to the WORKS_ON relation
INSERT INTO WORKS_ON 
VALUES ('123456789', 1, 32.5);
INSERT INTO WORKS_ON 
VALUES ('123456789', 2, 7.5);
INSERT INTO WORKS_ON 
VALUES ('666884444', 3, 40.0);
INSERT INTO WORKS_ON 
VALUES ('453453453', 1, 20.0);
INSERT INTO WORKS_ON 
VALUES ('453453453', 2, 20.0);
INSERT INTO WORKS_ON 
VALUES ('333445555', 2, 10.0);
INSERT INTO WORKS_ON 
VALUES ('333445555', 3, 10.0);
INSERT INTO WORKS_ON 
VALUES ('333445555', 10, 10.0);
INSERT INTO WORKS_ON 
VALUES ('333445555', 20, 10.0);
INSERT INTO WORKS_ON 
VALUES ('999887777', 30, 30.0);
INSERT INTO WORKS_ON 
VALUES ('999887777', 10, 10.0);
INSERT INTO WORKS_ON 
VALUES ('987987987', 10, 35.0);
INSERT INTO WORKS_ON 
VALUES ('987987987', 30, 5.0);
INSERT INTO WORKS_ON 
VALUES ('987654321', 30, 20.0);
INSERT INTO WORKS_ON 
VALUES ('987654321', 20, 15.0);
INSERT INTO WORKS_ON 
VALUES ('888665555', 20, 0);

-- The following script adds a new tuple to the DEPENDENT relation
INSERT INTO DEPENDENT
VALUES ('333445555', 'Alice', 'F', TO_DATE('1986-04-05','YYYY-MM-DD'), 'Daughter');
INSERT INTO DEPENDENT
VALUES ('333445555', 'Theodore', 'M', TO_DATE('1983-10-25','YYYY-MM-DD'), 'Son');
INSERT INTO DEPENDENT
VALUES ('333445555', 'Joy', 'F', TO_DATE('1958-05-03','YYYY-MM-DD'), 'Spouse');
INSERT INTO DEPENDENT
VALUES ('987654321', 'Abner', 'M', TO_DATE('1942-02-28','YYYY-MM-DD'), 'Spouse');
INSERT INTO DEPENDENT
VALUES ('123456789', 'Michael', 'M', TO_DATE('1988-01-04','YYYY-MM-DD'), 'Son');
INSERT INTO DEPENDENT
VALUES ('123456789', 'Alice', 'F', TO_DATE('1988-12-30','YYYY-MM-DD'), 'Daughter');
INSERT INTO DEPENDENT
VALUES ('123456789', 'Elizabeth', 'F', TO_DATE('1967-05-05','YYYY-MM-DD'), 'Spouse');

-- *********************************************************************************************************
-- Basic queries to test the tables

ALTER TABLE Employee1 RENAME TO Employee;
ALTER TABLE Department1 RENAME TO Department;

SELECT * FROM EMPLOYEE;
SELECT * FROM DEPARTMENT;
SELECT * FROM DEPT_LOCATIONS;
SELECT * FROM PROJECT;
SELECT * FROM WORKS_ON;
SELECT * FROM DEPENDENT;