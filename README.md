# 🎓 SistemaNotasUniversitarias

Un sistema académico completo desarrollado en **C++ (C++/CLI)** con interfaz gráfica en **Windows Forms** y base de datos relacional **MySQL**.

## 📖 Descripción del Proyecto
Este proyecto tiene como objetivo principal gestionar la estructura académica de una universidad. Permite administrar facultades, carreras, materias, estudiantes, docentes y secciones. Su funcionalidad central (Gestión de Notas) proporciona una trazabilidad completa desde que un estudiante se inscribe en una sección hasta que obtiene su calificación final en diversas actividades.

## 🚀 Características Principales

*   **Administración Institucional:** Gestión CRUD (Crear, Leer, Actualizar, Eliminar) para Facultades y Carreras.
*   **Gestión de Usuarios:** Registro de Estudiantes (con generación automática de carnet) y Docentes.
*   **Planificación Académica:** Creación de Materias, Ciclos Académicos y Secciones.
*   **Inscripciones:** Vinculación controlada de Estudiantes a Secciones específicas.
*   **Gestión de Evaluaciones y Notas:** Registro de notas por actividad y cálculo automático según porcentajes.
*   **Informes y Cálculos Académicos:**
    *   Cálculo del promedio de notas por estudiante y por materia.
    *   Conteo de alumnos aprobados (Promedio ≥ 61).
    *   Identificación de nota máxima y mínima general y por materia.
    *   Generación de estado final (Aprobado/Reprobado).

## 🛠️ Tecnologías Utilizadas

*   **Lenguaje:** C++ (C++/CLI para .NET)
*   **Interfaz Gráfica:** Windows Forms (WinForms)
*   **Base de Datos:** MySQL Server (Versión 8.0+)
*   **IDE:** Visual Studio 2022 (con carga de trabajo "Desarrollo para el escritorio con C++" y soporte para C++/CLI)
*   **Conector BD:** MySQL Connector/NET

## ⚙️ Requisitos y Configuración

### 1. Base de Datos
El proyecto incluye un script SQL con la estructura completa y datos de prueba.
1. Abriendo un gestor de base de datos MySQL (ej. MySQL Workbench, XAMPP, etc.).
2. Ejecutando el archivo `gestion_notas_universidad.sql` incluido en el código fuente. Esto creará la base de datos `gestion_notas_universidad` y poblará las tablas con datos iniciales.

### 2. Configuración en Visual Studio
1. Clona este repositorio:
   ```bash
   git clone https://github.com/Milton421/SistemaNotasUniversitarias.git
   ```
2. Abre la solución `ProyectoFinal.sln` con Visual Studio 2022.
3. Asegúrate de tener instalada la extensión o paquete de **MySQL.Data** para poder interactuar con la base de datos.
4. Si tu usuario/contraseña de MySQL local no son los valores por defecto (ej. root/sin clave), modifica la cadena de conexión en la clase `ConexionBD.cpp`.

## 🗄️ Estructura de la Base de Datos
El diseño relacional incluye 10 tablas interconectadas para garantizar la integridad de los datos académicos:
*   `facultad`, `carrera`, `materia`
*   `docente`, `ciclo_academico`, `seccion`
*   `estudiante`, `asignacion_materia`, `inscripcion`, `nota`

*(Puedes consultar el archivo `documentacion_gestion_notas.md` para ver el Diagrama Entidad-Relación y detalles de cada tabla).*


