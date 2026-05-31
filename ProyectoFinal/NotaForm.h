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
	/// Formulario de gestion de notas academicas.
	/// </summary>
	public ref class NotaForm : public System::Windows::Forms::Form
	{
	public:
		/// <summary>Constructor.</summary>
		NotaForm(void)
		{
			InitializeComponent();
			dgvNotas->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
			dgvNotas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			lblID->Text    = "";
			lblID->Visible = false;
			cbFacultad->DropDownStyle    = System::Windows::Forms::ComboBoxStyle::DropDownList;
			cbCarrera->DropDownStyle    = System::Windows::Forms::ComboBoxStyle::DropDownList;
			cbMateria->DropDownStyle    = System::Windows::Forms::ComboBoxStyle::DropDownList;
			cbSeccion->DropDownStyle    = System::Windows::Forms::ComboBoxStyle::DropDown;
			cbInscripcion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDown;
			btnActualizar->Enabled = false;
			btnEliminar->Enabled   = false;
			cargarFacultades();
			if (cbMateria->SelectedValue != nullptr && cbMateria->SelectedValue->GetType() == System::Int32::typeid)
				cargarSecciones(Convert::ToInt32(cbMateria->SelectedValue));
			if (cbSeccion->SelectedValue != nullptr && cbSeccion->SelectedValue->GetType() == System::Int32::typeid)
				cargarInscripciones(Convert::ToInt32(cbSeccion->SelectedValue));
			// La tabla inicia vacia; se carga al seleccionar un estudiante
			cbFacultad->SelectedIndexChanged    += gcnew EventHandler(this, &NotaForm::cbFacultad_SelectedIndexChanged);
			cbCarrera->SelectedIndexChanged    += gcnew EventHandler(this, &NotaForm::cbCarrera_SelectedIndexChanged);
			cbMateria->SelectedIndexChanged    += gcnew EventHandler(this, &NotaForm::cbMateria_SelectedIndexChanged);
			cbSeccion->SelectedIndexChanged    += gcnew EventHandler(this, &NotaForm::cbSeccion_SelectedIndexChanged);
			cbInscripcion->SelectedIndexChanged += gcnew EventHandler(this, &NotaForm::cbInscripcion_SelectedIndexChanged);
			txtNota->KeyPress       += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NotaForm::txtNumeric_KeyPress);
			txtPorcentaje->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NotaForm::txtNumeric_KeyPress);
			Tema::Aplicar(this);

		}

	protected:
		/// <summary>Libera recursos.</summary>
		~NotaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^    lblFacultadLabel;
	private: System::Windows::Forms::Label^    lblCarreraLabel;
	private: System::Windows::Forms::Label^    lblMateriaLabel;
	private: System::Windows::Forms::Label^    lblSeccionLabel;
	private: System::Windows::Forms::Label^    lblInscripcionLabel;
	private: System::Windows::Forms::ComboBox^ cbFacultad;
	private: System::Windows::Forms::ComboBox^ cbCarrera;
	private: System::Windows::Forms::ComboBox^ cbMateria;
	private: System::Windows::Forms::ComboBox^ cbSeccion;
	private: System::Windows::Forms::ComboBox^ cbInscripcion;
	private: System::Windows::Forms::Label^    lblActividadLabel;
	private: System::Windows::Forms::Label^    lblNotaLabel;
	private: System::Windows::Forms::Label^    lblPorcentajeLabel;
	private: System::Windows::Forms::TextBox^  txtActividad;
	private: System::Windows::Forms::NumericUpDown^ txtNota;
	private: System::Windows::Forms::NumericUpDown^ txtPorcentaje;
	private: System::Windows::Forms::DataGridView^ dgvNotas;
	private: System::Windows::Forms::Button^   btnInsertar;
	private: System::Windows::Forms::Button^   btnActualizar;
	private: System::Windows::Forms::Button^   btnEliminar;
	private: System::Windows::Forms::Button^   btnSalir;

	private: System::Windows::Forms::Label^    lblID;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblFacultadLabel = (gcnew System::Windows::Forms::Label());
			this->lblCarreraLabel = (gcnew System::Windows::Forms::Label());
			this->lblMateriaLabel = (gcnew System::Windows::Forms::Label());
			this->lblSeccionLabel = (gcnew System::Windows::Forms::Label());
			this->lblInscripcionLabel = (gcnew System::Windows::Forms::Label());
			this->cbFacultad = (gcnew System::Windows::Forms::ComboBox());
			this->cbCarrera = (gcnew System::Windows::Forms::ComboBox());
			this->cbMateria = (gcnew System::Windows::Forms::ComboBox());
			this->cbSeccion = (gcnew System::Windows::Forms::ComboBox());
			this->cbInscripcion = (gcnew System::Windows::Forms::ComboBox());
			this->lblActividadLabel = (gcnew System::Windows::Forms::Label());
			this->lblNotaLabel = (gcnew System::Windows::Forms::Label());
			this->lblPorcentajeLabel = (gcnew System::Windows::Forms::Label());
			this->txtActividad = (gcnew System::Windows::Forms::TextBox());
			this->txtNota = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtPorcentaje = (gcnew System::Windows::Forms::NumericUpDown());
			this->dgvNotas = (gcnew System::Windows::Forms::DataGridView());
			this->btnInsertar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());

			this->lblID = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNotas))->BeginInit();
			this->SuspendLayout();
			
			this->lblFacultadLabel->AutoSize = true;
			this->lblFacultadLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFacultadLabel->Location = System::Drawing::Point(15, 10);
			this->lblFacultadLabel->Name = L"lblFacultadLabel";
			this->lblFacultadLabel->Size = System::Drawing::Size(62, 17);
			this->lblFacultadLabel->Text = L"Facultad:";
			
			this->cbFacultad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbFacultad->Location = System::Drawing::Point(15, 28);
			this->cbFacultad->Name = L"cbFacultad";
			this->cbFacultad->Size = System::Drawing::Size(174, 24);
			
			this->lblCarreraLabel->AutoSize = true;
			this->lblCarreraLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCarreraLabel->Location = System::Drawing::Point(201, 10);
			this->lblCarreraLabel->Name = L"lblCarreraLabel";
			this->lblCarreraLabel->Size = System::Drawing::Size(62, 17);
			this->lblCarreraLabel->Text = L"Carrera:";
			
			this->cbCarrera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbCarrera->Location = System::Drawing::Point(201, 28);
			this->cbCarrera->Name = L"cbCarrera";
			this->cbCarrera->Size = System::Drawing::Size(174, 24);
			
			this->lblMateriaLabel->AutoSize = true;
			this->lblMateriaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblMateriaLabel->Location = System::Drawing::Point(387, 10);
			this->lblMateriaLabel->Name = L"lblMateriaLabel";
			this->lblMateriaLabel->Size = System::Drawing::Size(59, 17);
			this->lblMateriaLabel->Text = L"Materia:";
			
			this->cbMateria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbMateria->Location = System::Drawing::Point(387, 28);
			this->cbMateria->Name = L"cbMateria";
			this->cbMateria->Size = System::Drawing::Size(174, 24);
			
			this->lblSeccionLabel->AutoSize = true;
			this->lblSeccionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSeccionLabel->Location = System::Drawing::Point(15, 63);
			this->lblSeccionLabel->Name = L"lblSeccionLabel";
			this->lblSeccionLabel->Size = System::Drawing::Size(62, 17);
			this->lblSeccionLabel->Text = L"Seccion:";
			
			this->cbSeccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbSeccion->Location = System::Drawing::Point(15, 81);
			this->cbSeccion->Name = L"cbSeccion";
			this->cbSeccion->Size = System::Drawing::Size(174, 24);
			
			this->lblInscripcionLabel->AutoSize = true;
			this->lblInscripcionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblInscripcionLabel->Location = System::Drawing::Point(201, 63);
			this->lblInscripcionLabel->Name = L"lblInscripcionLabel";
			this->lblInscripcionLabel->Size = System::Drawing::Size(79, 17);
			this->lblInscripcionLabel->Text = L"Estudiante:";
			
			this->cbInscripcion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbInscripcion->Location = System::Drawing::Point(201, 81);
			this->cbInscripcion->Name = L"cbInscripcion";
			this->cbInscripcion->Size = System::Drawing::Size(360, 24);
			
			this->lblActividadLabel->AutoSize = true;
			this->lblActividadLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblActividadLabel->Location = System::Drawing::Point(15, 116);
			this->lblActividadLabel->Name = L"lblActividadLabel";
			this->lblActividadLabel->Size = System::Drawing::Size(69, 17);
			this->lblActividadLabel->Text = L"Actividad:";
			
			this->txtActividad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtActividad->Location = System::Drawing::Point(15, 134);
			this->txtActividad->Name = L"txtActividad";
			this->txtActividad->Size = System::Drawing::Size(226, 23);
			
			this->lblNotaLabel->AutoSize = true;
			this->lblNotaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblNotaLabel->Location = System::Drawing::Point(254, 116);
			this->lblNotaLabel->Name = L"lblNotaLabel";
			this->lblNotaLabel->Size = System::Drawing::Size(42, 17);
			this->lblNotaLabel->Text = L"Nota:";
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtNota))->BeginInit();
			this->txtNota->DecimalPlaces = 2;
			this->txtNota->Minimum       = System::Decimal(gcnew cli::array<int>(4) { 0, 0, 0, 0 });
			this->txtNota->Maximum       = System::Decimal(gcnew cli::array<int>(4) { 100, 0, 0, 0 });
			this->txtNota->Increment     = System::Decimal(gcnew cli::array<int>(4) { 5, 0, 0, 65536 });
			this->txtNota->Font    = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtNota->Location = System::Drawing::Point(254, 134);
			this->txtNota->Name     = L"txtNota";
			this->txtNota->Size     = System::Drawing::Size(114, 26);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtNota))->EndInit();
			
			this->lblPorcentajeLabel->AutoSize = true;
			this->lblPorcentajeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblPorcentajeLabel->Location = System::Drawing::Point(380, 116);
			this->lblPorcentajeLabel->Name = L"lblPorcentajeLabel";
			this->lblPorcentajeLabel->Size = System::Drawing::Size(106, 17);
			this->lblPorcentajeLabel->Text = L"Porcentaje (%):";
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPorcentaje))->BeginInit();
			this->txtPorcentaje->DecimalPlaces = 1;
			this->txtPorcentaje->Minimum       = System::Decimal(gcnew cli::array<int>(4) { 0, 0, 0, 0 });
			this->txtPorcentaje->Maximum       = System::Decimal(gcnew cli::array<int>(4) { 100, 0, 0, 0 });
			this->txtPorcentaje->Increment     = System::Decimal(gcnew cli::array<int>(4) { 5, 0, 0, 0 });
			this->txtPorcentaje->Font    = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPorcentaje->Location = System::Drawing::Point(380, 134);
			this->txtPorcentaje->Name     = L"txtPorcentaje";
			this->txtPorcentaje->Size     = System::Drawing::Size(114, 26);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPorcentaje))->EndInit();
			
			this->dgvNotas->Location = System::Drawing::Point(15, 173);
			this->dgvNotas->Size = System::Drawing::Size(590, 247);

			this->dgvNotas->ReadOnly = true;
			this->dgvNotas->RowHeadersWidth = 51;
			this->dgvNotas->RowTemplate->Height = 24;
			this->dgvNotas->Size = System::Drawing::Size(615, 309);
			this->dgvNotas->TabIndex = 12;
			this->dgvNotas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &NotaForm::dgvNotas_CellClick);
			this->dgvNotas->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &NotaForm::dgvNotas_DataBindingComplete);
			this->dgvNotas->SelectionChanged    += gcnew System::EventHandler(this, &NotaForm::dgvNotas_SelectionChanged);
			// 
			// btnInsertar
			// 
			this->btnInsertar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInsertar->Location = System::Drawing::Point(644, 120);
			this->btnInsertar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(86, 33);
			this->btnInsertar->TabIndex = 13;
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &NotaForm::btnInsertar_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(644, 158);
			this->btnActualizar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(86, 33);
			this->btnActualizar->TabIndex = 14;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &NotaForm::btnActualizar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(644, 197);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(86, 33);
			this->btnEliminar->TabIndex = 15;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &NotaForm::btnEliminar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(644, 235);
			this->btnSalir->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(86, 33);
			this->btnSalir->TabIndex = 16;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &NotaForm::btnSalir_Click);
			// 

			// 
			// lblID
			// 
			this->lblID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblID->Location = System::Drawing::Point(644, 325);
			this->lblID->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblID->Name = L"lblID";
			this->lblID->Size = System::Drawing::Size(88, 21);
			this->lblID->TabIndex = 18;
			this->lblID->Visible = false;
			// 
			// NotaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 447);
			this->Controls->Add(this->lblFacultadLabel);
			this->Controls->Add(this->cbFacultad);
			this->Controls->Add(this->lblCarreraLabel);
			this->Controls->Add(this->cbCarrera);
			this->Controls->Add(this->lblMateriaLabel);
			this->Controls->Add(this->cbMateria);
			this->Controls->Add(this->lblSeccionLabel);
			this->Controls->Add(this->cbSeccion);
			this->Controls->Add(this->lblInscripcionLabel);
			this->Controls->Add(this->cbInscripcion);
			this->Controls->Add(this->lblActividadLabel);
			this->Controls->Add(this->txtActividad);
			this->Controls->Add(this->lblNotaLabel);
			this->Controls->Add(this->txtNota);
			this->Controls->Add(this->lblPorcentajeLabel);
			this->Controls->Add(this->txtPorcentaje);
			this->Controls->Add(this->dgvNotas);
			this->Controls->Add(this->btnInsertar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnSalir);

			this->Controls->Add(this->lblID);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"NotaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gestion de Notas";
			this->Load += gcnew System::EventHandler(this, &NotaForm::NotaForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNotas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// =========================================
		// HELPERS
		// =========================================

		
		void cargarFacultades() {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarFacultadesCombo();
			cbFacultad->DataSource    = dt;
			cbFacultad->DisplayMember = "nombre_facultad";
			cbFacultad->ValueMember   = "id_facultad";
		}

		void cargarCarreras(int id_facultad) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarCarrerasPorFacultad(id_facultad);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbCarrera->DataSource    = dt;
				cbCarrera->DisplayMember = "nombre_carrera";
				cbCarrera->ValueMember   = "id_carrera";
				cbCarrera->Enabled = true;
			} else {
				cbCarrera->BeginUpdate(); cbCarrera->DataSource = nullptr; cbCarrera->Items->Clear(); cbCarrera->Items->Add(""); cbCarrera->SelectedIndex = 0; cbCarrera->EndUpdate(); cbCarrera->Enabled = false;
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
				cbSeccion->BeginUpdate(); cbSeccion->DataSource = nullptr; cbSeccion->Items->Clear(); cbSeccion->Items->Add(""); cbSeccion->SelectedIndex = 0; cbSeccion->EndUpdate(); cbSeccion->Enabled = false;
				cbInscripcion->BeginUpdate(); cbInscripcion->DataSource = nullptr; cbInscripcion->Items->Clear(); cbInscripcion->Items->Add(""); cbInscripcion->SelectedIndex = 0; cbInscripcion->EndUpdate(); cbInscripcion->Enabled = false;
				btnInsertar->Enabled = false;
			}
		}

		void cargarMaterias(int id_carrera) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarMateriasPorCarrera(id_carrera);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbMateria->DataSource    = dt;
				cbMateria->DisplayMember = "nombre_materia";
				cbMateria->ValueMember   = "id_materia";
				cbMateria->Enabled = true;
			} else {
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
				cbSeccion->BeginUpdate(); cbSeccion->DataSource = nullptr; cbSeccion->Items->Clear(); cbSeccion->Items->Add(""); cbSeccion->SelectedIndex = 0; cbSeccion->EndUpdate(); cbSeccion->Enabled = false;
				cbInscripcion->BeginUpdate(); cbInscripcion->DataSource = nullptr; cbInscripcion->Items->Clear(); cbInscripcion->Items->Add(""); cbInscripcion->SelectedIndex = 0; cbInscripcion->EndUpdate(); cbInscripcion->Enabled = false;
				btnInsertar->Enabled = false;
			}
		}

		void old_cargarmaterias() {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarMaterias();
			cbMateria->DataSource    = dt;
			cbMateria->DisplayMember = "nombre_materia";
			cbMateria->ValueMember   = "id_materia";
		}

		void cargarSecciones(int id_materia) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarSeccionesPorMateria(id_materia);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbSeccion->DataSource    = dt;
				cbSeccion->DisplayMember = "nombre_seccion";
				cbSeccion->ValueMember   = "id_seccion";
				cbSeccion->Enabled = true;
			}
			else {
				cbSeccion->BeginUpdate();
				cbSeccion->DataSource = nullptr;
				cbSeccion->Items->Clear();
				cbSeccion->Items->Add("");
				cbSeccion->SelectedIndex = 0;
				cbSeccion->EndUpdate();
				cbSeccion->Enabled = false;
				cbInscripcion->BeginUpdate();
				cbInscripcion->DataSource = nullptr;
				cbInscripcion->Items->Clear();
				cbInscripcion->Items->Add("");
				cbInscripcion->SelectedIndex = 0;
				cbInscripcion->EndUpdate();
				cbInscripcion->Enabled = false;
				btnInsertar->Enabled = false;
			}
		}

		void cargarInscripciones(int id_seccion) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarInscripcionesPorSeccion(id_seccion);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbInscripcion->DataSource    = dt;
				cbInscripcion->DisplayMember = "estudiante";
				cbInscripcion->ValueMember   = "id_inscripcion";
				cbInscripcion->Enabled = true;
				btnInsertar->Enabled   = true;
			}
			else {
				cbInscripcion->BeginUpdate();
				cbInscripcion->DataSource = nullptr;
				cbInscripcion->Items->Clear();
				cbInscripcion->Items->Add("");
				cbInscripcion->SelectedIndex = 0;
				cbInscripcion->EndUpdate();
				cbInscripcion->Enabled = false;
				btnInsertar->Enabled   = false;
			}
		}

		void cargarTabla() {
			CModelo^ modelo = gcnew CModelo();
			if (cbInscripcion->SelectedValue != nullptr && cbInscripcion->SelectedValue->GetType() == System::Int32::typeid) {
				int id = Convert::ToInt32(cbInscripcion->SelectedValue);
				dgvNotas->DataSource = modelo->listarNotasPorInscripcion(id);
			}
			else {
				dgvNotas->DataSource = modelo->listarNotas();
			}
		}

		void limpiarCampos() {
			txtActividad->Text    = "";
			txtNota->Value        = System::Decimal(0);
			txtPorcentaje->Value  = System::Decimal(0);
			lblID->Text           = "";
			btnActualizar->Enabled = false;
			btnEliminar->Enabled   = false;
			if (dgvNotas->Rows->Count > 0) dgvNotas->ClearSelection();
		}

		// =========================================
		// EVENTOS
		// =========================================

	
	private: System::Void cbFacultad_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbFacultad->SelectedValue != nullptr && cbFacultad->SelectedValue->GetType() == System::Int32::typeid)
			cargarCarreras(Convert::ToInt32(cbFacultad->SelectedValue));
	}

	private: System::Void cbCarrera_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbCarrera->SelectedValue != nullptr && cbCarrera->SelectedValue->GetType() == System::Int32::typeid)
			cargarMaterias(Convert::ToInt32(cbCarrera->SelectedValue));
	}

	private: System::Void cbMateria_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbMateria->SelectedValue != nullptr && cbMateria->SelectedValue->GetType() == System::Int32::typeid)
			cargarSecciones(Convert::ToInt32(cbMateria->SelectedValue));
	}

	private: System::Void cbSeccion_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbSeccion->SelectedValue != nullptr && cbSeccion->SelectedValue->GetType() == System::Int32::typeid) {
			int id = Convert::ToInt32(cbSeccion->SelectedValue);
			cargarInscripciones(id);
		}
		else {
			cbInscripcion->BeginUpdate();
			cbInscripcion->DataSource = nullptr;
			cbInscripcion->Items->Clear();
			cbInscripcion->Items->Add("");
			cbInscripcion->SelectedIndex = 0;
			cbInscripcion->EndUpdate();
			cbInscripcion->Enabled = false;
			btnInsertar->Enabled   = false;
			cargarTabla();
		}
	}

	private: System::Void cbInscripcion_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		cargarTabla();
		btnInsertar->Enabled = (cbInscripcion->SelectedValue != nullptr);
	}

	private: System::Void dgvNotas_CellClick(System::Object^ sender,
		System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dgvNotas->Rows[e->RowIndex];
			lblID->Text         = row->Cells[0]->Value->ToString();
			txtActividad->Text  = row->Cells[2]->Value->ToString();
			try { txtNota->Value      = Convert::ToDecimal(row->Cells[3]->Value); } catch (Exception^) { txtNota->Value = System::Decimal(0); }
			try { txtPorcentaje->Value = Convert::ToDecimal(row->Cells[4]->Value); } catch (Exception^) { txtPorcentaje->Value = System::Decimal(0); }
			btnActualizar->Enabled = true;
			btnEliminar->Enabled   = true;
		}
		else {
			limpiarCampos();
		}
	}

	private: System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cbInscripcion->SelectedValue == nullptr) {
			MessageBox::Show("Seleccione un estudiante."); return;
		}
		if (String::IsNullOrWhiteSpace(txtActividad->Text)) {
			MessageBox::Show("Ingrese la actividad."); return;
		}
		double parsedNota = (double)txtNota->Value;
		double parsedPorc = (double)txtPorcentaje->Value;
		try {
			int idInsc = Convert::ToInt32(cbInscripcion->SelectedValue);
			CModelo^ modelo = gcnew CModelo();
			
			// Validar que la suma total no exceda 100%
			double totalActual = modelo->porcentajeTotalPorInscripcion(idInsc, 0);
			if (totalActual + parsedPorc > 100.0) {
				MessageBox::Show(String::Format("No se puede insertar. El porcentaje total ({0}%) excederia el 100% permitido.", totalActual + parsedPorc), 
					"Validacion", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			Nota^ nueva = gcnew Nota();
			nueva->id_inscripcion = idInsc;
			nueva->actividad      = txtActividad->Text;
			nueva->nota_obtenida  = (float)parsedNota;
			nueva->porcentaje     = (float)parsedPorc;
			if (modelo->insertarNota(nueva)) {
				MessageBox::Show("Nota insertada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarTabla();
				limpiarCampos();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblID->Text)) {
			MessageBox::Show("Seleccione una nota para actualizar."); return;
		}
		if (String::IsNullOrWhiteSpace(txtActividad->Text)) {
			MessageBox::Show("Ingrese la actividad."); return;
		}
		double parsedNota = (double)txtNota->Value;
		double parsedPorc = (double)txtPorcentaje->Value;
		try {
			int idNota = Convert::ToInt32(lblID->Text);
			int idInsc = Convert::ToInt32(cbInscripcion->SelectedValue);
			CModelo^ modelo = gcnew CModelo();
			
			// Validar que la suma total (excluyendo la nota actual) no exceda 100%
			double totalActual = modelo->porcentajeTotalPorInscripcion(idInsc, idNota);
			if (totalActual + parsedPorc > 100.0) {
				MessageBox::Show(String::Format("No se puede actualizar. El porcentaje total ({0}%) excederia el 100% permitido.", totalActual + parsedPorc), 
					"Validacion", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			Nota^ editada = gcnew Nota();
			editada->id_nota       = idNota;
			editada->actividad     = txtActividad->Text;
			editada->nota_obtenida = (float)parsedNota;
			editada->porcentaje    = (float)parsedPorc;
			if (modelo->actualizarNota(editada)) {
				MessageBox::Show("Nota actualizada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarTabla();
				limpiarCampos();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblID->Text)) {
			MessageBox::Show("Seleccione una nota para eliminar."); return;
		}
		if (MessageBox::Show("Confirmar eliminacion?", "Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
			return;
		try {
			int id = Convert::ToInt32(lblID->Text);
			CModelo^ modelo = gcnew CModelo();
			if (modelo->eliminarNota(id)) {
				MessageBox::Show("Nota eliminada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarTabla();
				limpiarCampos();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


	private: System::Void dgvNotas_DataBindingComplete(System::Object^ sender,
		System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		// Renombrar encabezados
		if (dgvNotas->Columns->Contains("id_nota"))        dgvNotas->Columns["id_nota"]->Visible        = false;
		if (dgvNotas->Columns->Contains("id_inscripcion")) dgvNotas->Columns["id_inscripcion"]->Visible  = false;
		if (dgvNotas->Columns->Contains("actividad"))      dgvNotas->Columns["actividad"]->HeaderText    = L"Actividad";
		if (dgvNotas->Columns->Contains("nota_obtenida"))  dgvNotas->Columns["nota_obtenida"]->HeaderText = L"Nota";
		if (dgvNotas->Columns->Contains("porcentaje"))     dgvNotas->Columns["porcentaje"]->HeaderText   = L"Porcentaje (%)";
		// Formatear columnas numericas a 2 decimales
		if (dgvNotas->Columns->Contains("nota_obtenida"))  dgvNotas->Columns["nota_obtenida"]->DefaultCellStyle->Format  = "F2";
		if (dgvNotas->Columns->Contains("porcentaje"))     dgvNotas->Columns["porcentaje"]->DefaultCellStyle->Format     = "F1";
	}

	private: System::Void dgvNotas_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		// Resaltar fila seleccionada con color azul suave
		for each (DataGridViewRow^ row in dgvNotas->Rows) {
			if (row->Selected) {
				row->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(210, 230, 255);
				row->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(0, 50, 120);
				row->DefaultCellStyle->Font      = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			} else {
				row->DefaultCellStyle->BackColor = System::Drawing::Color::Empty;
				row->DefaultCellStyle->ForeColor = System::Drawing::Color::Empty;
				row->DefaultCellStyle->Font      = nullptr;
			}
		}
	}

	private: System::Void txtNumeric_KeyPress(System::Object^ sender,
		System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != (char)8)
			e->Handled = true;
	}
	private: System::Void NotaForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
