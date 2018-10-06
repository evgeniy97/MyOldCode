CREATE TABLE `Тело` (
	`id_тела` DECIMAL NOT NULL AUTO_INCREMENT,
	`пол` BINARY NOT NULL AUTO_INCREMENT,
	`фамилия` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`имя` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`дата_поступления` DATE NOT NULL AUTO_INCREMENT,
	`дата_рождения` DATE NOT NULL AUTO_INCREMENT,
	`дата_смерти` DATE NOT NULL AUTO_INCREMENT,
	`id_страховой` DECIMAL NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`id_тела`)
);

CREATE TABLE `Страховая` (
	`id_страховой` DECIMAL NOT NULL AUTO_INCREMENT,
	`название` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`адрес` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`номер_телефона` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`id_страховой`)
);

CREATE TABLE `Морг` (
	`id_морга` DECIMAL NOT NULL AUTO_INCREMENT,
	`адрес` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`телефон` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`id_морга`)
);

CREATE TABLE `Патологоанатом` (
	`id_специалиста` DECIMAL NOT NULL AUTO_INCREMENT,
	`id_морга` DECIMAL NOT NULL AUTO_INCREMENT,
	`фамилия` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`имя` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`телефон` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	`адрес` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`id_специалиста`)
);

CREATE TABLE `Диагноз` (
	`id_диагноза` DECIMAL NOT NULL AUTO_INCREMENT,
	`название` VARCHAR(255) NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`id_диагноза`)
);

CREATE TABLE `Карта` (
	`id_тела` DECIMAL NOT NULL AUTO_INCREMENT,
	`id_диагноза` DECIMAL NOT NULL AUTO_INCREMENT,
	`id_специалиста` DECIMAL NOT NULL AUTO_INCREMENT
);

ALTER TABLE `Тело` ADD CONSTRAINT `Тело_fk0` FOREIGN KEY (`id_тела`) REFERENCES `Карта`(`id_тела`);

ALTER TABLE `Тело` ADD CONSTRAINT `Тело_fk1` FOREIGN KEY (`id_страховой`) REFERENCES `Страховая`(`id_страховой`);

ALTER TABLE `Страховая` ADD CONSTRAINT `Страховая_fk0` FOREIGN KEY (`id_страховой`) REFERENCES `Тело`(`id_страховой`);

ALTER TABLE `Морг` ADD CONSTRAINT `Морг_fk0` FOREIGN KEY (`id_морга`) REFERENCES `Патологоанатом`(`id_морга`);

ALTER TABLE `Патологоанатом` ADD CONSTRAINT `Патологоанатом_fk0` FOREIGN KEY (`id_специалиста`) REFERENCES `Карта`(`id_специалиста`);

ALTER TABLE `Патологоанатом` ADD CONSTRAINT `Патологоанатом_fk1` FOREIGN KEY (`id_морга`) REFERENCES `Морг`(`id_морга`);

ALTER TABLE `Диагноз` ADD CONSTRAINT `Диагноз_fk0` FOREIGN KEY (`id_диагноза`) REFERENCES `Карта`(`id_диагноза`);

ALTER TABLE `Карта` ADD CONSTRAINT `Карта_fk0` FOREIGN KEY (`id_тела`) REFERENCES `Тело`(`id_тела`);

ALTER TABLE `Карта` ADD CONSTRAINT `Карта_fk1` FOREIGN KEY (`id_диагноза`) REFERENCES `Диагноз`(`id_диагноза`);

ALTER TABLE `Карта` ADD CONSTRAINT `Карта_fk2` FOREIGN KEY (`id_специалиста`) REFERENCES `Патологоанатом`(`id_специалиста`);

INSERT INTO 'Морг' VALUES(1,'Улица Вязов, дом 13','1122')
INSERT INTO 'Морг' VALUES(2,'Жизненный тупик, дом 666','4534')
INSERT INTO 'Морг' VALUES(3,'Последнее пристанище улица, дом 3/7','4545')

INSERT INTO 'Патологоанатом' VALUES(1,1,'Чижков','Влад',NONE,NONE)
INSERT INTO 'Патологоанатом' VALUES(2,1,'Пушков','Иван',NONE,NONE)

INSERT INTO 'Патологоанатом' VALUES(3,2,'Пупкова','Елена',NONE,NONE)
INSERT INTO 'Патологоанатом' VALUES(4,2,'Мудков','Петр',NONE,NONE)

INSERT INTO 'Патологоанатом' VALUES(5,3,'Пипикова','Иванина',NONE,NONE)
INSERT INTO 'Патологоанатом' VALUES(6,3,'Пуп','Владислава',NONE,NONE)

INSERT INTO 'Диагноз' VALUES(1,'Сердечная недостаточность')
INSERT INTO 'Диагноз' VALUES(2,'Разрыв селезенки')
INSERT INTO 'Диагноз' VALUES(3,'Внезапное отделение головы от тела')
INSERT INTO 'Диагноз' VALUES(4,'Рак')
INSERT INTO 'Диагноз' VALUES(5,'Неизвестно')

INSERT INTO 'Страховая' VALUES(1,'Нежный ангел','Лесная, дом 3','4534')
INSERT INTO 'Страховая' VALUES(1,'Живи вечно','Люликова, дом 89','4822')

