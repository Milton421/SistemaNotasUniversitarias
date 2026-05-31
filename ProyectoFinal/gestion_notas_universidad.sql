CREATE DATABASE IF NOT EXISTS `gestion_notas_universidad` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `gestion_notas_universidad`;
-- MySQL dump 10.13  Distrib 8.0.41, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: gestion_notas_universidad
-- ------------------------------------------------------
-- Server version	8.0.41

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- =========================================
-- TABLA FACULTAD
-- =========================================

DROP TABLE IF EXISTS `facultad`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `facultad` (
  `id_facultad`     INT          NOT NULL AUTO_INCREMENT,
  `nombre_facultad` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`id_facultad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `facultad`
--

LOCK TABLES `facultad` WRITE;
/*!40000 ALTER TABLE `facultad` DISABLE KEYS */;
INSERT INTO `facultad` VALUES
  (1, 'Ingenieria y Arquitectura'),
  (2, 'Ciencias Economicas'),
  (3, 'Ciencias Juridicas'),
  (4, 'Medicina'),
  (5, 'Humanidades y Ciencias Sociales');
/*!40000 ALTER TABLE `facultad` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA CARRERA
-- =========================================

DROP TABLE IF EXISTS `carrera`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `carrera` (
  `id_carrera`     INT          NOT NULL AUTO_INCREMENT,
  `nombre_carrera` VARCHAR(100) NOT NULL,
  `id_facultad`    INT          NOT NULL,
  PRIMARY KEY (`id_carrera`),
  CONSTRAINT `fk_carrera_facultad`
    FOREIGN KEY (`id_facultad`)
    REFERENCES `facultad` (`id_facultad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `carrera`
--

LOCK TABLES `carrera` WRITE;
/*!40000 ALTER TABLE `carrera` DISABLE KEYS */;
INSERT INTO `carrera` VALUES
  (1, 'Ingenieria en Sistemas Informaticos', 1),
  (2, 'Ingenieria Civil',                    1),
  (3, 'Administracion de Empresas',          2),
  (4, 'Licenciatura en Derecho',             3),
  (5, 'Medicina General',                    4);
/*!40000 ALTER TABLE `carrera` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA DOCENTE
-- =========================================

DROP TABLE IF EXISTS `docente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `docente` (
  `id_docente`   INT          NOT NULL AUTO_INCREMENT,
  `nombres`      VARCHAR(100) NOT NULL,
  `apellidos`    VARCHAR(100) NOT NULL,
  `correo`       VARCHAR(100) DEFAULT NULL,
  `especialidad` VARCHAR(100) DEFAULT NULL,
  PRIMARY KEY (`id_docente`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docente`
--

LOCK TABLES `docente` WRITE;
/*!40000 ALTER TABLE `docente` DISABLE KEYS */;
INSERT INTO `docente` VALUES
  (1, 'Carlos',  'Martinez',  'cmartinez@uni.edu.sv', 'Programacion y Base de Datos'),
  (2, 'Ana',     'Rodriguez', 'arodriguez@uni.edu.sv', 'Matematicas Aplicadas'),
  (3, 'Luis',    'Garcia',    'lgarcia@uni.edu.sv',    'Derecho Civil y Penal'),
  (4, 'Maria',   'Lopez',     'mlopez@uni.edu.sv',     'Anatomia y Fisiologia'),
  (5, 'Jorge',   'Perez',     'jperez@uni.edu.sv',     'Administracion y Finanzas');
/*!40000 ALTER TABLE `docente` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA CICLO_ACADEMICO
-- =========================================

DROP TABLE IF EXISTS `ciclo_academico`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ciclo_academico` (
  `id_ciclo`    INT         NOT NULL AUTO_INCREMENT,
  `nombre_ciclo` VARCHAR(50) NOT NULL,
  `anio`        INT         NOT NULL,
  PRIMARY KEY (`id_ciclo`),
  CONSTRAINT `uq_ciclo` UNIQUE (`nombre_ciclo`, `anio`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ciclo_academico`
--

LOCK TABLES `ciclo_academico` WRITE;
/*!40000 ALTER TABLE `ciclo_academico` DISABLE KEYS */;
INSERT INTO `ciclo_academico` VALUES
  (1, 'Ciclo I',  2026),
  (2, 'Ciclo II', 2025),
  (3, 'Ciclo I',  2025),
  (4, 'Ciclo II', 2024),
  (5, 'Ciclo I',  2024);
/*!40000 ALTER TABLE `ciclo_academico` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA MATERIA
-- =========================================

DROP TABLE IF EXISTS `materia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `materia` (
  `id_materia`     INT         NOT NULL AUTO_INCREMENT,
  `codigo_materia` VARCHAR(20) NOT NULL,
  `nombre_materia` VARCHAR(100) NOT NULL,
  `creditos`       INT         NOT NULL,
  `semestre`       INT         NOT NULL,
  `id_carrera`     INT         NOT NULL,
  PRIMARY KEY (`id_materia`),
  UNIQUE KEY `uq_codigo_materia` (`codigo_materia`),
  CONSTRAINT `fk_materia_carrera`
    FOREIGN KEY (`id_carrera`)
    REFERENCES `carrera` (`id_carrera`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `materia`
--

LOCK TABLES `materia` WRITE;
/*!40000 ALTER TABLE `materia` DISABLE KEYS */;
INSERT INTO `materia` VALUES
  (1, 'INF-101', 'Programacion I',    4, 1, 1),
  (2, 'INF-202', 'Base de Datos',     4, 2, 1),
  (3, 'ADM-101', 'Contabilidad I',    3, 1, 3),
  (4, 'DER-101', 'Derecho Civil',     4, 1, 4),
  (5, 'INF-303', 'Diseno Digital',    3, 3, 1);
/*!40000 ALTER TABLE `materia` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA ESTUDIANTE
-- =========================================

DROP TABLE IF EXISTS `estudiante`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `estudiante` (
  `id_estudiante`   INT         NOT NULL AUTO_INCREMENT,
  `carnet`          VARCHAR(20) NOT NULL,
  `nombres`         VARCHAR(100) NOT NULL,
  `apellidos`       VARCHAR(100) NOT NULL,
  `correo`          VARCHAR(100) DEFAULT NULL,
  `telefono`        VARCHAR(20)  DEFAULT NULL,
  `fecha_nacimiento` DATE        DEFAULT NULL,
  `id_carrera`      INT         NOT NULL,
  PRIMARY KEY (`id_estudiante`),
  UNIQUE KEY `uq_carnet` (`carnet`),
  CONSTRAINT `fk_estudiante_carrera`
    FOREIGN KEY (`id_carrera`)
    REFERENCES `carrera` (`id_carrera`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estudiante`
--

LOCK TABLES `estudiante` WRITE;
/*!40000 ALTER TABLE `estudiante` DISABLE KEYS */;
INSERT INTO `estudiante` VALUES
  (1, '2021-0001', 'Milton',    'Martinez',  'milton@gmail.com',  '7777-0001', '2000-03-15', 1),
  (2, '2021-0002', 'Maria',     'Lopez',     'maria@gmail.com',   '7777-0002', '2001-06-20', 1),
  (3, '2021-0003', 'Juan',      'Garcia',    'juan@gmail.com',    '7777-0003', '2000-11-10', 2),
  (4, '2021-0004', 'Ana',       'Perez',     'ana@gmail.com',     '7777-0004', '2002-01-25', 3),
  (5, '2021-0005', 'Luis',      'Ramos',     'luis@gmail.com',    '7777-0005', '2001-09-05', 1);
/*!40000 ALTER TABLE `estudiante` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA SECCION
-- =========================================

DROP TABLE IF EXISTS `seccion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `seccion` (
  `id_seccion`    INT         NOT NULL AUTO_INCREMENT,
  `nombre_seccion` VARCHAR(20) NOT NULL,
  `jornada`       VARCHAR(50)  DEFAULT NULL,
  `aula`          VARCHAR(20)  DEFAULT NULL,
  `id_materia`    INT         NOT NULL,
  `id_docente`    INT         NOT NULL,
  `id_ciclo`      INT         NOT NULL,
  PRIMARY KEY (`id_seccion`),
  CONSTRAINT `fk_seccion_materia`
    FOREIGN KEY (`id_materia`)
    REFERENCES `materia` (`id_materia`),
  CONSTRAINT `fk_seccion_docente`
    FOREIGN KEY (`id_docente`)
    REFERENCES `docente` (`id_docente`),
  CONSTRAINT `fk_seccion_ciclo`
    FOREIGN KEY (`id_ciclo`)
    REFERENCES `ciclo_academico` (`id_ciclo`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `seccion`
--

LOCK TABLES `seccion` WRITE;
/*!40000 ALTER TABLE `seccion` DISABLE KEYS */;
INSERT INTO `seccion` VALUES
  (1, 'A', 'Matutina',   'A-101', 1, 1, 1),
  (2, 'B', 'Vespertina', 'B-201', 1, 2, 1),
  (3, 'A', 'Matutina',   'C-301', 2, 1, 1),
  (4, 'A', 'Matutina',   'D-101', 3, 5, 1),
  (5, 'A', 'Matutina',   'E-201', 4, 3, 1);
/*!40000 ALTER TABLE `seccion` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA INSCRIPCION
-- =========================================

DROP TABLE IF EXISTS `inscripcion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `inscripcion` (
  `id_inscripcion`   INT  NOT NULL AUTO_INCREMENT,
  `id_estudiante`    INT  NOT NULL,
  `id_seccion`       INT  NOT NULL,
  `fecha_inscripcion` DATE NOT NULL,
  PRIMARY KEY (`id_inscripcion`),
  CONSTRAINT `uq_inscripcion` UNIQUE (`id_estudiante`, `id_seccion`),
  CONSTRAINT `fk_inscripcion_estudiante`
    FOREIGN KEY (`id_estudiante`)
    REFERENCES `estudiante` (`id_estudiante`),
  CONSTRAINT `fk_inscripcion_seccion`
    FOREIGN KEY (`id_seccion`)
    REFERENCES `seccion` (`id_seccion`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inscripcion`
--

LOCK TABLES `inscripcion` WRITE;
/*!40000 ALTER TABLE `inscripcion` DISABLE KEYS */;
INSERT INTO `inscripcion` VALUES
  (1, 1, 1, '2026-01-10'),
  (2, 2, 1, '2026-01-10'),
  (3, 1, 3, '2026-01-11'),
  (4, 3, 2, '2026-01-12'),
  (5, 4, 4, '2026-01-13');
/*!40000 ALTER TABLE `inscripcion` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA ASIGNACION_MATERIA
-- [AGREGADA] Requerida por AsignacionForm.h
-- y Controlador.cpp del proyecto C++.
-- Relaciona directamente un estudiante con
-- una materia (independiente de la seccion).
-- =========================================

DROP TABLE IF EXISTS `asignacion_materia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asignacion_materia` (
  `id_asignacion`   INT  NOT NULL AUTO_INCREMENT,
  `id_estudiante`   INT  NOT NULL,
  `id_materia`      INT  NOT NULL,
  `fecha_asignacion` DATE NOT NULL,
  PRIMARY KEY (`id_asignacion`),
  CONSTRAINT `uq_asignacion` UNIQUE (`id_estudiante`, `id_materia`),
  CONSTRAINT `fk_asignacion_estudiante`
    FOREIGN KEY (`id_estudiante`)
    REFERENCES `estudiante` (`id_estudiante`),
  CONSTRAINT `fk_asignacion_materia`
    FOREIGN KEY (`id_materia`)
    REFERENCES `materia` (`id_materia`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asignacion_materia`
--

LOCK TABLES `asignacion_materia` WRITE;
/*!40000 ALTER TABLE `asignacion_materia` DISABLE KEYS */;
INSERT INTO `asignacion_materia` VALUES
  (1, 1, 1, '2026-01-10'),
  (2, 1, 2, '2026-01-10'),
  (3, 2, 1, '2026-01-10'),
  (4, 3, 3, '2026-01-12'),
  (5, 4, 3, '2026-01-13');
/*!40000 ALTER TABLE `asignacion_materia` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- TABLA NOTA
-- =========================================

DROP TABLE IF EXISTS `nota`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `nota` (
  `id_nota`       INT           NOT NULL AUTO_INCREMENT,
  `id_inscripcion` INT           NOT NULL,
  `actividad`     VARCHAR(100)  NOT NULL,
  `nota_obtenida` DECIMAL(5,2)  NOT NULL,
  `porcentaje`    DECIMAL(5,2)  NOT NULL,
  PRIMARY KEY (`id_nota`),
  CONSTRAINT `fk_nota_inscripcion`
    FOREIGN KEY (`id_inscripcion`)
    REFERENCES `inscripcion` (`id_inscripcion`),
  CONSTRAINT `chk_nota_obtenida`
    CHECK (`nota_obtenida` >= 0 AND `nota_obtenida` <= 100),
  CONSTRAINT `chk_porcentaje`
    CHECK (`porcentaje` >= 0 AND `porcentaje` <= 100)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nota`
--

LOCK TABLES `nota` WRITE;
/*!40000 ALTER TABLE `nota` DISABLE KEYS */;
INSERT INTO `nota` VALUES
  (1, 1, 'Tarea 1',        85.00, 20.00),
  (2, 1, 'Examen Parcial', 72.00, 30.00),
  (3, 2, 'Tarea 1',        90.00, 20.00),
  (4, 3, 'Tarea 1',        68.00, 20.00),
  (5, 4, 'Examen Parcial', 55.00, 30.00);
/*!40000 ALTER TABLE `nota` ENABLE KEYS */;
UNLOCK TABLES;

-- =========================================
-- CONSULTAS SOLICITADAS
-- =========================================

-- =========================================
-- 1. PROMEDIO DE NOTAS POR ESTUDIANTE
-- =========================================

SELECT
    e.id_estudiante,
    e.nombres,
    e.apellidos,
    AVG(n.nota_obtenida) AS promedio
FROM `estudiante` e
INNER JOIN `inscripcion` i
    ON e.id_estudiante = i.id_estudiante
INNER JOIN `nota` n
    ON i.id_inscripcion = n.id_inscripcion
GROUP BY e.id_estudiante, e.nombres, e.apellidos;

-- =========================================
-- 2. NUMERO DE APROBADOS
-- (Promedio >= 61)
-- =========================================

SELECT COUNT(*) AS numero_aprobados
FROM (
    SELECT
        e.id_estudiante,
        AVG(n.nota_obtenida) AS promedio
    FROM `estudiante` e
    INNER JOIN `inscripcion` i
        ON e.id_estudiante = i.id_estudiante
    INNER JOIN `nota` n
        ON i.id_inscripcion = n.id_inscripcion
    GROUP BY e.id_estudiante
    HAVING AVG(n.nota_obtenida) >= 61
) AS aprobados;

-- =========================================
-- 3. NOTA MAXIMA
-- =========================================

SELECT MAX(nota_obtenida) AS nota_maxima
FROM `nota`;

-- =========================================
-- 4. NOTA MINIMA
-- =========================================

SELECT MIN(nota_obtenida) AS nota_minima
FROM `nota`;

-- =========================================
-- 5. INFORME GENERAL DE ESTUDIANTES
-- =========================================

SELECT
    e.carnet,
    CONCAT(e.nombres, ' ', e.apellidos) AS estudiante,
    AVG(n.nota_obtenida)  AS promedio,
    MAX(n.nota_obtenida)  AS nota_maxima,
    MIN(n.nota_obtenida)  AS nota_minima,
    CASE
        WHEN AVG(n.nota_obtenida) >= 61 THEN 'APROBADO'
        ELSE 'REPROBADO'
    END AS estado
FROM `estudiante` e
INNER JOIN `inscripcion` i
    ON e.id_estudiante = i.id_estudiante
INNER JOIN `nota` n
    ON i.id_inscripcion = n.id_inscripcion
GROUP BY e.id_estudiante, e.carnet, e.nombres, e.apellidos;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

