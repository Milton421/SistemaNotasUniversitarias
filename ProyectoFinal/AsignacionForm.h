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
	/// Formulario de asignacion de materias a estudiantes.
	/// </summary>
	public ref class AsignacionForm : public System::Windows::Forms::Form
	{
	public:
		AsignacionForm(void)
		{
			InitializeComponent();
			cbEstudiante->DropDownStyle = ComboBoxStyle::DropDownList;
			cbFacultad->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbCarrera->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbMateria->DropDownStyle    = ComboBoxStyle::DropDownList;
			dgvAsignaciones->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
			dgvAsignaciones->MultiSelect         = false;
			dgvAsignaciones->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			cargarCombos();
			cbFacultad->SelectedIndexChanged += gcnew EventHandler(this, &AsignacionForm::cbFacultad_SelectedIndexChanged);
			cbCarrera->SelectedIndexChanged += gcnew EventHandler(this, &AsignacionForm::cbCarrera_SelectedIndexChanged);
			cargarTabla();
			Tema::Aplicar(this);

		}

		AsignacionForm(int idEstudiante)
		{
			InitializeComponent();
			cbEstudiante->DropDownStyle = ComboBoxStyle::DropDownList;
			cbFacultad->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbCarrera->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbMateria->DropDownStyle    = ComboBoxStyle::DropDownList;
			dgvAsignaciones->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
			dgvAsignaciones->MultiSelect         = false;
			dgvAsignaciones->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			cargarCombos();
			cbFacultad->SelectedIndexChanged += gcnew EventHandler(this, &AsignacionForm::cbFacultad_SelectedIndexChanged);
			cbCarrera->SelectedIndexChanged += gcnew EventHandler(this, &AsignacionForm::cbCarrera_SelectedIndexChanged);
			try {
				cbEstudiante->SelectedValue = idEstudiante;
				cbEstudiante->Enabled = false;
			}
			catch (Exception^) {}
			cargarTabla();
			Tema::Aplicar(this);

		}

	protected:
		~AsignacionForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^    lblEstudianteLabel;
	private: System::Windows::Forms::Label^    lblFacultadLabel;
	private: System::Windows::Forms::Label^    lblCarreraLabel;
	private: System::Windows::Forms::Label^    lblMateriaLabel;
	private: System::Windows::Forms::Label^    lblFechaLabel;
	private: System::Windows::Forms::ComboBox^ cbEstudiante;
	private: System::Windows::Forms::ComboBox^ cbFacultad;
	private: System::Windows::Forms::ComboBox^ cbCarrera;
	private: System::Windows::Forms::ComboBox^ cbMateria;
	private: System::Windows::Forms::DateTimePicker^ dtFecha;
	private: System::Windows::Forms::DataGridView^ dgvAsignaciones;
	private: System::Windows::Forms::Button^   btnInsertar;
	private: System::Windows::Forms::Button^   btnEliminar;
	private: System::Windows::Forms::Button^   btnSalir;

	private: System::Windows::Forms::Label^    lblID;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblEstudianteLabel = (gcnew System::Windows::Forms::Label());
			this->lblFacultadLabel   = (gcnew System::Windows::Forms::Label());
			this->lblCarreraLabel    = (gcnew System::Windows::Forms::Label());
			this->lblMateriaLabel    = (gcnew System::Windows::Forms::Label());
			this->lblFechaLabel      = (gcnew System::Windows::Forms::Label());
			this->cbEstudiante       = (gcnew System::Windows::Forms::ComboBox());
			this->cbFacultad         = (gcnew System::Windows::Forms::ComboBox());
			this->cbCarrera          = (gcnew System::Windows::Forms::ComboBox());
			this->cbMateria          = (gcnew System::Windows::Forms::ComboBox());
			this->dtFecha           = (gcnew System::Windows::Forms::DateTimePicker());
			this->dgvAsignaciones    = (gcnew System::Windows::Forms::DataGridView());
			this->btnInsertar        = (gcnew System::Windows::Forms::Button());
			this->btnEliminar        = (gcnew System::Windows::Forms::Button());
			this->btnSalir           = (gcnew System::Windows::Forms::Button());

			this->lblID              = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->BeginInit();
			this->SuspendLayout();
			
			this->lblFacultadLabel->AutoSize = true;
			this->lblFacultadLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFacultadLabel->Location = System::Drawing::Point(28, 12);
			this->lblFacultadLabel->Name = L"lblFacultadLabel";
			this->lblFacultadLabel->Size = System::Drawing::Size(70, 20);
			this->lblFacultadLabel->Text = L"Facultad:";
			
			this->cbFacultad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbFacultad->Location = System::Drawing::Point(28, 35);
			this->cbFacultad->Name = L"cbFacultad";
			this->cbFacultad->Size = System::Drawing::Size(300, 26);
			
			this->lblCarreraLabel->AutoSize = true;
			this->lblCarreraLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCarreraLabel->Location = System::Drawing::Point(348, 12);
			this->lblCarreraLabel->Name = L"lblCarreraLabel";
			this->lblCarreraLabel->Size = System::Drawing::Size(70, 20);
			this->lblCarreraLabel->Text = L"Carrera:";
			
			this->cbCarrera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbCarrera->Location = System::Drawing::Point(348, 35);
			this->cbCarrera->Name = L"cbCarrera";
			this->cbCarrera->Size = System::Drawing::Size(300, 26);
			
			this->lblMateriaLabel->AutoSize = true;
			this->lblMateriaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblMateriaLabel->Location = System::Drawing::Point(28, 70);
			this->lblMateriaLabel->Name = L"lblMateriaLabel";
			this->lblMateriaLabel->Size = System::Drawing::Size(70, 20);
			this->lblMateriaLabel->Text = L"Materia:";
			
			this->cbMateria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbMateria->Location = System::Drawing::Point(28, 93);
			this->cbMateria->Name = L"cbMateria";
			this->cbMateria->Size = System::Drawing::Size(300, 26);
			
			this->lblEstudianteLabel->AutoSize = true;
			this->lblEstudianteLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblEstudianteLabel->Location = System::Drawing::Point(348, 70);
			this->lblEstudianteLabel->Name = L"lblEstudianteLabel";
			this->lblEstudianteLabel->Size = System::Drawing::Size(90, 20);
			this->lblEstudianteLabel->Text = L"Estudiante:";
			
			this->cbEstudiante->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbEstudiante->Location = System::Drawing::Point(348, 93);
			this->cbEstudiante->Name = L"cbEstudiante";
			this->cbEstudiante->Size = System::Drawing::Size(300, 26);
			
			this->lblFechaLabel->AutoSize = true;
			this->lblFechaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFechaLabel->Location = System::Drawing::Point(28, 128);
			this->lblFechaLabel->Name = L"lblFechaLabel";
			this->lblFechaLabel->Size = System::Drawing::Size(80, 20);
			this->lblFechaLabel->Text = L"Fecha Asignacion:";
			
			this->dtFecha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtFecha->Location = System::Drawing::Point(28, 150);
			this->dtFecha->Name = L"dtFecha";
			this->dtFecha->Size = System::Drawing::Size(200, 26);
			this->dtFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			
			this->dgvAsignaciones->Location = System::Drawing::Point(28, 190);
			this->dgvAsignaciones->Size = System::Drawing::Size(680, 270);

			this->dgvAsignaciones->TabIndex = 6;
			this->dgvAsignaciones->ReadOnly = true;
			this->dgvAsignaciones->AllowUserToAddRows = false;
			this->dgvAsignaciones->AllowUserToDeleteRows = false;
			this->dgvAsignaciones->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AsignacionForm::dgvAsignaciones_CellClick);
			this->dgvAsignaciones->SelectionChanged += gcnew System::EventHandler(this, &AsignacionForm::dgvAsignaciones_SelectionChanged);
			// 
			// btnInsertar
			// 
			this->btnInsertar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInsertar->Location = System::Drawing::Point(726, 190);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(115, 37);
			this->btnInsertar->TabIndex = 7;
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &AsignacionForm::btnInsertar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(726, 237);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(115, 37);
			this->btnEliminar->TabIndex = 8;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &AsignacionForm::btnEliminar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(726, 284);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(115, 37);
			this->btnSalir->TabIndex = 9;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &AsignacionForm::btnSalir_Click);
			// 

			// 

			// 
			// lblID
			// 
			this->lblID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblID->Location = System::Drawing::Point(726, 360);
			this->lblID->Name = L"lblID";
			this->lblID->Size = System::Drawing::Size(118, 26);
			this->lblID->TabIndex = 11;
			this->lblID->Text = L"";
			this->lblID->Visible = false;
			// 
			// AsignacionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(868, 488);
			this->Controls->Add(this->lblEstudianteLabel);
			this->Controls->Add(this->cbEstudiante);
			this->Controls->Add(this->lblFacultadLabel);
			this->Controls->Add(this->cbFacultad);
			this->Controls->Add(this->lblCarreraLabel);
			this->Controls->Add(this->cbCarrera);
			this->Controls->Add(this->lblMateriaLabel);
			this->Controls->Add(this->cbMateria);
			this->Controls->Add(this->lblFechaLabel);
			this->Controls->Add(this->dtFecha);
			this->Controls->Add(this->dgvAsignaciones);
			this->Controls->Add(this->btnInsertar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnSalir);

			this->Controls->Add(this->lblID);
			this->Name = L"AsignacionForm";
			this->Text = L"Asignacion de Materias";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		
		void cargarCombos() {
			CModelo^ modelo = gcnew CModelo();
			cbEstudiante->DataSource    = modelo->listarEstudiantesCombo();
			cbEstudiante->DisplayMember = "estudiante";
			cbEstudiante->ValueMember   = "id_estudiante";
			
			DataTable^ dtFac = modelo->listarFacultadesCombo();
			cbFacultad->DataSource    = dtFac;
			cbFacultad->DisplayMember = "nombre_facultad";
			cbFacultad->ValueMember   = "id_facultad";
			
			if (cbFacultad->SelectedValue != nullptr && cbFacultad->SelectedValue->GetType() == System::Int32::typeid)
				cargarCarreras(Convert::ToInt32(cbFacultad->SelectedValue));
		}

		void cargarCarreras(int id_facultad) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarCarrerasPorFacultad(id_facultad);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbCarrera->DataSource    = dt;
				cbCarrera->DisplayMember = "nombre_carrera";
				cbCarrera->ValueMember   = "id_carrera";
				cbCarrera->Enabled = true;
				if (cbCarrera->SelectedValue != nullptr && cbCarrera->SelectedValue->GetType() == System::Int32::typeid)
					cargarMaterias(Convert::ToInt32(cbCarrera->SelectedValue));
			} else {
				cbCarrera->BeginUpdate(); cbCarrera->DataSource = nullptr; cbCarrera->Items->Clear(); cbCarrera->Items->Add(""); cbCarrera->SelectedIndex = 0; cbCarrera->EndUpdate(); cbCarrera->Enabled = false;
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
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
			}
		}

		void old_cargarCombos() {
			CModelo^ modelo = gcnew CModelo();

			// Combo estudiantes
			cbEstudiante->DataSource    = modelo->listarEstudiantesCombo();
			cbEstudiante->DisplayMember = "estudiante";
			cbEstudiante->ValueMember   = "id_estudiante";

			// Combo materias
			cbMateria->DataSource    = modelo->listarMaterias();
			cbMateria->DisplayMember = "nombre_materia";
			cbMateria->ValueMember   = "id_materia";

			// Suscribir evento despues de cargar datos para evitar disparo prematuro
			cbEstudiante->SelectedIndexChanged +=
				gcnew EventHandler(this, &AsignacionForm::cbEstudiante_SelectedIndexChanged);
		}

		// Carga la tabla filtrando por el estudiante actualmente seleccionado
		void cargarTabla() {
			if (cbEstudiante->SelectedValue == nullptr) return;
			int idEst = Convert::ToInt32(cbEstudiante->SelectedValue);
			CModelo^ modelo = gcnew CModelo();
			dgvAsignaciones->DataSource =
				modelo->listarAsignacionesPorEstudiante(idEst);
		}

		// =========================================
		// EVENTOS
		// =========================================

	private: System::Void cbEstudiante_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Al cambiar de estudiante: filtrar tabla y refrescar combo de materias
		cargarTabla();
	}

	
	private: System::Void cbFacultad_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbFacultad->SelectedValue != nullptr && cbFacultad->SelectedValue->GetType() == System::Int32::typeid)
			cargarCarreras(Convert::ToInt32(cbFacultad->SelectedValue));
	}

	private: System::Void cbCarrera_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbCarrera->SelectedValue != nullptr && cbCarrera->SelectedValue->GetType() == System::Int32::typeid)
			cargarMaterias(Convert::ToInt32(cbCarrera->SelectedValue));
	}

	private: System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (cbEstudiante->SelectedValue == nullptr) { MessageBox::Show("Seleccione un estudiante."); return; }
			if (cbMateria->SelectedValue == nullptr)    { MessageBox::Show("Seleccione una materia.");   return; }
			Asignacion^ a = gcnew Asignacion();
			a->id_estudiante    = Convert::ToInt32(cbEstudiante->SelectedValue);
			a->id_materia       = Convert::ToInt32(cbMateria->SelectedValue);
			a->fecha_asignacion = dtFecha->Value.ToString("yyyy-MM-dd");
			CModelo^ modelo = gcnew CModelo();
			if (modelo->asignacionExiste(a->id_estudiante, a->id_materia)) {
				MessageBox::Show("La asignacion ya existe para este estudiante y materia.");
				return;
			}
			if (modelo->insertarAsignacion(a)) {
				MessageBox::Show("Asignacion creada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarTabla();   // recarga filtrada por estudiante actual
				lblID->Text = "";
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(lblID->Text)) {
			MessageBox::Show("Seleccione una asignacion para eliminar."); return;
		}
		if (MessageBox::Show("Confirmar eliminacion?", "Eliminar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
			return;
		int id = Convert::ToInt32(lblID->Text);
		CModelo^ modelo = gcnew CModelo();
		if (modelo->eliminarAsignacion(id)) {
			MessageBox::Show("Asignacion eliminada.", "Exito",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarTabla();   // recarga filtrada por estudiante actual
			lblID->Text = "";
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvAsignaciones_CellClick(System::Object^ sender,
		System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dgvAsignaciones->Rows[e->RowIndex];
			lblID->Text = row->Cells[0]->Value->ToString();
		}
	}

	private: System::Void dgvAsignaciones_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (dgvAsignaciones->SelectedRows->Count > 0) {
			DataGridViewRow^ row = dgvAsignaciones->SelectedRows[0];
			lblID->Text = row->Cells[0]->Value->ToString();
		}
	}
	};
}