INSERT INTO 'Тело' VALUES(1,0,'Жданов','Петр','2018-09-23','1956-12-12','2018-09-23',1)
INSERT INTO 'Тело' VALUES(2,0,'Пипиков','Роман','2018-09-21','1986-05-14','2018-09-20',1)
INSERT INTO 'Тело' VALUES(3,1,'Пупкова','Мария','2018-09-20','1980-11-01','2018-09-20',2)
INSERT INTO 'Тело' VALUES(4,1,'Перепругнова','Лариса','2018-09-23','1976-10-12','2018-09-23',1)
INSERT INTO 'Тело' VALUES(5,0,'Кеков','Петрушка','2018-09-21','1990-01-23','2018-09-20',2)
INSERT INTO 'Тело' VALUES(6,0,'Ждуников','Петр','2018-09-19','1967-03-12','2018-09-19',1)
INSERT INTO 'Тело' VALUES(7,1,'Популяцкая','Ярослава','2018-09-20','1983-09-17','2018-09-20',2)
INSERT INTO 'Тело' VALUES(8,0,'Пуров','Мурий','2018-09-21','1979-04-06','2018-09-22',2)
INSERT INTO 'Тело' VALUES(9,0,'Покойников','Геракл','2018-09-18','1959-03-06','2018-09-17',2)
INSERT INTO 'Тело' VALUES(10,0,'Пуров','Мурий','2018-09-21','1965-11-24','2018-09-22',1)
INSERT INTO 'Тело' VALUES(11,1,'Пупыркина','Антонина','2018-09-20','1965-11-19','2018-09-20',1)
INSERT INTO 'Тело' VALUES(12,1,'Пуп','Владислва','2018-09-20','1919-11-19','2018-09-20',1)
INSERT INTO 'Тело' VALUES(13,1,None,None,'2018-09-20',None,None,None)
INSERT INTO 'Тело' VALUES(14,0,'Луа','Хуа','2018-09-18','1992-11-25','2018-09-18',1)
INSERT INTO 'Тело' VALUES(15,0,'Ненене','Пика','2018-09-20','1985-07-30','2018-09-20',2)
INSERT INTO 'Тело' VALUES(16,1,'Пуп','Тоника','2018-09-20','1925-06-14','2018-09-20',2)
INSERT INTO 'Тело' VALUES(17,0,'Акакака','Акакий','2018-09-18','1953-03-02','2018-09-18',1)
INSERT INTO 'Тело' VALUES(18,0,'Пуп','Владислва','2018-09-17','1987-02-04','2018-09-17',2)
INSERT INTO 'Тело' VALUES(19,0,'Бездомный','Владислва','2018-09-20','1919-09-19','2018-09-20',1)
INSERT INTO 'Тело' VALUES(20,0,'Труп','Аыва','2018-09-21','1956-11-19','2018-09-20',1)

INSERT INTO 'Карта' VALUES(1,1,1)
INSERT INTO 'Карта' VALUES(1,2,1)
INSERT INTO 'Карта' VALUES(2,3,4)
INSERT INTO 'Карта' VALUES(3,4,2)
INSERT INTO 'Карта' VALUES(4,1,3)
INSERT INTO 'Карта' VALUES(4,1,2)
INSERT INTO 'Карта' VALUES(5,3,6)
INSERT INTO 'Карта' VALUES(6,2,5)
INSERT INTO 'Карта' VALUES(7,1,5)
INSERT INTO 'Карта' VALUES(7,2,6)
INSERT INTO 'Карта' VALUES(8,4,3)
INSERT INTO 'Карта' VALUES(9,4,3)
INSERT INTO 'Карта' VALUES(10,2,6)
INSERT INTO 'Карта' VALUES(10,1,4)
INSERT INTO 'Карта' VALUES(11,3,1)
INSERT INTO 'Карта' VALUES(12,2,2)
INSERT INTO 'Карта' VALUES(13,1,3)
INSERT INTO 'Карта' VALUES(14,5,2)
INSERT INTO 'Карта' VALUES(15,5,2)
INSERT INTO 'Карта' VALUES(16,4,4)
INSERT INTO 'Карта' VALUES(17,2,3)
INSERT INTO 'Карта' VALUES(18,4,6)
INSERT INTO 'Карта' VALUES(19,3,2)
INSERT INTO 'Карта' VALUES(20,5,1)

/* 10-20 запросов
1) Добавление / Удаление тела
2) Вывести тела за определенную дату
3) Вывести тела, у которых не совпадает дата смерти и дата прибытия
4) Вывести тела, которым поставил диагнозы определнный врач
5) Вывести все диагнозы конкретного тела
5) Вывести все тела с конкретным диагнозом
6) Вывести все тела с определленой страховой
7) Вывести все тела из опредленного морга
8) Вывести всех врачей из определленого морга
9) Добавить / Удаление карты
10) Из опредленного морга определенным числом
11) Вывести все диагнозы которые ставил определенный врач 
12) Люди которые умерли в определенный период
13) Добавить / удалить врача
14) Вывести тела рожденные до/ после даты
15) Вывести всем страховые для каждого тела
16) Телефоны врачей которые ставили диагнозы определнному телу 
*/