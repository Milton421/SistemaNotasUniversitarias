#include "Controlador.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
// =========================================
// CONSTRUCTOR
// =========================================

CModelo::CModelo() {
    db = gcnew ConexionBD();
}

bool CModelo::probarConexion() {
    return db->conexionActiva();
}

DataTable^ CModelo::listarAsignacionesPorEstudiante(int id_estudiante) {

    String^ sql =
        "SELECT a.id_asignacion, a.id_estudiante, a.id_materia, m.nombre_materia, a.fecha_asignacion FROM asignacion_materia a "
        "INNER JOIN materia m ON a.id_materia = m.id_materia "
        "WHERE a.id_estudiante = " + id_estudiante;

    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }

    return gcnew DataTable();
}

bool CModelo::asignacionExiste(int id_estudiante, int id_materia) {
    try {
        String^ sql = "SELECT COUNT(*) AS c FROM asignacion_materia WHERE id_estudiante = " + id_estudiante + " AND id_materia = " + id_materia;
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToInt32(fila["c"]->ToString()) > 0;
        }
    }
    catch (Exception^) {}
    return false;
}

// =========================================
// ASIGNACION
// =========================================

DataTable^ CModelo::listarAsignaciones() {

    String^ sql =
        "SELECT a.id_asignacion, a.id_estudiante, CONCAT(e.nombres,' ',e.apellidos) AS estudiante, a.id_materia, m.nombre_materia, a.fecha_asignacion FROM asignacion_materia a "
        "INNER JOIN estudiante e ON a.id_estudiante = e.id_estudiante "
        "INNER JOIN materia m ON a.id_materia = m.id_materia";

    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }

    return gcnew DataTable();
}

