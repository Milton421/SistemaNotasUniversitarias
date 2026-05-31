#pragma once
#include "Tema.h"
#include "Controlador.h"

namespace ProyectoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Formulario unificado de gestion academica: Docentes, Materias, Ciclos y Secciones.
	/// </summary>
	public ref class GestionAcademicaForm : public System::Windows::Forms::Form
	{
	public:
		GestionAcademicaForm(void)
		{
			InitializeComponent();
			for each (DataGridView^ dgv in gcnew array<DataGridView^>{
				dgvDocentes, dgvMaterias, dgvCiclos, dgvSecciones}) {
				dgv->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
				dgv->MultiSelect         = false;
				dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				dgv->AllowUserToAddRows    = false;
				dgv->AllowUserToDeleteRows = false;
				dgv->ReadOnly = true;
			}
			cbMateriaSec->DropDownStyle  = ComboBoxStyle::DropDownList;
			cbDocenteSec->DropDownStyle  = ComboBoxStyle::DropDownList;
			cbCicloSec->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbCarreraMat->DropDownStyle  = ComboBoxStyle::DropDownList;

			btnActualizarDoc->Enabled = false; btnEliminarDoc->Enabled = false;
			btnActualizarMat->Enabled = false; btnEliminarMat->Enabled = false;
			btnActualizarCic->Enabled = false; btnEliminarCic->Enabled = false;
			btnActualizarSec->Enabled = false; btnEliminarSec->Enabled = false;

			cargarDocentes();
			cargarMaterias();
			cargarCiclos();
			cargarCombosSeccion();
			cargarSecciones();
		cargarFacultades();
		cargarCarreras();
		CModelo^ m = gcnew CModelo();
		cbFacultadCar->DataSource = m->listarFacultadesCombo();
		cbFacultadCar->DisplayMember = "nombre_facultad";
		cbFacultadCar->ValueMember = "id_facultad";

			Tema::Aplicar(this);

		}

	protected:
		~GestionAcademicaForm()
		{
			if (components) { delete components; }
		}

	// =========================================
	// CONTROLES — DECLARACION
	// =========================================
	private:
		System::ComponentModel::Container^ components;

		System::Windows::Forms::TabControl^  tabControl;
		System::Windows::Forms::TabPage^     tabDocentes;
		System::Windows::Forms::TabPage^     tabMaterias;
		System::Windows::Forms::TabPage^     tabCiclos;
		System::Windows::Forms::TabPage^     tabSecciones;
		System::Windows::Forms::TabPage^     tabFacultades;
		System::Windows::Forms::TabPage^     tabCarreras;

		// Facultades
		System::Windows::Forms::DataGridView^ dgvFacultades;
		System::Windows::Forms::Label^        lblNombreFac;
		System::Windows::Forms::TextBox^      txtNombreFac;
		System::Windows::Forms::Label^        lblIDFac;
		System::Windows::Forms::Button^       btnInsertarFac;
		System::Windows::Forms::Button^       btnActualizarFac;
		System::Windows::Forms::Button^       btnEliminarFac;
		System::Windows::Forms::Button^       btnLimpiarFac;

		// Carreras
		System::Windows::Forms::DataGridView^ dgvCarreras;
		System::Windows::Forms::Label^        lblNombreCar;
		System::Windows::Forms::TextBox^      txtNombreCar;
		System::Windows::Forms::Label^        lblFacultadCar;
		System::Windows::Forms::ComboBox^     cbFacultadCar;
		System::Windows::Forms::Label^        lblIDCar;
		System::Windows::Forms::Button^       btnInsertarCar;
		System::Windows::Forms::Button^       btnActualizarCar;
		System::Windows::Forms::Button^       btnEliminarCar;
		System::Windows::Forms::Button^       btnLimpiarCar;

		// --- Botones globales ---

		System::Windows::Forms::Button^  btnSalir;

		// ---- TAB DOCENTES ----
		System::Windows::Forms::DataGridView^ dgvDocentes;
		System::Windows::Forms::Label^    lblNombresDoc;
		System::Windows::Forms::Label^    lblApellidosDoc;
		System::Windows::Forms::Label^    lblCorreoDoc;
		System::Windows::Forms::Label^    lblEspecDoc;
		System::Windows::Forms::TextBox^  txtNombresDoc;
		System::Windows::Forms::TextBox^  txtApellidosDoc;
		System::Windows::Forms::TextBox^  txtCorreoDoc;
		System::Windows::Forms::TextBox^  txtEspecDoc;
		System::Windows::Forms::Label^    lblIDDoc;
		System::Windows::Forms::Button^   btnInsertarDoc;
		System::Windows::Forms::Button^   btnActualizarDoc;
		System::Windows::Forms::Button^   btnEliminarDoc;
		System::Windows::Forms::Button^   btnLimpiarDoc;

		// ---- TAB MATERIAS ----
		System::Windows::Forms::DataGridView^ dgvMaterias;
		System::Windows::Forms::Label^    lblCodigoMat;
		System::Windows::Forms::Label^    lblNombreMat;
		System::Windows::Forms::Label^    lblCreditosMat;
		System::Windows::Forms::Label^    lblSemestreMat;
		System::Windows::Forms::Label^    lblCarreraMat;
		System::Windows::Forms::TextBox^  txtCodigoMat;
		System::Windows::Forms::TextBox^  txtNombreMat;
		System::Windows::Forms::TextBox^  txtCreditosMat;
		System::Windows::Forms::TextBox^  txtSemestreMat;
		System::Windows::Forms::ComboBox^ cbCarreraMat;
		System::Windows::Forms::Label^    lblIDMat;
		System::Windows::Forms::Button^   btnInsertarMat;
		System::Windows::Forms::Button^   btnActualizarMat;
		System::Windows::Forms::Button^   btnEliminarMat;
		System::Windows::Forms::Button^   btnLimpiarMat;

		// ---- TAB CICLOS ----
		System::Windows::Forms::DataGridView^ dgvCiclos;
		System::Windows::Forms::Label^    lblNombreCic;
		System::Windows::Forms::Label^    lblAnioCic;
		System::Windows::Forms::TextBox^  txtNombreCic;
		System::Windows::Forms::TextBox^  txtAnioCic;
		System::Windows::Forms::Label^    lblIDCic;
		System::Windows::Forms::Button^   btnInsertarCic;
		System::Windows::Forms::Button^   btnActualizarCic;
		System::Windows::Forms::Button^   btnEliminarCic;
		System::Windows::Forms::Button^   btnLimpiarCic;

		// ---- TAB SECCIONES ----
		System::Windows::Forms::DataGridView^ dgvSecciones;
		System::Windows::Forms::Label^    lblNombreSec;
		System::Windows::Forms::Label^    lblJornadaSec;
		System::Windows::Forms::Label^    lblAulaSec;
		System::Windows::Forms::Label^    lblMateriaSec;
		System::Windows::Forms::Label^    lblDocenteSec;
		System::Windows::Forms::Label^    lblCicloSec;
		System::Windows::Forms::TextBox^  txtNombreSec;
		System::Windows::Forms::TextBox^  txtJornadaSec;
		System::Windows::Forms::TextBox^  txtAulaSec;
		System::Windows::Forms::ComboBox^ cbMateriaSec;
		System::Windows::Forms::ComboBox^ cbDocenteSec;
		System::Windows::Forms::ComboBox^ cbCicloSec;
		System::Windows::Forms::Label^    lblIDSec;
		System::Windows::Forms::Button^   btnInsertarSec;
		System::Windows::Forms::Button^   btnActualizarSec;
		System::Windows::Forms::Button^   btnEliminarSec;
		System::Windows::Forms::Button^   btnLimpiarSec;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			// Instanciar todo
			this->components        = nullptr;
			this->tabControl        = (gcnew System::Windows::Forms::TabControl());
			this->tabDocentes       = (gcnew System::Windows::Forms::TabPage());
			this->tabMaterias       = (gcnew System::Windows::Forms::TabPage());
			this->tabCiclos         = (gcnew System::Windows::Forms::TabPage());
			this->tabSecciones      = (gcnew System::Windows::Forms::TabPage());
			this->tabFacultades     = (gcnew System::Windows::Forms::TabPage());
			this->tabCarreras       = (gcnew System::Windows::Forms::TabPage());

			this->dgvFacultades     = (gcnew System::Windows::Forms::DataGridView());
			this->lblNombreFac      = (gcnew System::Windows::Forms::Label());
			this->txtNombreFac      = (gcnew System::Windows::Forms::TextBox());
			this->lblIDFac          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarFac    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarFac  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarFac    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarFac     = (gcnew System::Windows::Forms::Button());

			this->dgvCarreras       = (gcnew System::Windows::Forms::DataGridView());
			this->lblNombreCar      = (gcnew System::Windows::Forms::Label());
			this->txtNombreCar      = (gcnew System::Windows::Forms::TextBox());
			this->lblFacultadCar    = (gcnew System::Windows::Forms::Label());
			this->cbFacultadCar     = (gcnew System::Windows::Forms::ComboBox());
			this->lblIDCar          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarCar    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarCar  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarCar    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarCar     = (gcnew System::Windows::Forms::Button());

			this->btnSalir          = (gcnew System::Windows::Forms::Button());

			// Docentes
			this->dgvDocentes       = (gcnew System::Windows::Forms::DataGridView());
			this->lblNombresDoc     = (gcnew System::Windows::Forms::Label());
			this->lblApellidosDoc   = (gcnew System::Windows::Forms::Label());
			this->lblCorreoDoc      = (gcnew System::Windows::Forms::Label());
			this->lblEspecDoc       = (gcnew System::Windows::Forms::Label());
			this->txtNombresDoc     = (gcnew System::Windows::Forms::TextBox());
			this->txtApellidosDoc   = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreoDoc      = (gcnew System::Windows::Forms::TextBox());
			this->txtEspecDoc       = (gcnew System::Windows::Forms::TextBox());
			this->lblIDDoc          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarDoc    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarDoc  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarDoc    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarDoc     = (gcnew System::Windows::Forms::Button());

			// Materias
			this->dgvMaterias       = (gcnew System::Windows::Forms::DataGridView());
			this->lblCodigoMat      = (gcnew System::Windows::Forms::Label());
			this->lblNombreMat      = (gcnew System::Windows::Forms::Label());
			this->lblCreditosMat    = (gcnew System::Windows::Forms::Label());
			this->lblSemestreMat    = (gcnew System::Windows::Forms::Label());
			this->lblCarreraMat     = (gcnew System::Windows::Forms::Label());
			this->txtCodigoMat      = (gcnew System::Windows::Forms::TextBox());
			this->txtNombreMat      = (gcnew System::Windows::Forms::TextBox());
			this->txtCreditosMat    = (gcnew System::Windows::Forms::TextBox());
			this->txtSemestreMat    = (gcnew System::Windows::Forms::TextBox());
			this->cbCarreraMat      = (gcnew System::Windows::Forms::ComboBox());
			this->lblIDMat          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarMat    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarMat  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarMat    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarMat     = (gcnew System::Windows::Forms::Button());

			// Ciclos
			this->dgvCiclos         = (gcnew System::Windows::Forms::DataGridView());
			this->lblNombreCic      = (gcnew System::Windows::Forms::Label());
			this->lblAnioCic        = (gcnew System::Windows::Forms::Label());
			this->txtNombreCic      = (gcnew System::Windows::Forms::TextBox());
			this->txtAnioCic        = (gcnew System::Windows::Forms::TextBox());
			this->lblIDCic          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarCic    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarCic  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarCic    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarCic     = (gcnew System::Windows::Forms::Button());

			// Secciones
			this->dgvSecciones      = (gcnew System::Windows::Forms::DataGridView());
			this->lblNombreSec      = (gcnew System::Windows::Forms::Label());
			this->lblJornadaSec     = (gcnew System::Windows::Forms::Label());
			this->lblAulaSec        = (gcnew System::Windows::Forms::Label());
			this->lblMateriaSec     = (gcnew System::Windows::Forms::Label());
			this->lblDocenteSec     = (gcnew System::Windows::Forms::Label());
			this->lblCicloSec       = (gcnew System::Windows::Forms::Label());
			this->txtNombreSec      = (gcnew System::Windows::Forms::TextBox());
			this->txtJornadaSec     = (gcnew System::Windows::Forms::TextBox());
			this->txtAulaSec        = (gcnew System::Windows::Forms::TextBox());
			this->cbMateriaSec      = (gcnew System::Windows::Forms::ComboBox());
			this->cbDocenteSec      = (gcnew System::Windows::Forms::ComboBox());
			this->cbCicloSec        = (gcnew System::Windows::Forms::ComboBox());
			this->lblIDSec          = (gcnew System::Windows::Forms::Label());
			this->btnInsertarSec    = (gcnew System::Windows::Forms::Button());
			this->btnActualizarSec  = (gcnew System::Windows::Forms::Button());
			this->btnEliminarSec    = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarSec     = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvDocentes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvMaterias))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvCiclos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvSecciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvFacultades))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvCarreras))->BeginInit();
			this->SuspendLayout();

			// =========================================
			// FORM
			// =========================================
			this->ClientSize   = System::Drawing::Size(1050, 620);
			this->Text         = L"Gestion Academica";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Name         = L"GestionAcademicaForm";

			// =========================================
			// TAB CONTROL
			// =========================================
			this->tabControl->Location = System::Drawing::Point(10, 10);
			this->tabControl->Size     = System::Drawing::Size(1030, 560);
			this->tabControl->Anchor   = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tabControl->Name     = L"tabControl";
			this->tabControl->TabIndex = 0;
			this->tabDocentes->Text    = L"  Docentes  ";
			this->tabMaterias->Text    = L"  Materias  ";
			this->tabCiclos->Text      = L"  Ciclos Academicos  ";
			this->tabSecciones->Text   = L"  Secciones  ";
			this->tabFacultades->Text  = L"  Facultades  ";
			this->tabCarreras->Text    = L"  Carreras  ";
			this->tabControl->Controls->Add(tabDocentes);
			this->tabControl->Controls->Add(tabMaterias);
			this->tabControl->Controls->Add(tabCiclos);
			this->tabControl->Controls->Add(tabSecciones);
			this->tabControl->Controls->Add(tabFacultades);
			this->tabControl->Controls->Add(tabCarreras);

			// =========================================
			// BOTONES GLOBALES
			// =========================================

			this->btnSalir->Location = System::Drawing::Point(950, 578);
			this->btnSalir->Size     = System::Drawing::Size(90, 30);
			this->btnSalir->Text     = L"Salir";
			this->btnSalir->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnSalir_Click);

			// =========================================
			// TAB DOCENTES — CONTROLES
			// =========================================
			int xLbl = 10, xTxt = 120, wTxt = 260, yBase = 15, yStep = 40;

			lblNombresDoc->Text     = L"Nombres:";
			lblNombresDoc->Location = System::Drawing::Point(xLbl, yBase);
			lblNombresDoc->Size     = System::Drawing::Size(100, 20);

			txtNombresDoc->Location = System::Drawing::Point(xTxt, yBase);
			txtNombresDoc->Size     = System::Drawing::Size(wTxt, 24);

			lblApellidosDoc->Text     = L"Apellidos:";
			lblApellidosDoc->Location = System::Drawing::Point(xLbl, yBase + yStep);
			lblApellidosDoc->Size     = System::Drawing::Size(100, 20);

			txtApellidosDoc->Location = System::Drawing::Point(xTxt, yBase + yStep);
			txtApellidosDoc->Size     = System::Drawing::Size(wTxt, 24);

			lblCorreoDoc->Text     = L"Correo:";
			lblCorreoDoc->Location = System::Drawing::Point(xLbl, yBase + yStep*2);
			lblCorreoDoc->Size     = System::Drawing::Size(100, 20);

			txtCorreoDoc->Location = System::Drawing::Point(xTxt, yBase + yStep*2);
			txtCorreoDoc->Size     = System::Drawing::Size(wTxt, 24);

			lblEspecDoc->Text     = L"Especialidad:";
			lblEspecDoc->Location = System::Drawing::Point(xLbl, yBase + yStep*3);
			lblEspecDoc->Size     = System::Drawing::Size(100, 20);

			txtEspecDoc->Location = System::Drawing::Point(xTxt, yBase + yStep*3);
			txtEspecDoc->Size     = System::Drawing::Size(wTxt, 24);

			lblIDDoc->Visible = false;

			// Botones docentes
			int xBtn = 410, yBtn = yBase, wBtn = 110, hBtn = 30;
			btnInsertarDoc->Text     = L"Insertar";
			btnInsertarDoc->Location = System::Drawing::Point(xBtn, yBtn);
			btnInsertarDoc->Size     = System::Drawing::Size(wBtn, hBtn);
			btnInsertarDoc->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnInsertarDoc_Click);

			btnActualizarDoc->Text     = L"Actualizar";
			btnActualizarDoc->Location = System::Drawing::Point(xBtn, yBtn + 40);
			btnActualizarDoc->Size     = System::Drawing::Size(wBtn, hBtn);
			btnActualizarDoc->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnActualizarDoc_Click);

			btnEliminarDoc->Text     = L"Eliminar";
			btnEliminarDoc->Location = System::Drawing::Point(xBtn, yBtn + 80);
			btnEliminarDoc->Size     = System::Drawing::Size(wBtn, hBtn);
			btnEliminarDoc->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnEliminarDoc_Click);

			btnLimpiarDoc->Text     = L"Limpiar";
			btnLimpiarDoc->Location = System::Drawing::Point(xBtn, yBtn + 120);
			btnLimpiarDoc->Size     = System::Drawing::Size(wBtn, hBtn);
			btnLimpiarDoc->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnLimpiarDoc_Click);

			dgvDocentes->Location = System::Drawing::Point(10, 180);
			dgvDocentes->Size     = System::Drawing::Size(990, 320);
			dgvDocentes->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvDocentes_CellClick);

			tabDocentes->Controls->Add(lblNombresDoc);   tabDocentes->Controls->Add(txtNombresDoc);
			tabDocentes->Controls->Add(lblApellidosDoc); tabDocentes->Controls->Add(txtApellidosDoc);
			tabDocentes->Controls->Add(lblCorreoDoc);    tabDocentes->Controls->Add(txtCorreoDoc);
			tabDocentes->Controls->Add(lblEspecDoc);     tabDocentes->Controls->Add(txtEspecDoc);
			tabDocentes->Controls->Add(lblIDDoc);
			tabDocentes->Controls->Add(btnInsertarDoc);  tabDocentes->Controls->Add(btnActualizarDoc);
			tabDocentes->Controls->Add(btnEliminarDoc);  tabDocentes->Controls->Add(btnLimpiarDoc);
			tabDocentes->Controls->Add(dgvDocentes);

			// =========================================
			// TAB MATERIAS — CONTROLES
			// =========================================
			lblCodigoMat->Text     = L"Codigo:";
			lblCodigoMat->Location = System::Drawing::Point(xLbl, yBase);
			lblCodigoMat->Size     = System::Drawing::Size(100, 20);
			txtCodigoMat->Location = System::Drawing::Point(xTxt, yBase);
			txtCodigoMat->Size     = System::Drawing::Size(150, 24);

			lblNombreMat->Text     = L"Nombre:";
			lblNombreMat->Location = System::Drawing::Point(xLbl, yBase + yStep);
			lblNombreMat->Size     = System::Drawing::Size(100, 20);
			txtNombreMat->Location = System::Drawing::Point(xTxt, yBase + yStep);
			txtNombreMat->Size     = System::Drawing::Size(wTxt, 24);

			lblCreditosMat->Text     = L"Creditos:";
			lblCreditosMat->Location = System::Drawing::Point(xLbl, yBase + yStep*2);
			lblCreditosMat->Size     = System::Drawing::Size(100, 20);
			txtCreditosMat->Location = System::Drawing::Point(xTxt, yBase + yStep*2);
			txtCreditosMat->Size     = System::Drawing::Size(80, 24);

			lblSemestreMat->Text     = L"Semestre:";
			lblSemestreMat->Location = System::Drawing::Point(xLbl, yBase + yStep*3);
			lblSemestreMat->Size     = System::Drawing::Size(100, 20);
			txtSemestreMat->Location = System::Drawing::Point(xTxt, yBase + yStep*3);
			txtSemestreMat->Size     = System::Drawing::Size(80, 24);

			lblCarreraMat->Text     = L"Carrera:";
			lblCarreraMat->Location = System::Drawing::Point(xLbl, yBase + yStep*4);
			lblCarreraMat->Size     = System::Drawing::Size(100, 20);
			cbCarreraMat->Location  = System::Drawing::Point(xTxt, yBase + yStep*4);
			cbCarreraMat->Size      = System::Drawing::Size(wTxt, 26);

			lblIDMat->Visible = false;

			btnInsertarMat->Text     = L"Insertar";
			btnInsertarMat->Location = System::Drawing::Point(xBtn, yBtn);
			btnInsertarMat->Size     = System::Drawing::Size(wBtn, hBtn);
			btnInsertarMat->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnInsertarMat_Click);

			btnActualizarMat->Text     = L"Actualizar";
			btnActualizarMat->Location = System::Drawing::Point(xBtn, yBtn + 40);
			btnActualizarMat->Size     = System::Drawing::Size(wBtn, hBtn);
			btnActualizarMat->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnActualizarMat_Click);

			btnEliminarMat->Text     = L"Eliminar";
			btnEliminarMat->Location = System::Drawing::Point(xBtn, yBtn + 80);
			btnEliminarMat->Size     = System::Drawing::Size(wBtn, hBtn);
			btnEliminarMat->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnEliminarMat_Click);

			btnLimpiarMat->Text     = L"Limpiar";
			btnLimpiarMat->Location = System::Drawing::Point(xBtn, yBtn + 120);
			btnLimpiarMat->Size     = System::Drawing::Size(wBtn, hBtn);
			btnLimpiarMat->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnLimpiarMat_Click);

			dgvMaterias->Location = System::Drawing::Point(10, 220);
			dgvMaterias->Size     = System::Drawing::Size(990, 280);
			dgvMaterias->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvMaterias_CellClick);

			tabMaterias->Controls->Add(lblCodigoMat);   tabMaterias->Controls->Add(txtCodigoMat);
			tabMaterias->Controls->Add(lblNombreMat);   tabMaterias->Controls->Add(txtNombreMat);
			tabMaterias->Controls->Add(lblCreditosMat); tabMaterias->Controls->Add(txtCreditosMat);
			tabMaterias->Controls->Add(lblSemestreMat); tabMaterias->Controls->Add(txtSemestreMat);
			tabMaterias->Controls->Add(lblCarreraMat);  tabMaterias->Controls->Add(cbCarreraMat);
			tabMaterias->Controls->Add(lblIDMat);
			tabMaterias->Controls->Add(btnInsertarMat);  tabMaterias->Controls->Add(btnActualizarMat);
			tabMaterias->Controls->Add(btnEliminarMat);  tabMaterias->Controls->Add(btnLimpiarMat);
			tabMaterias->Controls->Add(dgvMaterias);

			// =========================================
			// TAB CICLOS — CONTROLES
			// =========================================
			lblNombreCic->Text     = L"Nombre:";
			lblNombreCic->Location = System::Drawing::Point(xLbl, yBase);
			lblNombreCic->Size     = System::Drawing::Size(100, 20);
			txtNombreCic->Location = System::Drawing::Point(xTxt, yBase);
			txtNombreCic->Size     = System::Drawing::Size(200, 24);

			lblAnioCic->Text     = L"Anio:";
			lblAnioCic->Location = System::Drawing::Point(xLbl, yBase + yStep);
			lblAnioCic->Size     = System::Drawing::Size(100, 20);
			txtAnioCic->Location = System::Drawing::Point(xTxt, yBase + yStep);
			txtAnioCic->Size     = System::Drawing::Size(100, 24);

			lblIDCic->Visible = false;

			btnInsertarCic->Text     = L"Insertar";
			btnInsertarCic->Location = System::Drawing::Point(xBtn, yBtn);
			btnInsertarCic->Size     = System::Drawing::Size(wBtn, hBtn);
			btnInsertarCic->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnInsertarCic_Click);

			btnActualizarCic->Text     = L"Actualizar";
			btnActualizarCic->Location = System::Drawing::Point(xBtn, yBtn + 40);
			btnActualizarCic->Size     = System::Drawing::Size(wBtn, hBtn);
			btnActualizarCic->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnActualizarCic_Click);

			btnEliminarCic->Text     = L"Eliminar";
			btnEliminarCic->Location = System::Drawing::Point(xBtn, yBtn + 80);
			btnEliminarCic->Size     = System::Drawing::Size(wBtn, hBtn);
			btnEliminarCic->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnEliminarCic_Click);

			btnLimpiarCic->Text     = L"Limpiar";
			btnLimpiarCic->Location = System::Drawing::Point(xBtn, yBtn + 120);
			btnLimpiarCic->Size     = System::Drawing::Size(wBtn, hBtn);
			btnLimpiarCic->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnLimpiarCic_Click);

			dgvCiclos->Location = System::Drawing::Point(10, 180);
			dgvCiclos->Size     = System::Drawing::Size(990, 320);
			dgvCiclos->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvCiclos_CellClick);

			tabCiclos->Controls->Add(lblNombreCic); tabCiclos->Controls->Add(txtNombreCic);
			tabCiclos->Controls->Add(lblAnioCic);   tabCiclos->Controls->Add(txtAnioCic);
			tabCiclos->Controls->Add(lblIDCic);
			tabCiclos->Controls->Add(btnInsertarCic);  tabCiclos->Controls->Add(btnActualizarCic);
			tabCiclos->Controls->Add(btnEliminarCic);  tabCiclos->Controls->Add(btnLimpiarCic);
			tabCiclos->Controls->Add(dgvCiclos);

			// =========================================
			// TAB SECCIONES — CONTROLES
			// =========================================
			int xLbl2 = 10, xTxt2 = 110, wTxt2 = 200;
			int xLbl3 = 330, xTxt3 = 440, wTxt3 = 200;

			lblNombreSec->Text     = L"Nombre:";
			lblNombreSec->Location = System::Drawing::Point(xLbl2, yBase);
			lblNombreSec->Size     = System::Drawing::Size(95, 20);
			txtNombreSec->Location = System::Drawing::Point(xTxt2, yBase);
			txtNombreSec->Size     = System::Drawing::Size(150, 24);

			lblJornadaSec->Text     = L"Jornada:";
			lblJornadaSec->Location = System::Drawing::Point(xLbl2, yBase + yStep);
			lblJornadaSec->Size     = System::Drawing::Size(95, 20);
			txtJornadaSec->Location = System::Drawing::Point(xTxt2, yBase + yStep);
			txtJornadaSec->Size     = System::Drawing::Size(150, 24);

			lblAulaSec->Text     = L"Aula:";
			lblAulaSec->Location = System::Drawing::Point(xLbl2, yBase + yStep*2);
			lblAulaSec->Size     = System::Drawing::Size(95, 20);
			txtAulaSec->Location = System::Drawing::Point(xTxt2, yBase + yStep*2);
			txtAulaSec->Size     = System::Drawing::Size(150, 24);

			lblMateriaSec->Text     = L"Materia:";
			lblMateriaSec->Location = System::Drawing::Point(xLbl3, yBase);
			lblMateriaSec->Size     = System::Drawing::Size(95, 20);
			cbMateriaSec->Location  = System::Drawing::Point(xTxt3, yBase);
			cbMateriaSec->Size      = System::Drawing::Size(wTxt3, 26);

			lblDocenteSec->Text     = L"Docente:";
			lblDocenteSec->Location = System::Drawing::Point(xLbl3, yBase + yStep);
			lblDocenteSec->Size     = System::Drawing::Size(95, 20);
			cbDocenteSec->Location  = System::Drawing::Point(xTxt3, yBase + yStep);
			cbDocenteSec->Size      = System::Drawing::Size(wTxt3, 26);

			lblCicloSec->Text     = L"Ciclo:";
			lblCicloSec->Location = System::Drawing::Point(xLbl3, yBase + yStep*2);
			lblCicloSec->Size     = System::Drawing::Size(95, 20);
			cbCicloSec->Location  = System::Drawing::Point(xTxt3, yBase + yStep*2);
			cbCicloSec->Size      = System::Drawing::Size(wTxt3, 26);

			lblIDSec->Visible = false;

			btnInsertarSec->Text     = L"Insertar";
			btnInsertarSec->Location = System::Drawing::Point(680, yBtn);
			btnInsertarSec->Size     = System::Drawing::Size(wBtn, hBtn);
			btnInsertarSec->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnInsertarSec_Click);

			btnActualizarSec->Text     = L"Actualizar";
			btnActualizarSec->Location = System::Drawing::Point(680, yBtn + 40);
			btnActualizarSec->Size     = System::Drawing::Size(wBtn, hBtn);
			btnActualizarSec->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnActualizarSec_Click);

			btnEliminarSec->Text     = L"Eliminar";
			btnEliminarSec->Location = System::Drawing::Point(680, yBtn + 80);
			btnEliminarSec->Size     = System::Drawing::Size(wBtn, hBtn);
			btnEliminarSec->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnEliminarSec_Click);

			btnLimpiarSec->Text     = L"Limpiar";
			btnLimpiarSec->Location = System::Drawing::Point(680, yBtn + 120);
			btnLimpiarSec->Size     = System::Drawing::Size(wBtn, hBtn);
			btnLimpiarSec->Click   += gcnew EventHandler(this, &GestionAcademicaForm::btnLimpiarSec_Click);

			dgvSecciones->Location = System::Drawing::Point(10, 180);
			dgvSecciones->Size     = System::Drawing::Size(990, 320);
			dgvSecciones->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvSecciones_CellClick);

			tabSecciones->Controls->Add(lblNombreSec);  tabSecciones->Controls->Add(txtNombreSec);
			tabSecciones->Controls->Add(lblJornadaSec); tabSecciones->Controls->Add(txtJornadaSec);
			tabSecciones->Controls->Add(lblAulaSec);    tabSecciones->Controls->Add(txtAulaSec);
			tabSecciones->Controls->Add(lblMateriaSec); tabSecciones->Controls->Add(cbMateriaSec);
			tabSecciones->Controls->Add(lblDocenteSec); tabSecciones->Controls->Add(cbDocenteSec);
			tabSecciones->Controls->Add(lblCicloSec);   tabSecciones->Controls->Add(cbCicloSec);
			tabSecciones->Controls->Add(lblIDSec);
			tabSecciones->Controls->Add(btnInsertarSec);  tabSecciones->Controls->Add(btnActualizarSec);
			tabSecciones->Controls->Add(btnEliminarSec);  tabSecciones->Controls->Add(btnLimpiarSec);
			tabSecciones->Controls->Add(dgvSecciones);

			
			// =========================================
			// TAB FACULTADES - CONTROLES
			// =========================================
			int xLblFac = 10, xTxtFac = 120, wTxtFac = 260, yBaseFac = 15;
			lblNombreFac->Text     = L"Nombre:";
			lblNombreFac->Location = System::Drawing::Point(xLblFac, yBaseFac);
			lblNombreFac->Size     = System::Drawing::Size(100, 20);
			txtNombreFac->Location = System::Drawing::Point(xTxtFac, yBaseFac);
			txtNombreFac->Size     = System::Drawing::Size(wTxtFac, 24);
			
			lblIDFac->Text     = L"";
			lblIDFac->Visible  = false;

			int xBtnFac = 410, yBtnFac = yBaseFac, wBtnFac = 110, hBtnFac = 30;
			btnInsertarFac->Text     = L"Insertar";
			btnInsertarFac->Location = System::Drawing::Point(xBtnFac, yBtnFac);
			btnInsertarFac->Size     = System::Drawing::Size(wBtnFac, hBtnFac);
			btnInsertarFac->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnInsertarFac_Click);
			
			btnActualizarFac->Text     = L"Actualizar";
			btnActualizarFac->Location = System::Drawing::Point(xBtnFac, yBtnFac + 40);
			btnActualizarFac->Size     = System::Drawing::Size(wBtnFac, hBtnFac);
			btnActualizarFac->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnActualizarFac_Click);
			
			btnEliminarFac->Text     = L"Eliminar";
			btnEliminarFac->Location = System::Drawing::Point(xBtnFac + 120, yBtnFac);
			btnEliminarFac->Size     = System::Drawing::Size(wBtnFac, hBtnFac);
			btnEliminarFac->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnEliminarFac_Click);
			
			btnLimpiarFac->Text     = L"Limpiar";
			btnLimpiarFac->Location = System::Drawing::Point(xBtnFac + 120, yBtnFac + 40);
			btnLimpiarFac->Size     = System::Drawing::Size(wBtnFac, hBtnFac);
			btnLimpiarFac->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnLimpiarFac_Click);
			
			dgvFacultades->Location = System::Drawing::Point(10, 100);
			dgvFacultades->Size     = System::Drawing::Size(990, 400);
			dgvFacultades->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvFacultades_CellClick);
			
			tabFacultades->Controls->Add(lblNombreFac);   tabFacultades->Controls->Add(txtNombreFac);
			tabFacultades->Controls->Add(lblIDFac);
			tabFacultades->Controls->Add(btnInsertarFac); tabFacultades->Controls->Add(btnActualizarFac);
			tabFacultades->Controls->Add(btnEliminarFac); tabFacultades->Controls->Add(btnLimpiarFac);
			tabFacultades->Controls->Add(dgvFacultades);
			
			// =========================================
			// TAB CARRERAS - CONTROLES
			// =========================================
			int xLblCar = 10, xTxtCar = 120, wTxtCar = 260, yBaseCar = 15;
			lblNombreCar->Text     = L"Nombre:";
			lblNombreCar->Location = System::Drawing::Point(xLblCar, yBaseCar);
			lblNombreCar->Size     = System::Drawing::Size(100, 20);
			txtNombreCar->Location = System::Drawing::Point(xTxtCar, yBaseCar);
			txtNombreCar->Size     = System::Drawing::Size(wTxtCar, 24);
			
			lblFacultadCar->Text     = L"Facultad:";
			lblFacultadCar->Location = System::Drawing::Point(xLblCar, yBaseCar + 40);
			lblFacultadCar->Size     = System::Drawing::Size(100, 20);
			cbFacultadCar->Location = System::Drawing::Point(xTxtCar, yBaseCar + 40);
			cbFacultadCar->Size     = System::Drawing::Size(wTxtCar, 24);
			cbFacultadCar->DropDownStyle = ComboBoxStyle::DropDownList;
			
			lblIDCar->Text     = L"";
			lblIDCar->Visible  = false;

			int xBtnCar = 410, yBtnCar = yBaseCar, wBtnCar = 110, hBtnCar = 30;
			btnInsertarCar->Text     = L"Insertar";
			btnInsertarCar->Location = System::Drawing::Point(xBtnCar, yBtnCar);
			btnInsertarCar->Size     = System::Drawing::Size(wBtnCar, hBtnCar);
			btnInsertarCar->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnInsertarCar_Click);
			
			btnActualizarCar->Text     = L"Actualizar";
			btnActualizarCar->Location = System::Drawing::Point(xBtnCar, yBtnCar + 40);
			btnActualizarCar->Size     = System::Drawing::Size(wBtnCar, hBtnCar);
			btnActualizarCar->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnActualizarCar_Click);
			
			btnEliminarCar->Text     = L"Eliminar";
			btnEliminarCar->Location = System::Drawing::Point(xBtnCar + 120, yBtnCar);
			btnEliminarCar->Size     = System::Drawing::Size(wBtnCar, hBtnCar);
			btnEliminarCar->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnEliminarCar_Click);
			
			btnLimpiarCar->Text     = L"Limpiar";
			btnLimpiarCar->Location = System::Drawing::Point(xBtnCar + 120, yBtnCar + 40);
			btnLimpiarCar->Size     = System::Drawing::Size(wBtnCar, hBtnCar);
			btnLimpiarCar->Click   += gcnew System::EventHandler(this, &GestionAcademicaForm::btnLimpiarCar_Click);
			
			dgvCarreras->Location = System::Drawing::Point(10, 100);
			dgvCarreras->Size     = System::Drawing::Size(990, 400);
			dgvCarreras->CellClick += gcnew DataGridViewCellEventHandler(this, &GestionAcademicaForm::dgvCarreras_CellClick);
			
			tabCarreras->Controls->Add(lblNombreCar);   tabCarreras->Controls->Add(txtNombreCar);
			tabCarreras->Controls->Add(lblFacultadCar); tabCarreras->Controls->Add(cbFacultadCar);
			tabCarreras->Controls->Add(lblIDCar);
			tabCarreras->Controls->Add(btnInsertarCar); tabCarreras->Controls->Add(btnActualizarCar);
			tabCarreras->Controls->Add(btnEliminarCar); tabCarreras->Controls->Add(btnLimpiarCar);
			tabCarreras->Controls->Add(dgvCarreras);
			
			// =========================================
			// ENSAMBLAR FORM
			// =========================================
			this->Controls->Add(tabControl);

			this->Controls->Add(btnSalir);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvDocentes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvMaterias))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvCiclos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvSecciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvFacultades))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dgvCarreras))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	// =========================================
	// HELPERS — CARGA DE DATOS
	// =========================================

	void cargarDocentes() {
		CModelo^ m = gcnew CModelo();
		dgvDocentes->DataSource = m->listarDocentes();
	}

	void cargarMaterias() {
		CModelo^ m = gcnew CModelo();
		// Cargar combo carrera si esta vacio
		if (cbCarreraMat->Items->Count == 0) {
			DataTable^ dt = m->listarCarreras();
			cbCarreraMat->DataSource    = dt;
			cbCarreraMat->DisplayMember = "nombre_carrera";
			cbCarreraMat->ValueMember   = "id_carrera";
		}
		dgvMaterias->DataSource = m->listarMateriasCompleto();
	}

	void cargarCiclos() {
		CModelo^ m = gcnew CModelo();
		dgvCiclos->DataSource = m->listarCiclos();
	}

	void cargarCombosSeccion() {
		CModelo^ m = gcnew CModelo();

		DataTable^ dtMat = m->listarMaterias();
		cbMateriaSec->DataSource    = dtMat;
		cbMateriaSec->DisplayMember = "nombre_materia";
		cbMateriaSec->ValueMember   = "id_materia";

		DataTable^ dtDoc = m->listarDocentesCombo();
		cbDocenteSec->DataSource    = dtDoc;
		cbDocenteSec->DisplayMember = "docente";
		cbDocenteSec->ValueMember   = "id_docente";

		DataTable^ dtCic = m->listarCiclosCombo();
		cbCicloSec->DataSource    = dtCic;
		cbCicloSec->DisplayMember = "ciclo";
		cbCicloSec->ValueMember   = "id_ciclo";
	}

	void cargarSecciones() {
		CModelo^ m = gcnew CModelo();
		dgvSecciones->DataSource = m->listarSeccionesCompleto();
	}

	// =========================================
	// HELPERS — LIMPIAR CAMPOS
	// =========================================


	void cargarFacultades() {
		CModelo^ m = gcnew CModelo();
		dgvFacultades->DataSource = m->listarFacultades();
		dgvFacultades->Columns["id_facultad"]->Visible = false;
	}

	void cargarCarreras() {
		CModelo^ m = gcnew CModelo();
		dgvCarreras->DataSource = m->listarCarreras();
		dgvCarreras->Columns["id_carrera"]->Visible = false;
		dgvCarreras->Columns["id_facultad"]->Visible = false;
	}

	void limpiarDoc() {
		lblIDDoc->Text = "";
		txtNombresDoc->Text = ""; txtApellidosDoc->Text = "";
		txtCorreoDoc->Text  = ""; txtEspecDoc->Text     = "";
		btnActualizarDoc->Enabled = false; btnEliminarDoc->Enabled = false;
	}

	void limpiarMat() {
		lblIDMat->Text = "";
		txtCodigoMat->Text = ""; txtNombreMat->Text  = "";
		txtCreditosMat->Text = ""; txtSemestreMat->Text = "";
		if (cbCarreraMat->Items->Count > 0) cbCarreraMat->SelectedIndex = 0;
		btnActualizarMat->Enabled = false; btnEliminarMat->Enabled = false;
	}

	void limpiarCic() {
		lblIDCic->Text = "";
		txtNombreCic->Text = ""; txtAnioCic->Text = "";
		btnActualizarCic->Enabled = false; btnEliminarCic->Enabled = false;
	}

	void limpiarSec() {
		lblIDSec->Text = "";
		txtNombreSec->Text = ""; txtJornadaSec->Text = ""; txtAulaSec->Text = "";
		if (cbMateriaSec->Items->Count > 0) cbMateriaSec->SelectedIndex = 0;
		if (cbDocenteSec->Items->Count > 0) cbDocenteSec->SelectedIndex = 0;
		if (cbCicloSec->Items->Count   > 0) cbCicloSec->SelectedIndex   = 0;
		btnActualizarSec->Enabled = false; btnEliminarSec->Enabled = false;
	}

	// =========================================
	// EVENTOS — TAB DOCENTES
	// =========================================

