-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 01, 2012 at 09:35 AM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `addressbook`
--

-- --------------------------------------------------------

--
-- Table structure for table `contacts`
--

CREATE TABLE IF NOT EXISTS `contacts` (
  `firstname` text COLLATE latin1_general_ci NOT NULL COMMENT 'First Name',
  `lastname` text COLLATE latin1_general_ci NOT NULL COMMENT 'Last Name',
  `middlename` text COLLATE latin1_general_ci NOT NULL COMMENT 'Middle Name',
  `address` text COLLATE latin1_general_ci NOT NULL COMMENT 'Address',
  `phonenumber` text COLLATE latin1_general_ci NOT NULL COMMENT 'Phone Number',
  `relationshiptype` enum('UNKNOWN','BUSINESS','FAMILY','PLEASURE','INFO','WORK') COLLATE latin1_general_ci NOT NULL COMMENT 'Relationship Type',
  UNIQUE KEY `KEY` (`phonenumber`(13),`firstname`(64),`lastname`(64))
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci COMMENT='Contacts list for address book. ';

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