bool CModelo::insertarAsignacion(Asignacion^ nueva) {

    try {

        String^ sql =
            "INSERT INTO asignacion_materia (id_estudiante, id_materia, fecha_asignacion) VALUES (@estudiante, @materia, @fecha)";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@estudiante", nueva->id_estudiante);
        cmd->Parameters->AddWithValue("@materia", nueva->id_materia);
        cmd->Parameters->AddWithValue("@fecha", nueva->fecha_asignacion);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::eliminarAsignacion(int id) {

    try {

        String^ sql =
            "DELETE FROM asignacion_materia WHERE id_asignacion = @id";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@id", id);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// LISTAR ESTUDIANTES
// =========================================

DataTable^ CModelo::listarEstudiantesCombo() {

    String^ sql =
        "SELECT id_estudiante, "
        "CONCAT(nombres,' ',apellidos) "
        "AS estudiante "
        "FROM estudiante";

    return db->ejecutaConsultaTabla(sql);
}

DataTable^ CModelo::autodiagnostico() {

    // Devuelve un DataTable con conteos basicos y estado de conexion
    DataTable^ dt = gcnew DataTable();
    dt->Columns->Add("entidad");
    dt->Columns->Add("conteo");

    try {
        if (!db->conexionActiva()) {
            DataRow^ r = dt->NewRow();
            r["entidad"] = "conexion";
            r["conteo"] = "inactiva";
            dt->Rows->Add(r);
            return dt;
        }

        array<String^>^ tablas = gcnew array<String^>{ "estudiante", "materia", "seccion", "inscripcion", "nota" };

        for each (String ^ t in tablas) {
            String^ sql = "SELECT COUNT(*) AS c FROM " + t;
            DataTable^ rdt = db->ejecutaConsultaTabla(sql);
            int c = 0;
            if (rdt->Rows->Count > 0) {
                DataRow^ tempFila = rdt->Rows[0];
                c = Convert::ToInt32(tempFila["c"]->ToString());
            }
            DataRow^ r = dt->NewRow();
            r["entidad"] = t;
            r["conteo"] = c.ToString();
            dt->Rows->Add(r);
        }

        // comprobar consultas principales
        DataRow^ rr = dt->NewRow();
        rr["entidad"] = "promedio_existente";
        try {
            DataTable^ pd = this->promedioEstudiantes();
            rr["conteo"] = pd->Rows->Count.ToString();
        }
        catch (Exception^) {
            rr["conteo"] = "error";
        }
        dt->Rows->Add(rr);

        return dt;
    }
    catch (Exception^ ex) {
        DataRow^ r = dt->NewRow();
        r["entidad"] = "error";
        r["conteo"] = ex->Message;
        dt->Rows->Add(r);
        return dt;
    }
}

DataTable^ CModelo::listarSeccionesPorMateria(int id_materia) {

    String^ sql =
        "SELECT id_seccion, nombre_seccion FROM seccion WHERE id_materia = " + id_materia;

    return db->ejecutaConsultaTabla(sql);
}

DataTable^ CModelo::listarInscripcionesPorSeccion(int id_seccion) {

    // Devolver id_inscripcion, id_estudiante, nombre completo del estudiante y nombre de seccion
    String^ sql =
        "SELECT i.id_inscripcion, i.id_estudiante, CONCAT(e.nombres,' ',e.apellidos) AS estudiante, s.nombre_seccion "
        "FROM inscripcion i "
        "INNER JOIN estudiante e ON i.id_estudiante = e.id_estudiante "
        "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
        "WHERE i.id_seccion = " + id_seccion;

    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// LISTAR MATERIAS
// =========================================

DataTable^ CModelo::listarMaterias() {

    String^ sql =
        "SELECT id_materia, nombre_materia FROM materia";

    return db->ejecutaConsultaTabla(sql);
}

DataTable^ CModelo::listarMateriasPorCarrera(int id_carrera) {
    String^ sql =
        "SELECT id_materia, nombre_materia FROM materia WHERE id_carrera = " + id_carrera;
    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// PROMEDIO POR MATERIA
// =========================================

DataTable^ CModelo::promedioPorMateria(int id_materia) {

    String^ sql =
        "SELECT e.id_estudiante, CONCAT(e.nombres,' ',e.apellidos) AS estudiante, "
        "AVG(n.nota_obtenida) AS promedio "
        "FROM estudiante e "
        "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
        "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
        "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
        "WHERE s.id_materia = " + id_materia +
        " GROUP BY e.id_estudiante";

    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// NUMERO APROBADOS POR MATERIA
// =========================================

int CModelo::numeroAprobadosPorMateria(int id_materia) {

    try {
        String^ sql =
            "SELECT COUNT(*) AS numero_aprobados FROM ("
            "SELECT AVG(n.nota_obtenida) AS promedio "
            "FROM estudiante e "
            "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
            "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
            "WHERE s.id_materia = " + id_materia +
            " GROUP BY e.id_estudiante HAVING AVG(n.nota_obtenida) >= 61"
            ") AS aprobados";

        DataTable^ dt = db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToInt32(fila["numero_aprobados"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {
        return 0;
    }
}

// =========================================
// NOTA MAXIMA POR MATERIA
// =========================================

float CModelo::notaMaximaPorMateria(int id_materia) {

    try {
        String^ sql =
            "SELECT MAX(n.nota_obtenida) AS maxima "
            "FROM nota n "
            "INNER JOIN inscripcion i ON n.id_inscripcion = i.id_inscripcion "
            "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
            "WHERE s.id_materia = " + id_materia;

        DataTable^ dt = db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToSingle(fila["maxima"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {
        return 0;
    }
}

// =========================================
// NOTA MINIMA POR MATERIA
// =========================================

float CModelo::notaMinimaPorMateria(int id_materia) {

    try {
        String^ sql =
            "SELECT MIN(n.nota_obtenida) AS minima "
            "FROM nota n "
            "INNER JOIN inscripcion i ON n.id_inscripcion = i.id_inscripcion "
            "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
            "WHERE s.id_materia = " + id_materia;

        DataTable^ dt = db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToSingle(fila["minima"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {
        return 0;
    }
}

// =========================================
// INFORME POR MATERIA
// =========================================

DataTable^ CModelo::informePorMateria(int id_materia) {

    String^ sql =
        "SELECT e.carnet, CONCAT(e.nombres,' ',e.apellidos) AS estudiante, "
        "AVG(n.nota_obtenida) AS promedio, MAX(n.nota_obtenida) AS maxima, MIN(n.nota_obtenida) AS minima, "
        "CASE WHEN AVG(n.nota_obtenida) >= 61 THEN 'APROBADO' ELSE 'REPROBADO' END AS estado "
        "FROM estudiante e "
        "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
        "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
        "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
        "WHERE s.id_materia = " + id_materia +
        " GROUP BY e.id_estudiante, e.carnet, e.nombres, e.apellidos";

    return db->ejecutaConsultaTabla(sql);
}

DataTable^ CModelo::listarInscripcionesCombo() {

    String^ sql =
        "SELECT "
        "i.id_inscripcion, "
        "CONCAT(e.nombres,' ',e.apellidos,"
        "' - ',s.nombre_seccion) "
        "AS detalle "
        "FROM inscripcion i "
        "INNER JOIN estudiante e "
        "ON i.id_estudiante=e.id_estudiante "
        "INNER JOIN seccion s "
        "ON i.id_seccion=s.id_seccion";

    return db->ejecutaConsultaTabla(sql);
}

DataTable^ CModelo::listarEstudiantes() {

    String^ sql =
        "SELECT "
        "e.id_estudiante, "
        "e.carnet, "
        "e.nombres, "
        "e.apellidos, "
        "e.correo, "
        "e.telefono, "
        "e.fecha_nacimiento, "
        "e.id_carrera, "
        "c.nombre_carrera as carrera "
        "FROM estudiante e "
        "LEFT JOIN carrera c ON e.id_carrera = c.id_carrera";

    try {

        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }

    return gcnew DataTable();
}

DataTable^ CModelo::listarNotasPorInscripcion(int id_inscripcion) {

    String^ sql =
        "SELECT id_nota, id_inscripcion, actividad, nota_obtenida, porcentaje FROM nota "
        "WHERE id_inscripcion = " + id_inscripcion;

    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// GENERAR CARNET AUTOMATICO
// =========================================
String^ CModelo::generarCarnet() {
    String^ year = DateTime::Now.Year.ToString();
    String^ sql = "SELECT MAX(carnet) as last_carnet FROM estudiante WHERE carnet LIKE '" + year + "-%'";
    try {
        if (db->conexionActiva()) {
            DataTable^ dt = db->ejecutaConsultaTabla(sql);
            if (dt != nullptr && dt->Rows->Count > 0) {
                DataRow^ fila = dt->Rows[0];
                Object^ val = fila["last_carnet"];
                if (val != DBNull::Value) {
                    String^ lastCarnet = val->ToString();
                    array<String^>^ parts = lastCarnet->Split('-');
                    if (parts->Length == 2) {
                        int num = Convert::ToInt32(parts[1]) + 1;
                        return year + "-" + num.ToString("D4");
                    }
                }
            }
        }
    } catch (Exception^) {}
    
    return year + "-0001";
}

// =========================================
// INSERTAR ESTUDIANTE
// =========================================

bool CModelo::insertarEstudiante(Estudiante^ nuevo) {

    try {

        String^ sql =
            "INSERT INTO estudiante "
            "(carnet, nombres, apellidos, correo, telefono, fecha_nacimiento, id_carrera) "
            "VALUES "
            "(@carnet, @nombres, @apellidos, @correo, @telefono, @fecha, @id_carrera)";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@carnet", nuevo->carnet);
        cmd->Parameters->AddWithValue("@nombres", nuevo->nombres);
        cmd->Parameters->AddWithValue("@apellidos", nuevo->apellidos);
        cmd->Parameters->AddWithValue("@correo", nuevo->correo);
        cmd->Parameters->AddWithValue("@telefono", nuevo->telefono);
        cmd->Parameters->AddWithValue("@fecha", nuevo->fecha_nacimiento);
        cmd->Parameters->AddWithValue("@id_carrera", nuevo->id_carrera);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) {

        return false;
    }
}

// =========================================
// ACTUALIZAR ESTUDIANTE
// =========================================

bool CModelo::actualizarEstudiante(Estudiante^ editado) {

    try {

        String^ sql =
            "UPDATE estudiante SET "
            "carnet = @carnet, "
            "nombres = @nombres, "
            "apellidos = @apellidos, "
            "correo = @correo, "
            "telefono = @telefono, "
            "fecha_nacimiento = @fecha, "
            "id_carrera = @id_carrera "
            "WHERE id_estudiante = @id";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@carnet", editado->carnet);
        cmd->Parameters->AddWithValue("@nombres", editado->nombres);
        cmd->Parameters->AddWithValue("@apellidos", editado->apellidos);
        cmd->Parameters->AddWithValue("@correo", editado->correo);
        cmd->Parameters->AddWithValue("@telefono", editado->telefono);
        cmd->Parameters->AddWithValue("@fecha", editado->fecha_nacimiento);
        cmd->Parameters->AddWithValue("@id_carrera", editado->id_carrera);
        cmd->Parameters->AddWithValue("@id", editado->id_estudiante);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) {

        return false;
    }
}

// =========================================
// ELIMINAR ESTUDIANTE
// =========================================

bool CModelo::eliminarEstudiante(int id) {

    try {

        // Eliminar notas asociadas a las inscripciones del estudiante
        String^ sql1 = "DELETE FROM nota WHERE id_inscripcion IN (SELECT id_inscripcion FROM inscripcion WHERE id_estudiante = @id)";
        MySqlCommand^ cmd1 = gcnew MySqlCommand(sql1);
        cmd1->Parameters->AddWithValue("@id", id);
        db->ejecutaIUD(cmd1);

        // Eliminar inscripciones del estudiante
        String^ sql2 = "DELETE FROM inscripcion WHERE id_estudiante = @id";
        MySqlCommand^ cmd2 = gcnew MySqlCommand(sql2);
        cmd2->Parameters->AddWithValue("@id", id);
        db->ejecutaIUD(cmd2);

        // Eliminar asignaciones de materia del estudiante
        String^ sql3 = "DELETE FROM asignacion_materia WHERE id_estudiante = @id";
        MySqlCommand^ cmd3 = gcnew MySqlCommand(sql3);
        cmd3->Parameters->AddWithValue("@id", id);
        db->ejecutaIUD(cmd3);

        // Finalmente, eliminar el estudiante
        String^ sql =
            "DELETE FROM estudiante "
            "WHERE id_estudiante = @id";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) {

        return false;
    }
}

DataTable^ CModelo::listarCarreras() {

    String^ sql =
        "SELECT c.id_carrera, c.nombre_carrera, f.nombre_facultad, c.id_facultad "
        "FROM carrera c "
        "INNER JOIN facultad f ON c.id_facultad = f.id_facultad";

    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }

    return gcnew DataTable();
}

DataTable^ CModelo::listarCarrerasPorFacultad(int id_facultad) {
    String^ sql =
        "SELECT id_carrera, nombre_carrera FROM carrera WHERE id_facultad = " + id_facultad;
    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }
    return gcnew DataTable();
}

// INSCRIPCIONES

DataTable^ CModelo::listarSecciones() {

    String^ sql =
        "SELECT id_seccion, nombre_seccion "
        "FROM seccion";

    return db->ejecutaConsultaTabla(sql);
}

bool CModelo::insertarInscripcion(
    Inscripcion^ nueva) {

    try {

        String^ sql =
            "INSERT INTO inscripcion "
            "(id_estudiante, id_seccion, fecha_inscripcion) "
            "VALUES "
            "(@estudiante, @seccion, @fecha)";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue(
            "@estudiante",
            nueva->id_estudiante);

        cmd->Parameters->AddWithValue(
            "@seccion",
            nueva->id_seccion);

        cmd->Parameters->AddWithValue(
            "@fecha",
            nueva->fecha_inscripcion);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {

        MessageBox::Show(ex->Message);

        return false;
    }
}

DataTable^ CModelo::listarInscripciones() {

    String^ sql =
        "SELECT "
        "i.id_inscripcion, "
        "e.nombres, "
        "e.apellidos, "
        "s.nombre_seccion, "
        "i.fecha_inscripcion "
        "FROM inscripcion i "
        "INNER JOIN estudiante e "
        "ON i.id_estudiante = e.id_estudiante "
        "INNER JOIN seccion s "
        "ON i.id_seccion = s.id_seccion";

    return db->ejecutaConsultaTabla(sql);
}

bool CModelo::eliminarInscripcion(int id) {

    try {

        String^ sql =
            "DELETE FROM inscripcion "
            "WHERE id_inscripcion=@id";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue(
            "@id",
            id);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {

        MessageBox::Show(ex->Message);

        return false;
    }
}

// =========================================
// LISTAR NOTAS
// =========================================

DataTable^ CModelo::listarNotas() {

    String^ sql =
        "SELECT "
        "id_nota, "
        "id_inscripcion, "
        "actividad, "
        "nota_obtenida, "
        "porcentaje "
        "FROM nota";

    try {

        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {
    }

    return gcnew DataTable();
}

// =========================================
// OBTENER PORCENTAJE TOTAL POR INSCRIPCION
// =========================================

double CModelo::porcentajeTotalPorInscripcion(int id_inscripcion, int excluir_nota_id) {
    double total = 0.0;
    try {
        String^ sql = "SELECT SUM(porcentaje) AS total FROM nota WHERE id_inscripcion = " + id_inscripcion;
        if (excluir_nota_id > 0) {
            sql += " AND id_nota != " + excluir_nota_id;
        }
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt != nullptr && dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            Object^ val = fila["total"];
            if (val != DBNull::Value) {
                total = Convert::ToDouble(val);
            }
        }
    }
    catch (Exception^) {}
    return total;
}

// =========================================
// INSERTAR NOTA
// =========================================

bool CModelo::insertarNota(Nota^ nueva) {

    try {

        String^ sql =
            "INSERT INTO nota "
            "(id_inscripcion,actividad,"
            "nota_obtenida,porcentaje) "
            "VALUES "
            "(@inscripcion,@actividad,"
            "@nota,@porcentaje)";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue(
            "@inscripcion",
            nueva->id_inscripcion);

        cmd->Parameters->AddWithValue(
            "@actividad",
            nueva->actividad);

        cmd->Parameters->AddWithValue(
            "@nota",
            nueva->nota_obtenida);

        cmd->Parameters->AddWithValue(
            "@porcentaje",
            nueva->porcentaje);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {

        MessageBox::Show(ex->Message);

        return false;
    }
}

bool CModelo::actualizarNota(
    Nota^ editada) {

    try {

        String^ sql =
            "UPDATE nota SET "
            "actividad = @actividad, "
            "nota_obtenida = @nota, "
            "porcentaje = @porcentaje "
            "WHERE id_nota = @id";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue(
            "@actividad",
            editada->actividad);

        cmd->Parameters->AddWithValue(
            "@nota",
            editada->nota_obtenida);

        cmd->Parameters->AddWithValue(
            "@porcentaje",
            editada->porcentaje);

        cmd->Parameters->AddWithValue(
            "@id",
            editada->id_nota);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {

        MessageBox::Show(ex->Message);

        return false;
    }
}

bool CModelo::eliminarNota(int id) {

    try {

        String^ sql =
            "DELETE FROM nota "
            "WHERE id_nota = @id";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue(
            "@id",
            id);

        return db->ejecutaIUD(cmd) > 0;
    }
    catch (Exception^ ex) {

        MessageBox::Show(ex->Message);

        return false;
    }
}

// =========================================
// PROMEDIO DE ESTUDIANTES
// =========================================

DataTable^ CModelo::promedioEstudiantes() {

    String^ sql =
        "SELECT "
        "e.carnet, "
        "CONCAT(e.nombres, ' ', e.apellidos) AS estudiante, "
        "AVG(n.nota_obtenida) AS promedio "
        "FROM estudiante e "
        "INNER JOIN inscripcion i "
        "ON e.id_estudiante = i.id_estudiante "
        "INNER JOIN nota n "
        "ON i.id_inscripcion = n.id_inscripcion "
        "GROUP BY e.id_estudiante";

    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// NUMERO DE APROBADOS
// =========================================

int CModelo::numeroAprobados() {

    try {

        String^ sql =
            "SELECT COUNT(*) AS aprobados "
            "FROM ( "
            "SELECT AVG(n.nota_obtenida) AS promedio "
            "FROM estudiante e "
            "INNER JOIN inscripcion i "
            "ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN nota n "
            "ON i.id_inscripcion = n.id_inscripcion "
            "GROUP BY e.id_estudiante "
            "HAVING AVG(n.nota_obtenida) >= 61 "
            ") AS tabla_aprobados";

        DataTable^ dt =
            db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {

            DataRow^ fila =
                dt->Rows[0];

            return Convert::ToInt32(
                fila["aprobados"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {

        return 0;
    }
}

// =========================================
// TOTAL ESTUDIANTES (general)
// =========================================

int CModelo::totalEstudiantes() {
    try {
        String^ sql =
            "SELECT COUNT(DISTINCT e.id_estudiante) AS total "
            "FROM estudiante e "
            "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion";
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToInt32(fila["total"]->ToString());
        }
        return 0;
    } catch (Exception^) { return 0; }
}

// =========================================
// PROMEDIO GENERAL
// =========================================

float CModelo::promedioGeneral() {
    try {
        String^ sql =
            "SELECT AVG(sub.promedio) AS prom_general FROM ("
            "SELECT AVG(n.nota_obtenida) AS promedio "
            "FROM estudiante e "
            "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
            "GROUP BY e.id_estudiante) AS sub";
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            if (fila["prom_general"] != DBNull::Value) {
                return Convert::ToSingle(fila["prom_general"]->ToString());
            }
        }
        return 0.0f;
    } catch (Exception^) { return 0.0f; }
}

// =========================================
// TOTAL ESTUDIANTES POR MATERIA
// =========================================

int CModelo::totalEstudiantesPorMateria(int id_materia) {
    try {
        String^ sql =
            "SELECT COUNT(DISTINCT e.id_estudiante) AS total "
            "FROM estudiante e "
            "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
            "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
            "WHERE s.id_materia = " + id_materia.ToString();
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToInt32(fila["total"]->ToString());
        }
        return 0;
    } catch (Exception^) { return 0; }
}

// =========================================
// PROMEDIO POR MATERIA (valor float)
// =========================================

float CModelo::promedioPorMateriaValor(int id_materia) {
    try {
        String^ sql =
            "SELECT AVG(sub.promedio) AS prom FROM ("
            "SELECT AVG(n.nota_obtenida) AS promedio "
            "FROM estudiante e "
            "INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante "
            "INNER JOIN seccion s ON i.id_seccion = s.id_seccion "
            "INNER JOIN nota n ON i.id_inscripcion = n.id_inscripcion "
            "WHERE s.id_materia = " + id_materia.ToString() + " "
            "GROUP BY e.id_estudiante) AS sub";
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            if (fila["prom"] != DBNull::Value) {
                return Convert::ToSingle(fila["prom"]->ToString());
            }
        }
        return 0.0f;
    } catch (Exception^) { return 0.0f; }
}

// =========================================
// NOTA MAXIMA
// =========================================

float CModelo::notaMaxima() {

    try {

        String^ sql =
            "SELECT MAX(nota_obtenida) AS maxima "
            "FROM nota";

        DataTable^ dt =
            db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {

            DataRow^ fila =
                dt->Rows[0];

            return Convert::ToSingle(
                fila["maxima"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {

        return 0;
    }
}

// =========================================
// NOTA MINIMA
// =========================================

float CModelo::notaMinima() {

    try {

        String^ sql =
            "SELECT MIN(nota_obtenida) AS minima "
            "FROM nota";

        DataTable^ dt =
            db->ejecutaConsultaTabla(sql);

        if (dt->Rows->Count > 0) {

            DataRow^ fila =
                dt->Rows[0];

            return Convert::ToSingle(
                fila["minima"]->ToString());
        }

        return 0;
    }
    catch (Exception^) {

        return 0;
    }
}

// =========================================
// INFORME GENERAL
// =========================================

DataTable^ CModelo::informeGeneral() {

    String^ sql =
        "SELECT "
        "e.carnet, "
        "CONCAT(e.nombres,' ',e.apellidos) "
        "AS estudiante, "
        "AVG(n.nota_obtenida) AS promedio, "
        "MAX(n.nota_obtenida) AS maxima, "
        "MIN(n.nota_obtenida) AS minima, "
        "CASE WHEN AVG(n.nota_obtenida) >= 61 THEN 'APROBADO' ELSE 'REPROBADO' END AS estado "
        "FROM estudiante e "
        "INNER JOIN inscripcion i "
        "ON e.id_estudiante=i.id_estudiante "
        "INNER JOIN nota n "
        "ON i.id_inscripcion=n.id_inscripcion "
        "GROUP BY e.id_estudiante, e.carnet, e.nombres, e.apellidos";

    return db->ejecutaConsultaTabla(sql);
}

// =========================================
// LISTAR DOCENTES
// =========================================

DataTable^ CModelo::listarDocentes() {

    String^ sql =
        "SELECT "
        "id_docente, "
        "nombres, "
        "apellidos, "
        "correo, "
        "especialidad "
        "FROM docente";

    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {}

    return gcnew DataTable();
}

// =========================================
// LISTAR DOCENTES COMBO
// =========================================

DataTable^ CModelo::listarDocentesCombo() {

    String^ sql =
        "SELECT id_docente, "
        "CONCAT(nombres,' ',apellidos) AS docente "
        "FROM docente";

    try {
        if (db->conexionActiva()) {
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^) {}

    return gcnew DataTable();
}

// =========================================
// INSERTAR DOCENTE
// =========================================

bool CModelo::insertarDocente(Docente^ nuevo) {

    try {

        String^ sql =
            "INSERT INTO docente "
            "(nombres, apellidos, correo, especialidad) "
            "VALUES "
            "(@nombres, @apellidos, @correo, @especialidad)";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@nombres",      nuevo->nombres);
        cmd->Parameters->AddWithValue("@apellidos",    nuevo->apellidos);
        cmd->Parameters->AddWithValue("@correo",       nuevo->correo);
        cmd->Parameters->AddWithValue("@especialidad", nuevo->especialidad);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// ACTUALIZAR DOCENTE
// =========================================

bool CModelo::actualizarDocente(Docente^ editado) {

    try {

        String^ sql =
            "UPDATE docente SET "
            "nombres      = @nombres, "
            "apellidos    = @apellidos, "
            "correo       = @correo, "
            "especialidad = @especialidad "
            "WHERE id_docente = @id";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@nombres",      editado->nombres);
        cmd->Parameters->AddWithValue("@apellidos",    editado->apellidos);
        cmd->Parameters->AddWithValue("@correo",       editado->correo);
        cmd->Parameters->AddWithValue("@especialidad", editado->especialidad);
        cmd->Parameters->AddWithValue("@id",           editado->id_docente);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// ELIMINAR DOCENTE
// =========================================

bool CModelo::eliminarDocente(int id) {

    try {

        String^ sql =
            "DELETE FROM docente "
            "WHERE id_docente = @id";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql);

        cmd->Parameters->AddWithValue("@id", id);

        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// VERIFICAR INSCRIPCION DUPLICADA
// =========================================

bool CModelo::inscripcionExiste(int id_estudiante, int id_seccion) {
    try {
        String^ sql = "SELECT COUNT(*) AS c FROM inscripcion WHERE id_estudiante = " + id_estudiante + " AND id_seccion = " + id_seccion;
        DataTable^ dt = db->ejecutaConsultaTabla(sql);
        if (dt->Rows->Count > 0) {
            DataRow^ fila = dt->Rows[0];
            return Convert::ToInt32(fila["c"]->ToString()) > 0;
        }
    }
    catch (Exception^) {}
    return false;
}

// =========================================
// CRUD MATERIA (completo)
// =========================================

DataTable^ CModelo::listarMateriasCompleto() {
    String^ sql =
        "SELECT m.id_materia, m.codigo_materia, m.nombre_materia, m.creditos, m.semestre, "
        "m.id_carrera, c.nombre_carrera "
        "FROM materia m "
        "INNER JOIN carrera c ON m.id_carrera = c.id_carrera";
    try {
        if (db->conexionActiva())
            return db->ejecutaConsultaTabla(sql);
    }
    catch (Exception^) {}
    return gcnew DataTable();
}

bool CModelo::insertarMateria(Materia^ nueva) {
    try {
        String^ sql =
            "INSERT INTO materia (codigo_materia, nombre_materia, creditos, semestre, id_carrera) "
            "VALUES (@codigo, @nombre, @creditos, @semestre, @carrera)";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@codigo",   nueva->codigo_materia);
        cmd->Parameters->AddWithValue("@nombre",   nueva->nombre_materia);
        cmd->Parameters->AddWithValue("@creditos", nueva->creditos);
        cmd->Parameters->AddWithValue("@semestre", nueva->semestre);
        cmd->Parameters->AddWithValue("@carrera",  nueva->id_carrera);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::actualizarMateria(Materia^ editada) {
    try {
        String^ sql =
            "UPDATE materia SET "
            "codigo_materia = @codigo, "
            "nombre_materia = @nombre, "
            "creditos = @creditos, "
            "semestre = @semestre, "
            "id_carrera = @carrera "
            "WHERE id_materia = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@codigo",   editada->codigo_materia);
        cmd->Parameters->AddWithValue("@nombre",   editada->nombre_materia);
        cmd->Parameters->AddWithValue("@creditos", editada->creditos);
        cmd->Parameters->AddWithValue("@semestre", editada->semestre);
        cmd->Parameters->AddWithValue("@carrera",  editada->id_carrera);
        cmd->Parameters->AddWithValue("@id",       editada->id_materia);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::eliminarMateria(int id) {
    try {
        String^ sql = "DELETE FROM materia WHERE id_materia = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// CRUD CICLO_ACADEMICO
// =========================================

DataTable^ CModelo::listarCiclos() {
    String^ sql =
        "SELECT id_ciclo, nombre_ciclo, anio FROM ciclo_academico ORDER BY anio DESC, nombre_ciclo";
    try {
        if (db->conexionActiva())
            return db->ejecutaConsultaTabla(sql);
    }
    catch (Exception^) {}
    return gcnew DataTable();
}

DataTable^ CModelo::listarCiclosCombo() {
    String^ sql =
        "SELECT id_ciclo, CONCAT(nombre_ciclo, ' - ', anio) AS ciclo "
        "FROM ciclo_academico ORDER BY anio DESC, nombre_ciclo";
    try {
        if (db->conexionActiva())
            return db->ejecutaConsultaTabla(sql);
    }
    catch (Exception^) {}
    return gcnew DataTable();
}

bool CModelo::insertarCiclo(CicloAcademico^ nuevo) {
    try {
        String^ sql =
            "INSERT INTO ciclo_academico (nombre_ciclo, anio) VALUES (@nombre, @anio)";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", nuevo->nombre_ciclo);
        cmd->Parameters->AddWithValue("@anio",   nuevo->anio);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::actualizarCiclo(CicloAcademico^ editado) {
    try {
        String^ sql =
            "UPDATE ciclo_academico SET nombre_ciclo = @nombre, anio = @anio WHERE id_ciclo = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", editado->nombre_ciclo);
        cmd->Parameters->AddWithValue("@anio",   editado->anio);
        cmd->Parameters->AddWithValue("@id",     editado->id_ciclo);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::eliminarCiclo(int id) {
    try {
        String^ sql = "DELETE FROM ciclo_academico WHERE id_ciclo = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// CRUD SECCION
// =========================================

DataTable^ CModelo::listarSeccionesCompleto() {
    String^ sql =
        "SELECT s.id_seccion, s.nombre_seccion, s.jornada, s.aula, "
        "s.id_materia, m.nombre_materia, "
        "s.id_docente, CONCAT(d.nombres,' ',d.apellidos) AS docente, "
        "s.id_ciclo, CONCAT(c.nombre_ciclo,' - ',c.anio) AS ciclo "
        "FROM seccion s "
        "INNER JOIN materia m ON s.id_materia = m.id_materia "
        "INNER JOIN docente d ON s.id_docente = d.id_docente "
        "INNER JOIN ciclo_academico c ON s.id_ciclo = c.id_ciclo";
    try {
        if (db->conexionActiva())
            return db->ejecutaConsultaTabla(sql);
    }
    catch (Exception^) {}
    return gcnew DataTable();
}

bool CModelo::insertarSeccion(Seccion^ nueva) {
    try {
        String^ sql =
            "INSERT INTO seccion (nombre_seccion, jornada, aula, id_materia, id_docente, id_ciclo) "
            "VALUES (@nombre, @jornada, @aula, @materia, @docente, @ciclo)";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre",  nueva->nombre_seccion);
        cmd->Parameters->AddWithValue("@jornada", nueva->jornada);
        cmd->Parameters->AddWithValue("@aula",    nueva->aula);
        cmd->Parameters->AddWithValue("@materia", nueva->id_materia);
        cmd->Parameters->AddWithValue("@docente", nueva->id_docente);
        cmd->Parameters->AddWithValue("@ciclo",   nueva->id_ciclo);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::actualizarSeccion(Seccion^ editada) {
    try {
        String^ sql =
            "UPDATE seccion SET "
            "nombre_seccion = @nombre, "
            "jornada = @jornada, "
            "aula = @aula, "
            "id_materia = @materia, "
            "id_docente = @docente, "
            "id_ciclo = @ciclo "
            "WHERE id_seccion = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre",  editada->nombre_seccion);
        cmd->Parameters->AddWithValue("@jornada", editada->jornada);
        cmd->Parameters->AddWithValue("@aula",    editada->aula);
        cmd->Parameters->AddWithValue("@materia", editada->id_materia);
        cmd->Parameters->AddWithValue("@docente", editada->id_docente);
        cmd->Parameters->AddWithValue("@ciclo",   editada->id_ciclo);
        cmd->Parameters->AddWithValue("@id",      editada->id_seccion);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

bool CModelo::eliminarSeccion(int id) {
    try {
        String^ sql = "DELETE FROM seccion WHERE id_seccion = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return false;
    }
}

// =========================================
// CRUD FACULTAD
// =========================================

bool CModelo::insertarFacultad(Facultad^ f) {
    try {
        String^ sql = "INSERT INTO facultad (nombre_facultad) VALUES (@nombre)";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", f->nombre_facultad);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}

bool CModelo::actualizarFacultad(Facultad^ f) {
    try {
        String^ sql = "UPDATE facultad SET nombre_facultad = @nombre WHERE id_facultad = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", f->nombre_facultad);
        cmd->Parameters->AddWithValue("@id", f->id_facultad);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}

bool CModelo::eliminarFacultad(int id) {
    try {
        String^ sql = "DELETE FROM facultad WHERE id_facultad = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}

DataTable^ CModelo::listarFacultades() {
    String^ sql = "SELECT id_facultad, nombre_facultad FROM facultad";
    try {
        if (db->conexionActiva()) return db->ejecutaConsultaTabla(sql);
    } catch (Exception^) {}
    return gcnew DataTable();
}

DataTable^ CModelo::listarFacultadesCombo() {
    return listarFacultades();
}

// =========================================
// CRUD CARRERA
// =========================================

bool CModelo::insertarCarrera(Carrera^ c) {
    try {
        String^ sql = "INSERT INTO carrera (nombre_carrera, id_facultad) VALUES (@nombre, @id_fac)";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", c->nombre_carrera);
        cmd->Parameters->AddWithValue("@id_fac", c->id_facultad);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}

bool CModelo::actualizarCarrera(Carrera^ c) {
    try {
        String^ sql = "UPDATE carrera SET nombre_carrera = @nombre, id_facultad = @id_fac WHERE id_carrera = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@nombre", c->nombre_carrera);
        cmd->Parameters->AddWithValue("@id_fac", c->id_facultad);
        cmd->Parameters->AddWithValue("@id", c->id_carrera);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}

bool CModelo::eliminarCarrera(int id) {
    try {
        String^ sql = "DELETE FROM carrera WHERE id_carrera = @id";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql);
        cmd->Parameters->AddWithValue("@id", id);
        return (db->ejecutaIUD(cmd) > 0);
    }
    catch (Exception^) { return false; }
}
