/*
ALTER TABLE `body` DROP FOREIGN KEY `body_fk0`;

ALTER TABLE `body` DROP FOREIGN KEY `body_fk1`;

ALTER TABLE `insurable` DROP FOREIGN KEY `insurable_fk0`;

ALTER TABLE `Morgue` DROP FOREIGN KEY `Morgue_fk0`;

ALTER TABLE `diagnosis` DROP FOREIGN KEY `diagnosis_fk0`;

ALTER TABLE `card` DROP FOREIGN KEY `card_fk0`;

ALTER TABLE `card` DROP FOREIGN KEY `card_fk1`;

ALTER TABLE `card` DROP FOREIGN KEY `card_fk2`;

ALTER TABLE `pathologist` DROP FOREIGN KEY `pathologist_fk0`;

ALTER TABLE `pathologist` DROP FOREIGN KEY `pathologist_fk1`;

*/
DROP TABLE IF EXISTS `body`;

DROP TABLE IF EXISTS `insurable`;

DROP TABLE IF EXISTS `Morgue`;

DROP TABLE IF EXISTS `diagnosis`;

DROP TABLE IF EXISTS `card`;

DROP TABLE IF EXISTS `pathologist`;

