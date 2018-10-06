CREATE TABLE `body` (`id_body` DECIMAL NOT NULL PRIMARY KEY,`sex` BINARY,`surname` VARCHAR (255),`name` VARCHAR (255),`date_birt` DATE,`date_root` DATE,`death_date` DATE,`id_insurance` DECIMAL NOT NULL);
CREATE TABLE `Insurance` (`id_insurance` DECIMAL  PRIMARY KEY NOT NULL,`name` VARCHAR (255) NOT NULL,`address` VARCHAR (255),`phone` VARCHAR (255));
CREATE TABLE `Morgue` (	`id_morgue` DECIMAL  PRIMARY KEY NOT NULL,`address` VARCHAR (255),`phone` VARCHAR (255));
CREATE TABLE `Pathologist` (`id_specialist` DECIMAL  PRIMARY KEY NOT NULL ,`id_morgue` DECIMAL NOT NULL,`surname` VARCHAR(255) NOT NULL,`name` VARCHAR(255),`phone` VARCHAR(255),`addres` VARCHAR(255));
CREATE TABLE `Diagnosis` (`id_diagnosis` DECIMAL  PRIMARY KEY NOT NULL ,`name` VARCHAR(255) NOT NULL);
CREATE TABLE `Map` (`id_body` DECIMAL NOT NULL,`id_diagnosis` DECIMAL NOT NULL,`id_specialist` DECIMAL NOT NULL);
ALTER TABLE `body` ADD CONSTRAINT `body_fk0` FOREIGN KEY (`id_body`) REFERENCES `Map`(`id_body`);
ALTER TABLE `body` ADD CONSTRAINT `body_fk1` FOREIGN KEY (`id_insurance`) REFERENCES `Insurance`(`id_insurance`);
ALTER TABLE `Insurance` ADD CONSTRAINT `Insurance_fk0` FOREIGN KEY (`id_insurance`) REFERENCES `body`(`id_insurance`);
ALTER TABLE `Morgue` ADD CONSTRAINT `Morgue_fk0` FOREIGN KEY (`id_morgue`) REFERENCES `Pathologist`(`id_morgue`);
ALTER TABLE `Pathologist` ADD CONSTRAINT `Pathologist_fk0` FOREIGN KEY (`id_specialist`) REFERENCES `Map`(`id_specialist`);
ALTER TABLE `Pathologist` ADD CONSTRAINT `Pathologist_fk1` FOREIGN KEY (`id_morgue`) REFERENCES `Morgue`(`id_morgue`);
ALTER TABLE `Diagnosis` ADD CONSTRAINT `Diagnosis_fk0` FOREIGN KEY (`id_diagnosis`) REFERENCES `Map`(`id_diagnosis`);
ALTER TABLE `Map` ADD CONSTRAINT `Map_fk0` FOREIGN KEY (`id_body`) REFERENCES `body`(`id_body`);
ALTER TABLE `Map` ADD CONSTRAINT `Map_fk1` FOREIGN KEY (`id_diagnosis`) REFERENCES `Diagnosis`(`id_diagnosis`);
ALTER TABLE `Map` ADD CONSTRAINT `Map_fk2` FOREIGN KEY (`id_specialist`) REFERENCES `Pathologist`(`id_specialist`);
INSERT INTO 'Morgue' VALUES (1, 'Elm Street, House 13', '1122')
INSERT INTO 'Morgue' VALUES (2, 'Deadlock, house 666', '4534')
INSERT INTO 'Morgue' VALUES (3, 'The last shelter street, house 3/7', '4545')
INSERT INTO 'Pathologist' VALUES (1,1, 'Chizhkov', 'Vlad', NONE, NONE)
INSERT INTO 'Pathologist' VALUES (2,1, 'Pushkov', 'Ivan', NONE, NONE)
INSERT INTO 'Pathologist' VALUES (3,2, 'Pupkov', 'Elena', NONE, NONE)
INSERT INTO 'Pathologist' VALUES (4,2, 'Mudkov', 'Peter', NONE, NONE)
INSERT INTO 'Pathologist' VALUES (5.3, 'Pipikov', 'Ivanina', NONE, NONE)
INSERT INTO 'Pathologist' VALUES (6,3, 'Pup', 'Vladislav', NONE, NONE)
INSERT INTO 'Diagnosis' VALUES (1, 'Heart failure')
INSERT INTO 'Diagnosis' VALUES (2, 'Spleen rupture')
INSERT INTO 'Diagnosis' VALUES (3, 'Sudden separation of the head from the body')
INSERT INTO 'Diagnosis' VALUES (4, 'Cancer')
INSERT INTO 'Diagnosis' VALUES (5, 'Unknown')
INSERT INTO 'Insurance' VALUES (1, 'Tender Angel', 'Forest, house 3', '4534')
INSERT INTO 'Insurance' VALUES (1, 'Live Forever', 'Lulikova, house 89', '4822')
INSERT INTO 'body' VALUES (1.0, 'Zhdanov', 'Petr', '2018-09-23', '1956-12-12', '2018-09-23', 1)
INSERT INTO 'body' VALUES (2,0, 'Pipikov', 'Roman', '2018-09-21', '1986-05-14', '2018-09-20', 1)
INSERT INTO 'body' VALUES (3,1, 'Pupkova', 'Maria', '2018-09-20', '1980-11-01', '2018-09-20', 2)
INSERT INTO 'body' VALUES (4,1, 'Pereprugnov', 'Larissa', '2018-09-23', '1976-10-12', '2018-09-23', 1)
INSERT INTO 'body' VALUES (5,0, 'Kekov', 'Parsley', '2018-09-21', '1990-01-23', '2018-09-20', 2)
INSERT INTO 'body' VALUES (6,0, 'Zhdunikov', 'Petr', '2018-09-19', '1967-03-12', '2018-09-19', 1)
INSERT INTO 'body' VALUES (7,1, 'Populyatskaya', 'Yaroslav', '2018-09-20', '1983-09-17', '2018-09-20', 2)
INSERT INTO 'body' VALUES (8,0, 'Purov', 'Muri', '2018-09-21', '1979-04-06', '2018-09-22', 2)
INSERT INTO 'body' VALUES (9,0, 'dead men', 'Hercules', '2018-09-18', '1959-03-06', '2018-09-17', 2)
INSERT INTO 'body' VALUES (10,0, 'Purov', 'Muri', '2018-09-21', '1965-11-24', '2018-09-22', 1)
INSERT INTO 'body' VALUES (11.1, 'Pupyrkina', 'Antonina', '2018-09-20', '1965-11-19', '2018-09-20', 1)
INSERT INTO 'body' VALUES (12,1, 'Pup', 'Vladislav', '2018-09-20', '1919-11-19', '2018-09-20', 1)
INSERT INTO 'body' VALUES (13,1, None, None, '2018-09-20', None, None, None)
INSERT INTO 'body' VALUES (14,0, 'Loa', 'Hua', '2018-09-18', '1992-11-25', '2018-09-18', 1)
INSERT INTO 'body' VALUES (15,0, 'Nenene', 'Peak', '2018-09-20', '1985-07-30', '2018-09-20', 2)
INSERT INTO 'body' VALUES (16,1, 'Pup', 'Tonic', '2018-09-20', '1925-06-14', '2018-09-20', 2)
INSERT INTO 'body' VALUES (17,0, 'Akakaka', 'Akaki', '2018-09-18', '1953-03-02', '2018-09-18', 1)
INSERT INTO 'body' VALUES (18,0, 'Pup', 'Vladislav', '2018-09-17', '1987-02-04', '2018-09-17', 2)
INSERT INTO 'body' VALUES (19.0, 'Homeless', 'Vladislav', '2018-09-20', '1919-09-19', '2018-09-20', 1)
INSERT INTO 'body' VALUES (20,0, 'Corpse', 'AYVA', '2018-09-21', '1956-11-19', '2018-09-20', 1)
INSERT INTO 'Map' VALUES(1,1,1)
INSERT INTO 'Map' VALUES(1,2,1)
INSERT INTO 'Map' VALUES(2,3,4)
INSERT INTO 'Map' VALUES(3,4,2)
INSERT INTO 'Map' VALUES(4,1,3)
INSERT INTO 'Map' VALUES(4,1,2)
INSERT INTO 'Map' VALUES(5,3,6)
INSERT INTO 'Map' VALUES(6,2,5)
INSERT INTO 'Map' VALUES(7,1,5)
INSERT INTO 'Map' VALUES(7,2,6)
INSERT INTO 'Map' VALUES(8,4,3)
INSERT INTO 'Map' VALUES(9,4,3)
INSERT INTO 'Map' VALUES(10,2,6)
INSERT INTO 'Map' VALUES(10,1,4)
INSERT INTO 'Map' VALUES(11,3,1)
INSERT INTO 'Map' VALUES(12,2,2)
INSERT INTO 'Map' VALUES(13,1,3)
INSERT INTO 'Map' VALUES(14,5,2)
INSERT INTO 'Map' VALUES(15,5,2)
INSERT INTO 'Map' VALUES(16,4,4)
INSERT INTO 'Map' VALUES(17,2,3)
INSERT INTO 'Map' VALUES(18,4,6)
INSERT INTO 'Map' VALUES(19,3,2)
INSERT INTO 'Map' VALUES(20,5,1)