private: System::Void dgvDocentes_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvDocentes->Rows[e->RowIndex];
		lblIDDoc->Text         = fila->Cells["id_docente"]->Value->ToString();
		txtNombresDoc->Text    = fila->Cells["nombres"]->Value->ToString();
		txtApellidosDoc->Text  = fila->Cells["apellidos"]->Value->ToString();
		txtCorreoDoc->Text     = fila->Cells["correo"]->Value->ToString();
		txtEspecDoc->Text      = fila->Cells["especialidad"]->Value->ToString();
		btnActualizarDoc->Enabled = true; btnEliminarDoc->Enabled = true;
	}

private: System::Void btnInsertarDoc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombresDoc->Text->Trim() == "" || txtApellidosDoc->Text->Trim() == "") {
			MessageBox::Show(L"Nombres y Apellidos son obligatorios.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Docente^ d = gcnew Docente();
		d->nombres      = txtNombresDoc->Text->Trim();
		d->apellidos    = txtApellidosDoc->Text->Trim();
		d->correo       = txtCorreoDoc->Text->Trim();
		d->especialidad = txtEspecDoc->Text->Trim();
		CModelo^ m = gcnew CModelo();
		if (m->insertarDocente(d)) {
			MessageBox::Show(L"Docente insertado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarDocentes(); limpiarDoc();
			// Refrescar combo de secciones
			cargarCombosSeccion();
		}
	}

private: System::Void btnActualizarDoc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDDoc->Text == "") { MessageBox::Show(L"Seleccione un docente."); return; }
		if (txtNombresDoc->Text->Trim() == "" || txtApellidosDoc->Text->Trim() == "") {
			MessageBox::Show(L"Nombres y Apellidos son obligatorios.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Docente^ d = gcnew Docente();
		d->id_docente   = Convert::ToInt32(lblIDDoc->Text);
		d->nombres      = txtNombresDoc->Text->Trim();
		d->apellidos    = txtApellidosDoc->Text->Trim();
		d->correo       = txtCorreoDoc->Text->Trim();
		d->especialidad = txtEspecDoc->Text->Trim();
		CModelo^ m = gcnew CModelo();
		if (m->actualizarDocente(d)) {
			MessageBox::Show(L"Docente actualizado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarDocentes(); limpiarDoc(); cargarCombosSeccion();
		}
	}

private: System::Void btnEliminarDoc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDDoc->Text == "") { MessageBox::Show(L"Seleccione un docente."); return; }
		if (MessageBox::Show(L"Confirmar eliminacion?", L"Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes) return;
		CModelo^ m = gcnew CModelo();
		if (m->eliminarDocente(Convert::ToInt32(lblIDDoc->Text))) {
			MessageBox::Show(L"Docente eliminado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarDocentes(); limpiarDoc(); cargarCombosSeccion();
		}
		else {
			MessageBox::Show(L"No se pudo eliminar. El docente puede estar asignado a una seccion.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void btnLimpiarDoc_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarDoc();
	}

	// =========================================
	// EVENTOS — TAB MATERIAS
	// =========================================

private: System::Void dgvMaterias_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvMaterias->Rows[e->RowIndex];
		lblIDMat->Text         = fila->Cells["id_materia"]->Value->ToString();
		txtCodigoMat->Text     = fila->Cells["codigo_materia"]->Value->ToString();
		txtNombreMat->Text     = fila->Cells["nombre_materia"]->Value->ToString();
		txtCreditosMat->Text   = fila->Cells["creditos"]->Value->ToString();
		txtSemestreMat->Text   = fila->Cells["semestre"]->Value->ToString();
		try { cbCarreraMat->SelectedValue = fila->Cells["id_carrera"]->Value; } catch (Exception^) {}
		btnActualizarMat->Enabled = true; btnEliminarMat->Enabled = true;
	}

private: System::Void btnInsertarMat_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtCodigoMat->Text->Trim() == "" || txtNombreMat->Text->Trim() == "") {
			MessageBox::Show(L"Codigo y Nombre son obligatorios.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		int creditos, semestre;
		if (!Int32::TryParse(txtCreditosMat->Text, creditos) || creditos <= 0) {
			MessageBox::Show(L"Ingrese un numero valido de creditos.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		if (!Int32::TryParse(txtSemestreMat->Text, semestre) || semestre <= 0) {
			MessageBox::Show(L"Ingrese un numero valido de semestre.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Materia^ mat = gcnew Materia();
		mat->codigo_materia = txtCodigoMat->Text->Trim();
		mat->nombre_materia = txtNombreMat->Text->Trim();
		mat->creditos       = creditos;
		mat->semestre       = semestre;
		mat->id_carrera     = Convert::ToInt32(cbCarreraMat->SelectedValue);
		CModelo^ m = gcnew CModelo();
		if (m->insertarMateria(mat)) {
			MessageBox::Show(L"Materia insertada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarMaterias(); limpiarMat();
			// Refrescar combo materias en secciones
			cargarCombosSeccion();
		}
	}

private: System::Void btnActualizarMat_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDMat->Text == "") { MessageBox::Show(L"Seleccione una materia."); return; }
		if (txtCodigoMat->Text->Trim() == "" || txtNombreMat->Text->Trim() == "") {
			MessageBox::Show(L"Codigo y Nombre son obligatorios.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		int creditos, semestre;
		if (!Int32::TryParse(txtCreditosMat->Text, creditos) || creditos <= 0) {
			MessageBox::Show(L"Ingrese un numero valido de creditos.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		if (!Int32::TryParse(txtSemestreMat->Text, semestre) || semestre <= 0) {
			MessageBox::Show(L"Ingrese un numero valido de semestre.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Materia^ mat = gcnew Materia();
		mat->id_materia     = Convert::ToInt32(lblIDMat->Text);
		mat->codigo_materia = txtCodigoMat->Text->Trim();
		mat->nombre_materia = txtNombreMat->Text->Trim();
		mat->creditos       = creditos;
		mat->semestre       = semestre;
		mat->id_carrera     = Convert::ToInt32(cbCarreraMat->SelectedValue);
		CModelo^ m = gcnew CModelo();
		if (m->actualizarMateria(mat)) {
			MessageBox::Show(L"Materia actualizada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarMaterias(); limpiarMat(); cargarCombosSeccion();
		}
	}

private: System::Void btnEliminarMat_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDMat->Text == "") { MessageBox::Show(L"Seleccione una materia."); return; }
		if (MessageBox::Show(L"Confirmar eliminacion?", L"Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes) return;
		CModelo^ m = gcnew CModelo();
		if (m->eliminarMateria(Convert::ToInt32(lblIDMat->Text))) {
			MessageBox::Show(L"Materia eliminada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarMaterias(); limpiarMat(); cargarCombosSeccion();
		}
		else {
			MessageBox::Show(L"No se pudo eliminar. La materia puede estar en uso.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void btnLimpiarMat_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarMat();
	}

	// =========================================
	// EVENTOS — TAB CICLOS
	// =========================================

private: System::Void dgvCiclos_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvCiclos->Rows[e->RowIndex];
		lblIDCic->Text       = fila->Cells["id_ciclo"]->Value->ToString();
		txtNombreCic->Text   = fila->Cells["nombre_ciclo"]->Value->ToString();
		txtAnioCic->Text     = fila->Cells["anio"]->Value->ToString();
		btnActualizarCic->Enabled = true; btnEliminarCic->Enabled = true;
	}

private: System::Void btnInsertarCic_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombreCic->Text->Trim() == "") {
			MessageBox::Show(L"El nombre del ciclo es obligatorio.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		int anio;
		if (!Int32::TryParse(txtAnioCic->Text, anio) || anio < 2000 || anio > 2100) {
			MessageBox::Show(L"Ingrese un anio valido.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		CicloAcademico^ c = gcnew CicloAcademico();
		c->nombre_ciclo = txtNombreCic->Text->Trim();
		c->anio         = anio;
		CModelo^ m = gcnew CModelo();
		if (m->insertarCiclo(c)) {
			MessageBox::Show(L"Ciclo insertado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarCiclos(); limpiarCic(); cargarCombosSeccion();
		}
	}

private: System::Void btnActualizarCic_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDCic->Text == "") { MessageBox::Show(L"Seleccione un ciclo."); return; }
		if (txtNombreCic->Text->Trim() == "") {
			MessageBox::Show(L"El nombre del ciclo es obligatorio.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		int anio;
		if (!Int32::TryParse(txtAnioCic->Text, anio) || anio < 2000 || anio > 2100) {
			MessageBox::Show(L"Ingrese un anio valido.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		CicloAcademico^ c = gcnew CicloAcademico();
		c->id_ciclo     = Convert::ToInt32(lblIDCic->Text);
		c->nombre_ciclo = txtNombreCic->Text->Trim();
		c->anio         = anio;
		CModelo^ m = gcnew CModelo();
		if (m->actualizarCiclo(c)) {
			MessageBox::Show(L"Ciclo actualizado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarCiclos(); limpiarCic(); cargarCombosSeccion();
		}
	}

private: System::Void btnEliminarCic_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDCic->Text == "") { MessageBox::Show(L"Seleccione un ciclo."); return; }
		if (MessageBox::Show(L"Confirmar eliminacion?", L"Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes) return;
		CModelo^ m = gcnew CModelo();
		if (m->eliminarCiclo(Convert::ToInt32(lblIDCic->Text))) {
			MessageBox::Show(L"Ciclo eliminado.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarCiclos(); limpiarCic(); cargarCombosSeccion();
		}
		else {
			MessageBox::Show(L"No se pudo eliminar. El ciclo puede estar en uso.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void btnLimpiarCic_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarCic();
	}

	// =========================================
	// EVENTOS — TAB SECCIONES
	// =========================================

private: System::Void dgvSecciones_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvSecciones->Rows[e->RowIndex];
		lblIDSec->Text       = fila->Cells["id_seccion"]->Value->ToString();
		txtNombreSec->Text   = fila->Cells["nombre_seccion"]->Value->ToString();
		txtJornadaSec->Text  = fila->Cells["jornada"]->Value->ToString();
		txtAulaSec->Text     = fila->Cells["aula"]->Value->ToString();
		try { cbMateriaSec->SelectedValue = fila->Cells["id_materia"]->Value; } catch (Exception^) {}
		try { cbDocenteSec->SelectedValue = fila->Cells["id_docente"]->Value; } catch (Exception^) {}
		try { cbCicloSec->SelectedValue   = fila->Cells["id_ciclo"]->Value;   } catch (Exception^) {}
		btnActualizarSec->Enabled = true; btnEliminarSec->Enabled = true;
	}

private: System::Void btnInsertarSec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombreSec->Text->Trim() == "") {
			MessageBox::Show(L"El nombre de la seccion es obligatorio.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		if (cbMateriaSec->SelectedValue == nullptr || cbDocenteSec->SelectedValue == nullptr || cbCicloSec->SelectedValue == nullptr) {
			MessageBox::Show(L"Seleccione Materia, Docente y Ciclo.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Seccion^ s = gcnew Seccion();
		s->nombre_seccion = txtNombreSec->Text->Trim();
		s->jornada        = txtJornadaSec->Text->Trim();
		s->aula           = txtAulaSec->Text->Trim();
		s->id_materia     = Convert::ToInt32(cbMateriaSec->SelectedValue);
		s->id_docente     = Convert::ToInt32(cbDocenteSec->SelectedValue);
		s->id_ciclo       = Convert::ToInt32(cbCicloSec->SelectedValue);
		CModelo^ m = gcnew CModelo();
		if (m->insertarSeccion(s)) {
			MessageBox::Show(L"Seccion insertada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarSecciones();
		cargarFacultades();
		cargarCarreras();
		CModelo^ m = gcnew CModelo();
		cbFacultadCar->DataSource = m->listarFacultadesCombo();
		cbFacultadCar->DisplayMember = "nombre_facultad";
		cbFacultadCar->ValueMember = "id_facultad"; limpiarSec();
		}
	}

private: System::Void btnActualizarSec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDSec->Text == "") { MessageBox::Show(L"Seleccione una seccion."); return; }
		if (txtNombreSec->Text->Trim() == "") {
			MessageBox::Show(L"El nombre de la seccion es obligatorio.", L"Validacion",
				MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		Seccion^ s = gcnew Seccion();
		s->id_seccion     = Convert::ToInt32(lblIDSec->Text);
		s->nombre_seccion = txtNombreSec->Text->Trim();
		s->jornada        = txtJornadaSec->Text->Trim();
		s->aula           = txtAulaSec->Text->Trim();
		s->id_materia     = Convert::ToInt32(cbMateriaSec->SelectedValue);
		s->id_docente     = Convert::ToInt32(cbDocenteSec->SelectedValue);
		s->id_ciclo       = Convert::ToInt32(cbCicloSec->SelectedValue);
		CModelo^ m = gcnew CModelo();
		if (m->actualizarSeccion(s)) {
			MessageBox::Show(L"Seccion actualizada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarSecciones();
		cargarFacultades();
		cargarCarreras();
		CModelo^ m = gcnew CModelo();
		cbFacultadCar->DataSource = m->listarFacultadesCombo();
		cbFacultadCar->DisplayMember = "nombre_facultad";
		cbFacultadCar->ValueMember = "id_facultad"; limpiarSec();
		}
	}

private: System::Void btnEliminarSec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lblIDSec->Text == "") { MessageBox::Show(L"Seleccione una seccion."); return; }
		if (MessageBox::Show(L"Confirmar eliminacion?", L"Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes) return;
		CModelo^ m = gcnew CModelo();
		if (m->eliminarSeccion(Convert::ToInt32(lblIDSec->Text))) {
			MessageBox::Show(L"Seccion eliminada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarSecciones();
		cargarFacultades();
		cargarCarreras();
		CModelo^ m = gcnew CModelo();
		cbFacultadCar->DataSource = m->listarFacultadesCombo();
		cbFacultadCar->DisplayMember = "nombre_facultad";
		cbFacultadCar->ValueMember = "id_facultad"; limpiarSec();
		}
		else {
			MessageBox::Show(L"No se pudo eliminar. La seccion puede tener inscripciones.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void btnLimpiarSec_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarSec();
	}

	// =========================================
	// BOTONES GLOBALES
	// =========================================


	void limpiarFac() {
		lblIDFac->Text = "";
		txtNombreFac->Text = "";
		if (dgvFacultades->SelectedRows->Count > 0) dgvFacultades->ClearSelection();
	}

	void limpiarCar() {
		lblIDCar->Text = "";
		txtNombreCar->Text = "";
		if (cbFacultadCar->Items->Count > 0) cbFacultadCar->SelectedIndex = 0;
		if (dgvCarreras->SelectedRows->Count > 0) dgvCarreras->ClearSelection();
	}

	// =========================================
	// EVENTOS - TAB FACULTADES
	// =========================================

private: System::Void dgvFacultades_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvFacultades->Rows[e->RowIndex];
		lblIDFac->Text = fila->Cells["id_facultad"]->Value->ToString();
		txtNombreFac->Text = fila->Cells["nombre_facultad"]->Value->ToString();
	}

private: System::Void btnInsertarFac_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtNombreFac->Text)) return;
		CModelo^ m = gcnew CModelo();
		Facultad^ f = gcnew Facultad(0, txtNombreFac->Text);
		if (m->insertarFacultad(f)) {
			cargarFacultades();
			cbFacultadCar->DataSource = m->listarFacultadesCombo();
			limpiarFac();
		} else {
			MessageBox::Show("Error al insertar Facultad");
		}
	}

private: System::Void btnActualizarFac_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblIDFac->Text)) return;
		CModelo^ m = gcnew CModelo();
		Facultad^ f = gcnew Facultad(Convert::ToInt32(lblIDFac->Text), txtNombreFac->Text);
		if (m->actualizarFacultad(f)) {
			cargarFacultades();
			cbFacultadCar->DataSource = m->listarFacultadesCombo();
			limpiarFac();
		} else {
			MessageBox::Show("Error al actualizar");
		}
	}

private: System::Void btnEliminarFac_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblIDFac->Text)) return;
		CModelo^ m = gcnew CModelo();
		if (MessageBox::Show(L"Eliminar facultad?", L"Confirmar", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			if (m->eliminarFacultad(Convert::ToInt32(lblIDFac->Text))) {
				cargarFacultades();
				cbFacultadCar->DataSource = m->listarFacultadesCombo();
				limpiarFac();
			} else {
				MessageBox::Show("Error al eliminar (Puede que haya carreras asociadas).");
			}
		}
	}

private: System::Void btnLimpiarFac_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFac();
	}

	// =========================================
	// EVENTOS - TAB CARRERAS
	// =========================================

private: System::Void dgvCarreras_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ fila = dgvCarreras->Rows[e->RowIndex];
		lblIDCar->Text = fila->Cells["id_carrera"]->Value->ToString();
		txtNombreCar->Text = fila->Cells["nombre_carrera"]->Value->ToString();
		cbFacultadCar->SelectedValue = fila->Cells["id_facultad"]->Value;
	}

private: System::Void btnInsertarCar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtNombreCar->Text) || cbFacultadCar->SelectedValue == nullptr) return;
		CModelo^ m = gcnew CModelo();
		Carrera^ c = gcnew Carrera(0, txtNombreCar->Text, Convert::ToInt32(cbFacultadCar->SelectedValue));
		if (m->insertarCarrera(c)) {
			cargarCarreras();
			limpiarCar();
		} else {
			MessageBox::Show("Error al insertar Carrera");
		}
	}

private: System::Void btnActualizarCar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblIDCar->Text) || cbFacultadCar->SelectedValue == nullptr) return;
		CModelo^ m = gcnew CModelo();
		Carrera^ c = gcnew Carrera(Convert::ToInt32(lblIDCar->Text), txtNombreCar->Text, Convert::ToInt32(cbFacultadCar->SelectedValue));
		if (m->actualizarCarrera(c)) {
			cargarCarreras();
			limpiarCar();
		} else {
			MessageBox::Show("Error al actualizar");
		}
	}

private: System::Void btnEliminarCar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblIDCar->Text)) return;
		CModelo^ m = gcnew CModelo();
		if (MessageBox::Show(L"Eliminar carrera?", L"Confirmar", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			if (m->eliminarCarrera(Convert::ToInt32(lblIDCar->Text))) {
				cargarCarreras();
				limpiarCar();
			} else {
				MessageBox::Show("Error al eliminar (Puede que haya estudiantes asociados).");
			}
		}
	}

private: System::Void btnLimpiarCar_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarCar();
	}

private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
