#pragma once
using namespace System;

// =========================================
// CLASE ESTUDIANTE
// =========================================

ref class Estudiante {

public:

    int id_estudiante;
    String^ carnet;
    String^ nombres;
    String^ apellidos;
    String^ correo;
    String^ telefono;
    String^ fecha_nacimiento;
    int id_carrera;

public:

    Estudiante() {}

    Estudiante(
        int _id,
        String^ _carnet,
        String^ _nombres,
        String^ _apellidos,
        String^ _correo,
        String^ _telefono,
        String^ _fecha,
        int _carrera
    ) {

        id_estudiante = _id;
        carnet = _carnet;
        nombres = _nombres;
        apellidos = _apellidos;
        correo = _correo;
        telefono = _telefono;
        fecha_nacimiento = _fecha;
        id_carrera = _carrera;
    }
};

// =========================================
// CLASE ASIGNACION (asignacion_materia)
// =========================================

ref class Asignacion {

public:

    int id_asignacion;
    int id_estudiante;
    int id_materia;
    String^ fecha_asignacion;

public:

    Asignacion() {}

    Asignacion(
        int _id,
        int _estudiante,
        int _materia,
        String^ _fecha
    ) {

        id_asignacion = _id;
        id_estudiante = _estudiante;
        id_materia = _materia;
        fecha_asignacion = _fecha;
    }
};

// =========================================
// CLASE NOTA
// =========================================

ref class Nota {

public:

    int id_nota;
    int id_inscripcion;
    String^ actividad;
    float nota_obtenida;
    float porcentaje;

public:

    Nota() {}

    Nota(
        int _id,
        int _idInscripcion,
        String^ _actividad,
        float _nota,
        float _porcentaje
    ) {

        id_nota = _id;
        id_inscripcion = _idInscripcion;
        actividad = _actividad;
        nota_obtenida = _nota;
        porcentaje = _porcentaje;
    }
};

// =========================================
// CLASE MATERIA
// =========================================

ref class Materia {

public:

    int id_materia;
    String^ codigo_materia;
    String^ nombre_materia;
    int creditos;
    int semestre;
    int id_carrera;

public:

    Materia() {}

    Materia(
        int _id,
        String^ _codigo,
        String^ _nombre,
        int _creditos,
        int _semestre,
        int _idCarrera
    ) {

        id_materia = _id;
        codigo_materia = _codigo;
        nombre_materia = _nombre;
        creditos = _creditos;
        semestre = _semestre;
        id_carrera = _idCarrera;
    }
};

// =========================================
// CLASE INFORME
// =========================================

ref class Informe {

public:

    String^ estudiante;
    float promedio;
    float nota_maxima;
    float nota_minima;
    String^ estado;

public:

    Informe() {}

    Informe(
        String^ _estudiante,
        float _promedio,
        float _maxima,
        float _minima,
        String^ _estado
    ) {

        estudiante = _estudiante;
        promedio = _promedio;
        nota_maxima = _maxima;
        nota_minima = _minima;
        estado = _estado;
    }
};

// =========================================
// CLASE DOCENTE
// =========================================

ref class Docente {

public:

    int id_docente;
    String^ nombres;
    String^ apellidos;
    String^ correo;
    String^ especialidad;

public:

    Docente() {}

    Docente(
        int _id,
        String^ _nombres,
        String^ _apellidos,
        String^ _correo,
        String^ _especialidad
    ) {
        id_docente   = _id;
        nombres      = _nombres;
        apellidos    = _apellidos;
        correo       = _correo;
        especialidad = _especialidad;
    }
};

ref class Inscripcion {

public:

    int id_inscripcion;
    int id_estudiante;
    int id_seccion;
    String^ fecha_inscripcion;

public:

    Inscripcion() {}

    Inscripcion(
        int _id,
        int _estudiante,
        int _seccion,
        String^ _fecha
    ) {

        id_inscripcion = _id;
        id_estudiante = _estudiante;
        id_seccion = _seccion;
        fecha_inscripcion = _fecha;
    }
};

// =========================================
// CLASE CICLO_ACADEMICO
// =========================================

ref class CicloAcademico {

public:

    int     id_ciclo;
    String^ nombre_ciclo;
    int     anio;

public:

    CicloAcademico() {}

    CicloAcademico(
        int     _id,
        String^ _nombre,
        int     _anio
    ) {
        id_ciclo    = _id;
        nombre_ciclo = _nombre;
        anio        = _anio;
    }
};

// =========================================
// CLASE SECCION
// =========================================

ref class Seccion {

public:

    int     id_seccion;
    String^ nombre_seccion;
    String^ jornada;
    String^ aula;
    int     id_materia;
    int     id_docente;
    int     id_ciclo;

public:

    Seccion() {}

    Seccion(
        int     _id,
        String^ _nombre,
        String^ _jornada,
        String^ _aula,
        int     _materia,
        int     _docente,
        int     _ciclo
    ) {
        id_seccion    = _id;
        nombre_seccion = _nombre;
        jornada       = _jornada;
        aula          = _aula;
        id_materia    = _materia;
        id_docente    = _docente;
        id_ciclo      = _ciclo;
    }
};
// =========================================
// CLASE FACULTAD
// =========================================
ref class Facultad {
public:
    int id_facultad;
    System::String^ nombre_facultad;

    Facultad() {}

    Facultad(int _id, System::String^ _nombre) {
        id_facultad = _id;
        nombre_facultad = _nombre;
    }
};

// =========================================
// CLASE CARRERA
// =========================================
ref class Carrera {
public:
    int id_carrera;
    System::String^ nombre_carrera;
    int id_facultad;

    Carrera() {}

    Carrera(int _id, System::String^ _nombre, int _idFacultad) {
        id_carrera = _id;
        nombre_carrera = _nombre;
        id_facultad = _idFacultad;
    }
};

