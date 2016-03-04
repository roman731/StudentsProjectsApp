create table if not exists students(
      sID integer primary key not null, 
      name text NOT NULL, 
      pass text NOT NULL,  
      a1 integer NOT NULL,a2 integer NOT NULL, a3 integer NOT NULL,
      a4 integer NOT NULL,a5 integer NOT NULL, a6 integer NOT NULL,
      a7 integer NOT NULL, a8 integer NOT NULL, a9 integer NOT NULL,
      a10 integer NOT NULL,a11 integer NOT NULL, a12 integer NOT NULL,
    
      pa1 integer NOT NULL,pa2 integer NOT NULL, pa3 integer NOT NULL,
      pa4 integer NOT NULL, pa5 integer NOT NULL, pa6 integer NOT NULL,
      pa7 integer NOT NULL, pa8 integer NOT NULL, pa9 integer NOT NULL,
      pa10 integer NOT NULL, pa11 integer NOT NULL, pa12 integer NOT NULL
      );

create table if not exists admins(
      aID integer primary key not null, 
      name text NOT NULL, 
      pass text NOT NULL  
      );

create table if not exists projects(
      pID integer primary key not null, 
      name text NOT NULL, 
      description text NOT NULL,
      teamSize integer NOT NULL
      );

--Admins that own projects
create table if not exists ownsProject(
      aID integer,
      pID integer
      );
	  
--students that are registered in Projects
create table if not exists stuInProject(
      sID integer,
      pID integer
      );
	  
begin transaction;

--------------- ADDING projects to projects table ------------------------------------
insert into projects(pID, name, description, teamSize) values (1, 'Project1', 'p1description', 3);
insert into projects(pID, name, description, teamSize) values (2, 'Project2', 'p2description', 4);
insert into projects(pID, name, description, teamSize) values (3, 'Project3', 'p3description', 3);
insert into projects(pID, name, description, teamSize) values (4, 'Project4', 'p4 description', 4);

--------------- ADDING admins to admins table ---------------
insert into admins(aID, name, pass) values (1, 'Admin1', 'p');
insert into admins(aID, name, pass) values (2, 'Admin2', 'p');
insert into admins(aID, name, pass) values (3, 'Admin3', 'p');
insert into admins(aID, name, pass) values (4, 'Admin4', 'p');


-------------- ADDING STUDENTS to student table ------------------------------------------------
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (1, 'Alice', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (2, 'Bob', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                  1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (3, 'Charlie', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,               1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (4, 'Dale', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                  1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (5, 'Evan', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                  1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (6, 'Frank', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (7, 'George', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (8, 'Henry', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (9, 'Ivan', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                  1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (10, 'Janice', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,               1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (11, 'Karl', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (12, 'Louis', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (13, 'Mary', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (14, 'Nathan', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10,11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (15, 'Olga', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (16, 'Peter', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (17, 'Quinton', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,              1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (18, 'Rosanne', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,              1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (19, 'Susan', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (20, 'Tyler', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (21, 'Usain', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (22, 'Violet', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,               1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (23, 'Wolly', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (24, 'Xavier', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,               1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (25, 'Yoda', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);
insert into students(sID, name, pass, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12, pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12) values (26, 'Zebra', 'p', 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12,                1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12);

--------------- ADDING ownsProject ------------------
insert into ownsProject(aID, pID) values (1, 1);
insert into ownsProject(aID, pID) values (2, 2);
insert into ownsProject(aID, pID) values (3, 3);
insert into ownsProject(aID, pID) values (4, 4);

--------------- ADDING stuInProject ---------------
insert into stuInProject(sID, pID) values (1, 1);
insert into stuInProject(sID, pID) values (2, 2);
insert into stuInProject(sID, pID) values (3, 3);
insert into stuInProject(sID, pID) values (4, 4);
insert into stuInProject(sID, pID) values (5, 2);
insert into stuInProject(sID, pID) values (6, 3);
insert into stuInProject(sID, pID) values (7, 4);
insert into stuInProject(sID, pID) values (8, 2);
insert into stuInProject(sID, pID) values (9, 3);
insert into stuInProject(sID, pID) values (10, 4);
insert into stuInProject(sID, pID) values (11, 2);
insert into stuInProject(sID, pID) values (12, 3);
insert into stuInProject(sID, pID) values (13, 1);
insert into stuInProject(sID, pID) values (14, 2);
insert into stuInProject(sID, pID) values (15, 3);
insert into stuInProject(sID, pID) values (16, 1);
insert into stuInProject(sID, pID) values (17, 2);
insert into stuInProject(sID, pID) values (18, 3);
insert into stuInProject(sID, pID) values (19, 4);
insert into stuInProject(sID, pID) values (20, 1);
insert into stuInProject(sID, pID) values (21, 3);
insert into stuInProject(sID, pID) values (22, 4);
insert into stuInProject(sID, pID) values (23, 2);
insert into stuInProject(sID, pID) values (24, 1);
insert into stuInProject(sID, pID) values (25, 4);
insert into stuInProject(sID, pID) values (26, 2);

end transaction;

