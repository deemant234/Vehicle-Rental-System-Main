CREATE TABLE `admin_acc` (
  `Admin_name` varchar(25) NOT NULL,
  `UID` varchar(10) NOT NULL,
  `mob_no` bigint NOT NULL,
  PRIMARY KEY (`UID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `common_user` (
  `name` varchar(25) NOT NULL,
  `Aadhar_no` int NOT NULL,
  `mob_no` bigint NOT NULL COMMENT 'mobile number of person',
  PRIMARY KEY (`Aadhar_no`),
  UNIQUE KEY `Aadhar_no_UNIQUE` (`Aadhar_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `veh_history` (
  `veh_no` varchar(25) NOT NULL,
  `date_of_start` date NOT NULL,
  `date_of_leave` date NOT NULL,
  `earning` bigint DEFAULT NULL,
  PRIMARY KEY (`veh_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `veh_on_rent_1` (
  `name` varchar(25) DEFAULT NULL,
  `aadhar_no` int NOT NULL,
  `mob_no` bigint NOT NULL,
  `vehicle_no` varchar(15) NOT NULL,
  `vehicle_type` int NOT NULL,
  `Date_of_joining` date NOT NULL COMMENT 'Date of giving vehicle on rent',
  PRIMARY KEY (`aadhar_no`,`vehicle_no`),
  KEY `aadhar_no_idx` (`aadhar_no`),
  KEY `vehicle_no_idx` (`vehicle_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `veh_on_rent_2` (
  `aadhar_no` int NOT NULL,
  `vehicle_no` varchar(15) NOT NULL,
  `date_of_leave` date DEFAULT NULL,
  `earning` float DEFAULT NULL,
  PRIMARY KEY (`aadhar_no`,`vehicle_no`),
  KEY `aadhar_no_idx` (`aadhar_no`),
  KEY `vehicle_no _idx` (`vehicle_no`),
  CONSTRAINT `aadhar_no_FK` FOREIGN KEY (`aadhar_no`) REFERENCES `veh_on_rent_1` (`aadhar_no`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `vehicle_no_FK ` FOREIGN KEY (`vehicle_no`) REFERENCES `veh_on_rent_1` (`vehicle_no`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `veh_user_fd_record` (
  `veh_no` varchar(15) NOT NULL,
  `aadhar_no` int NOT NULL,
  `Date_of_start` date NOT NULL,
  `expected_date_of_ret` date DEFAULT NULL,
  `fare` float DEFAULT NULL COMMENT 'total fare to be paid',
  `actual_date_of_ret` date DEFAULT NULL,
  `days_diff` int DEFAULT NULL,
  PRIMARY KEY (`veh_no`,`aadhar_no`,`Date_of_start`),
  KEY `aadhar_no_fk_idx` (`aadhar_no`),
  KEY `act_date_fk` (`Date_of_start`),
  CONSTRAINT `aadhar_no_fk_rcd` FOREIGN KEY (`aadhar_no`) REFERENCES `vehicle_user_fd` (`aadhar_no`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `act_date_fk` FOREIGN KEY (`Date_of_start`) REFERENCES `vehicle_user_fd` (`Date_of_start`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `vehicle_no_fk_rcd` FOREIGN KEY (`veh_no`) REFERENCES `vehicle_user_fd` (`veh_no`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `vehicle_booked` (
  `owner_name` varchar(25) DEFAULT NULL,
  `user_name` varchar(25) DEFAULT NULL,
  `veh_no` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;



CREATE TABLE `vehicle_user_fd` (
  `aadhar_no` int NOT NULL,
  `veh_no` varchar(15) NOT NULL,
  `Date_of_start` date NOT NULL COMMENT 'DATE OF TAKING VEHICLE ON RENT',
  `name` varchar(25) NOT NULL,
  `mob_no` bigint NOT NULL,
  `veh_type` int NOT NULL,
  `days` int NOT NULL COMMENT 'days for which vehicle is taken on rent',
  PRIMARY KEY (`aadhar_no`,`veh_no`,`Date_of_start`),
  KEY `aadhar_no_idx` (`aadhar_no`),
  KEY `vehicle_no_idx` (`veh_no`) /*!80000 INVISIBLE */,
  KEY `start_date_idx` (`Date_of_start`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `avail_veh` AS select `veh_on_rent_1`.`name` 
AS `name`,`veh_on_rent_1`.`vehicle_no` AS `vehicle_no`,`veh_on_rent_1`.`vehicle_type` AS `vehicle_type` from `veh_on_rent_1`;


CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `booking_rec_fd` AS select `veh_user_fd_record`.`Date_of_start` 
AS `Date_of_start`,`veh_user_fd_record`.`aadhar_no` AS `aadhar_no`,`veh_user_fd_record`.`veh_no` AS `veh_no`,`veh_user_fd_record`.`expected_date_of_ret` 
AS `expected_date_of_ret` from `veh_user_fd_record`;

DELIMITER $$
CREATE DEFINER=`root`@`localhost` FUNCTION `day_calc`(
 date1 date ,date2 date
) RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE i INT;
    SET i=datediff(date1,date2);
    RETURN i; 
END$$
DELIMITER ;


DELIMITER $$
CREATE DEFINER=`root`@`localhost` FUNCTION `fare`(
 days int
) RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE i INT;
    SET i=days*2000;
    RETURN i; 
END$$
DELIMITER ;

ALTER TABLE `veh_rent`.`veh_history` 
ADD COLUMN `Sr_no` INT NOT NULL AUTO_INCREMENT AFTER `veh_no`,
CHANGE COLUMN `earning` `earning` BIGINT NULL ,
ADD UNIQUE INDEX `Sr_no_UNIQUE` (`Sr_no` ASC) VISIBLE;
;


INSERT INTO artist VALUES('Kriti',10,'India');
delete  from artist  ;
update artist set rating = 10 where name ='Anavi';
select * from artist;

CREATE TABLE `php_assignment`.`check_user` (
  `Username` VARCHAR(25) NOT NULL,
  `Password` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`Username`, `Password`));

INSERT INTO check_user VALUES ('Dhruv Goyal' , '12345');

select * from artist;

