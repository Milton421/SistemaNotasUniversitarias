#pragma once

#include "ConexionBD.h"
#include "ClasesModelo.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

// =========================================
// CONTROLADOR PRINCIPAL
// =========================================

ref class CModelo {

private:

    ConexionBD^ db;

public:

    // =========================================
    // CONSTRUCTOR
    // =========================================

    CModelo();

    bool probarConexion();

    DataTable^ listarEstudiantesCombo();


// CRUD ESTUDIANTES

    DataTable^ listarEstudiantes();

    // CRUD Facultad
    bool insertarFacultad(Facultad^ f);
    bool actualizarFacultad(Facultad^ f);
    bool eliminarFacultad(int id);
    DataTable^ listarFacultades();
    DataTable^ listarFacultadesCombo();

    // CRUD Carrera
    bool insertarCarrera(Carrera^ c);
    bool actualizarCarrera(Carrera^ c);
    bool eliminarCarrera(int id);
    DataTable^ listarCarreras();
    DataTable^ listarCarrerasPorFacultad(int id_facultad);

    String^ generarCarnet();

    bool insertarEstudiante(Estudiante^ nuevo);

    bool actualizarEstudiante(Estudiante^ editado);

    bool eliminarEstudiante(int id);

    // INSCRIPCIONES
    DataTable^ listarInscripcionesCombo();

    DataTable^ listarInscripciones();

    DataTable^ listarSecciones();

    DataTable^ listarSeccionesPorMateria(int id_materia);

    DataTable^ listarInscripcionesPorSeccion(int id_seccion);

    bool insertarInscripcion(Inscripcion^ nueva);

    bool eliminarInscripcion(int id);

    // verifica si ya existe una inscripcion estudiante-seccion
    bool inscripcionExiste(int id_estudiante, int id_seccion);

    // =========================================
    // CRUD NOTAS
    // =========================================

    DataTable^ listarNotas();

    DataTable^ listarNotasPorInscripcion(int id_inscripcion);

    bool insertarNota(Nota^ nuevo);

    bool actualizarNota(Nota^ editada);

    bool eliminarNota(int id);

    double porcentajeTotalPorInscripcion(int id_inscripcion, int excluir_nota_id);

    // ASIGNACION MATERIAS A ESTUDIANTES
    DataTable^ listarAsignaciones();
    DataTable^ listarAsignacionesPorEstudiante(int id_estudiante);

    bool insertarAsignacion(Asignacion^ nueva);

    bool eliminarAsignacion(int id);

    // verifica si ya existe una asignacion estudiante-materia
    bool asignacionExiste(int id_estudiante, int id_materia);

    // =========================================
    // CONSULTAS E INFORMES
    // =========================================

    DataTable^ promedioEstudiantes();

    int numeroAprobados();

    int totalEstudiantes();

    float promedioGeneral();

    float notaMaxima();

    float notaMinima();

    DataTable^ informeGeneral();

    // METODOS POR MATERIA
    DataTable^ listarMaterias();
    DataTable^ listarMateriasPorCarrera(int id_carrera);

    DataTable^ promedioPorMateria(int id_materia);

    int numeroAprobadosPorMateria(int id_materia);

    int totalEstudiantesPorMateria(int id_materia);

    float promedioPorMateriaValor(int id_materia);

    float notaMaximaPorMateria(int id_materia);

    float notaMinimaPorMateria(int id_materia);

    DataTable^ informePorMateria(int id_materia);

    // Diagnóstico / verificación de la integridad básica
    DataTable^ autodiagnostico();

    // =========================================
    // CRUD DOCENTES
    // =========================================

    DataTable^ listarDocentes();

    DataTable^ listarDocentesCombo();

    bool insertarDocente(Docente^ nuevo);

    bool actualizarDocente(Docente^ editado);

    bool eliminarDocente(int id);

    // =========================================
    // CRUD MATERIA (completo)
    // =========================================

    DataTable^ listarMateriasCompleto();

    bool insertarMateria(Materia^ nueva);

    bool actualizarMateria(Materia^ editada);

    bool eliminarMateria(int id);

    // =========================================
    // CRUD CICLO_ACADEMICO
    // =========================================

    DataTable^ listarCiclos();

    DataTable^ listarCiclosCombo();

    bool insertarCiclo(CicloAcademico^ nuevo);

    bool actualizarCiclo(CicloAcademico^ editado);

    bool eliminarCiclo(int id);

    // =========================================
    // CRUD SECCION
    // =========================================

    DataTable^ listarSeccionesCompleto();

    bool insertarSeccion(Seccion^ nueva);

    bool actualizarSeccion(Seccion^ editada);

    bool eliminarSeccion(int id);
};