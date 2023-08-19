-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  lun. 11 oct. 2021 à 11:31
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `mefsuggest`
--

-- --------------------------------------------------------

--
-- Structure de la table `dictionnaire`
--

DROP TABLE IF EXISTS `dictionnaire`;
CREATE TABLE IF NOT EXISTS `dictionnaire` (
  `words` varchar(30) CHARACTER SET utf8 NOT NULL,
  `theme` int(11) NOT NULL,
  PRIMARY KEY (`words`,`theme`),
  KEY `theme_dictionnaire_fk` (`theme`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `dictionnaire`
--

INSERT INTO `dictionnaire` (`words`, `theme`) VALUES
('câbl[a-zA-Z]*', 1),
('déçu', 3),
('D[.]*S[.]*I[.]*', 1),
('informatique', 1),
('internet', 1),
('ordi[a-zA-Z]*', 1),
('porte[s]{0,1}', 2);

-- --------------------------------------------------------

--
-- Structure de la table `resulttable`
--

DROP TABLE IF EXISTS `resulttable`;
CREATE TABLE IF NOT EXISTS `resulttable` (
  `resulltId` int(11) NOT NULL AUTO_INCREMENT,
  `number` int(11) NOT NULL,
  `theme` int(11) NOT NULL,
  `count` int(11) NOT NULL,
  PRIMARY KEY (`resulltId`),
  KEY `theme_resulttable_fk` (`theme`),
  KEY `suggestion_resulttable_fk` (`number`)
) ENGINE=MyISAM AUTO_INCREMENT=126 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `resulttable`
--

INSERT INTO `resulttable` (`resulltId`, `number`, `theme`, `count`) VALUES
(122, 1, 1, 1),
(123, 1, 2, 1),
(124, 2, 1, 2),
(125, 3, 3, 1);

-- --------------------------------------------------------

--
-- Structure de la table `structure`
--

DROP TABLE IF EXISTS `structure`;
CREATE TABLE IF NOT EXISTS `structure` (
  `identifiant` int(11) NOT NULL,
  `nom` varchar(100) CHARACTER SET utf8 NOT NULL,
  `adresse` int(11) NOT NULL,
  PRIMARY KEY (`identifiant`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `structure`
--

INSERT INTO `structure` (`identifiant`, `nom`, `adresse`) VALUES
(1, 'DSI', 1),
(4, 'DGML', 1);

-- --------------------------------------------------------

--
-- Structure de la table `suggestion`
--

DROP TABLE IF EXISTS `suggestion`;
CREATE TABLE IF NOT EXISTS `suggestion` (
  `number` int(11) NOT NULL AUTO_INCREMENT,
  `date_hour_of_emit` datetime NOT NULL,
  `libelle` varchar(1000) CHARACTER SET utf8mb4 NOT NULL,
  `email` varchar(200) NOT NULL,
  PRIMARY KEY (`number`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `suggestion`
--

INSERT INTO `suggestion` (`number`, `date_hour_of_emit`, `libelle`, `email`) VALUES
(1, '2021-09-04 23:09:00', 'la porte de la salle des Stagiaire (130) est à la DSI est cassée', 'oloukponah@gmail.com'),
(2, '2021-09-05 23:18:00', 'les câbles de connexion internet sont beaucoup trop usés', 'mouleroyinnon@gmail.com'),
(3, '2021-09-06 11:04:00', 'Je suis déçu de l\'acceuil', 'oloukponad@gmail.com');

-- --------------------------------------------------------

--
-- Structure de la table `theme`
--

DROP TABLE IF EXISTS `theme`;
CREATE TABLE IF NOT EXISTS `theme` (
  `identifiant` int(11) NOT NULL,
  `libelle` varchar(100) NOT NULL,
  `category` int(11) NOT NULL,
  PRIMARY KEY (`identifiant`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `theme`
--

INSERT INTO `theme` (`identifiant`, `libelle`, `category`) VALUES
(1, 'informatique', 1),
(2, 'logistique', 1),
(3, 'déception', 2);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
