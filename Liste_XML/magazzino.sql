-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Apr 08, 2019 alle 23:18
-- Versione del server: 10.1.36-MariaDB
-- Versione PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `magazzino`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `magazzini`
--

CREATE TABLE `magazzini` (
  `IdMagazzino` int(11) NOT NULL,
  `Codice` int(11) NOT NULL,
  `Nome` varchar(64) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dump dei dati per la tabella `magazzini`
--

INSERT INTO `magazzini` (`IdMagazzino`, `Codice`, `Nome`) VALUES
(1, 1, 'Nichelino'),
(2, 2, 'Grugliasco'),
(3, 3, 'Torino'),
(4, 4, 'Castiglione');

-- --------------------------------------------------------

--
-- Struttura della tabella `prodotti`
--

CREATE TABLE `prodotti` (
  `IdProdotto` int(11) NOT NULL,
  `Nome` varchar(64) NOT NULL,
  `Quantita` int(11) NOT NULL,
  `descrizione` varchar(255) NOT NULL,
  `Scaffale` int(11) NOT NULL,
  `prezzo` float NOT NULL,
  `collocazione` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dump dei dati per la tabella `prodotti`
--

INSERT INTO `prodotti` (`IdProdotto`, `Nome`, `Quantita`, `descrizione`, `Scaffale`, `prezzo`, `collocazione`) VALUES
(100, 'zaino', 150, 'zaino robusto per il trasporto del PC portatile', 2, 35.99, 1),
(101, 'cassa bluetooth', 1000, 'altoparlante intelligente per ascoltare la musica dove vuoi', 1, 59.99, 1),
(200, 'chitarra epiphone explorer 1984 black', 5, 'chitarra modello explorer in ebano nero edizione limitata', 5, 595, 2),
(201, 'chitarra KH-2 Vintage', 1500, 'chitarra esp signature di kirk hammett', 1, 2099, 2),
(300, 'Razer Blade Stealth', 25000, 'Razer Blade Stealth da 15 pollici Intel Core i7 - 7500u, 16GB RAM, 512GB SSD, Windows 10 nero', 45, 1378.16, 3),
(301, 'DELL XPS 15', 55139, 'Notebook DELL XPS 15 pollici i7-8750H, 16GB RAM, 512 GB SSD, NVIDIA GeForce 1050 Ti, Windows 10 Pro', 88, 1644, 3),
(400, 'uova di pasqua - Latte', 100, 'Uova di Pasqua artigianali vendute dagli scout di Gassino Torinese', 1, 6, 4),
(401, 'uova di Pasqua - Fondente', 50, 'UOva di Pasqua artigianali vendute dagli scout di Gassino Torinese', 2, 6, 4);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `magazzini`
--
ALTER TABLE `magazzini`
  ADD PRIMARY KEY (`IdMagazzino`);

--
-- Indici per le tabelle `prodotti`
--
ALTER TABLE `prodotti`
  ADD PRIMARY KEY (`IdProdotto`),
  ADD KEY `collocazione` (`collocazione`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `magazzini`
--
ALTER TABLE `magazzini`
  MODIFY `IdMagazzino` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT per la tabella `prodotti`
--
ALTER TABLE `prodotti`
  MODIFY `IdProdotto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=402;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `prodotti`
--
ALTER TABLE `prodotti`
  ADD CONSTRAINT `prodotti_ibfk_1` FOREIGN KEY (`collocazione`) REFERENCES `magazzini` (`IdMagazzino`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
