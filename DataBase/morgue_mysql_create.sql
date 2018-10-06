CREATE TABLE `body` (
	`id_body` INT NOT NULL,
	`sex` BINARY,
	`surname` VARCHAR(255),
	`name` VARCHAR(255),
	`date_arrived` DATE NOT NULL,
	`date_birth` DATE,
	`date_death` DATE,
	`id_insurable` INT NOT NULL,
	PRIMARY KEY (`id_body`)
);

CREATE TABLE `insurable` (
	`id_insurable` INT NOT NULL,
	`name` VARCHAR(255) NOT NULL UNIQUE,
	`addres` VARCHAR(255),
	`phone` VARCHAR(255),
	PRIMARY KEY (`id_insurable`)
);

CREATE TABLE `morgue` (
	`id_morgue` INT NOT NULL,
	`addres` VARCHAR(255),
	`phone` VARCHAR(255),
	PRIMARY KEY (`id_morgue`)
);

CREATE TABLE `diagnosis` (
	`id_diagnosis` INT NOT NULL,
	`name` VARCHAR(255) NOT NULL,
	PRIMARY KEY (`id_diagnosis`)
);

CREATE TABLE `card` (
	`id_body` INT NOT NULL,
	`id_diagnosis` INT NOT NULL,
	`id_doctor` INT NOT NULL
);

CREATE TABLE `pathologist` (
	`id_doctor` INT NOT NULL,
	`id_morgue` INT NOT NULL,
	`surname` VARCHAR(255) NOT NULL UNIQUE,
	`name` VARCHAR(255),
	`phone` VARCHAR(255),
	`addres` VARCHAR(255),
	PRIMARY KEY (`id_doctor`)
);

/*
ALTER TABLE `body` ADD CONSTRAINT `body_fk0` FOREIGN KEY (`id_body`) REFERENCES `card`(`id_body`);

ALTER TABLE `body` ADD CONSTRAINT `body_fk1` FOREIGN KEY (`id_insurable`) REFERENCES `insurable`(`id_insurable`);

ALTER TABLE `insurable` ADD CONSTRAINT `insurable_fk0` FOREIGN KEY (`id_insurable`) REFERENCES `body`(`id_insurable`);

ALTER TABLE `morgue` ADD CONSTRAINT `morgue_fk0` FOREIGN KEY (`id_morgue`) REFERENCES `pathologist`(`id_morgue`);

ALTER TABLE `diagnosis` ADD CONSTRAINT `diagnosis_fk0` FOREIGN KEY (`id_diagnosis`) REFERENCES `card`(`id_diagnosis`);

ALTER TABLE `card` ADD CONSTRAINT `card_fk0` FOREIGN KEY (`id_body`) REFERENCES `body`(`id_body`);

ALTER TABLE `card` ADD CONSTRAINT `card_fk1` FOREIGN KEY (`id_diagnosis`) REFERENCES `diagnosis`(`id_diagnosis`);

ALTER TABLE `card` ADD CONSTRAINT `card_fk2` FOREIGN KEY (`id_doctor`) REFERENCES `pathologist`(`id_doctor`);

ALTER TABLE `pathologist` ADD CONSTRAINT `pathologist_fk0` FOREIGN KEY (`id_doctor`) REFERENCES `card`(`id_doctor`);

ALTER TABLE `pathologist` ADD CONSTRAINT `pathologist_fk1` FOREIGN KEY (`id_morgue`) REFERENCES `Morgue`(`id_morgue`);

*/