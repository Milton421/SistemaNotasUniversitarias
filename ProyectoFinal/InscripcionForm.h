#pragma once
#include "Tema.h"
#include "Controlador.h"
#include "AsignacionForm.h"

namespace ProyectoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Formulario de gestion de inscripciones de estudiantes en secciones.
	/// </summary>
	public ref class InscripcionForm : public System::Windows::Forms::Form
	{
	public:
		/// <summary>Constructor.</summary>
		InscripcionForm(void)
		{
			InitializeComponent();
			cbEstudiante->DropDownStyle = ComboBoxStyle::DropDownList;
			cbFacultad->DropDownStyle   = ComboBoxStyle::DropDownList;
			cbCarrera->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbMateria->DropDownStyle    = ComboBoxStyle::DropDownList;
			cbSeccion->DropDownStyle    = ComboBoxStyle::DropDownList;
			dgvInscripciones->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
			dgvInscripciones->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			cargarCombos();
			cbFacultad->SelectedIndexChanged += gcnew EventHandler(this, &InscripcionForm::cbFacultad_SelectedIndexChanged);
			cbCarrera->SelectedIndexChanged += gcnew EventHandler(this, &InscripcionForm::cbCarrera_SelectedIndexChanged);
			cbMateria->SelectedIndexChanged += gcnew EventHandler(this, &InscripcionForm::cbMateria_SelectedIndexChanged);
			cargarTabla();
			Tema::Aplicar(this);

		}

	protected:
		/// <summary>Libera recursos.</summary>
		~InscripcionForm()
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
	private: System::Windows::Forms::Label^    lblSeccionLabel;
	private: System::Windows::Forms::Label^    lblFechaLabel;
	private: System::Windows::Forms::ComboBox^ cbEstudiante;
	private: System::Windows::Forms::ComboBox^ cbFacultad;
	private: System::Windows::Forms::ComboBox^ cbCarrera;
	private: System::Windows::Forms::ComboBox^ cbMateria;
	private: System::Windows::Forms::ComboBox^ cbSeccion;
	private: System::Windows::Forms::DateTimePicker^ dtFecha;
	private: System::Windows::Forms::DataGridView^   dgvInscripciones;
	private: System::Windows::Forms::Button^   btnInsertar;
	private: System::Windows::Forms::Button^   btnEliminar;
	private: System::Windows::Forms::Button^   btnObtener;
	private: System::Windows::Forms::Button^   btnSalir;

	private: System::Windows::Forms::Label^    lblID;

	private:
		/// <summary>Variable requerida por el disenador.</summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo requerido por el disenador. No modificar el contenido con el editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblEstudianteLabel = (gcnew System::Windows::Forms::Label());
			this->lblFacultadLabel   = (gcnew System::Windows::Forms::Label());
			this->lblCarreraLabel    = (gcnew System::Windows::Forms::Label());
			this->lblMateriaLabel    = (gcnew System::Windows::Forms::Label());
			this->lblSeccionLabel    = (gcnew System::Windows::Forms::Label());
			this->lblFechaLabel      = (gcnew System::Windows::Forms::Label());
			this->cbEstudiante       = (gcnew System::Windows::Forms::ComboBox());
			this->cbFacultad         = (gcnew System::Windows::Forms::ComboBox());
			this->cbCarrera          = (gcnew System::Windows::Forms::ComboBox());
			this->cbMateria          = (gcnew System::Windows::Forms::ComboBox());
			this->cbSeccion          = (gcnew System::Windows::Forms::ComboBox());
			this->dtFecha            = (gcnew System::Windows::Forms::DateTimePicker());
			this->dgvInscripciones   = (gcnew System::Windows::Forms::DataGridView());
			this->btnInsertar        = (gcnew System::Windows::Forms::Button());
			this->btnEliminar        = (gcnew System::Windows::Forms::Button());
			this->btnObtener         = (gcnew System::Windows::Forms::Button());
			this->btnSalir           = (gcnew System::Windows::Forms::Button());

			this->lblID              = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInscripciones))->BeginInit();
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
			
			this->lblSeccionLabel->AutoSize = true;
			this->lblSeccionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSeccionLabel->Location = System::Drawing::Point(348, 70);
			this->lblSeccionLabel->Name = L"lblSeccionLabel";
			this->lblSeccionLabel->Size = System::Drawing::Size(70, 20);
			this->lblSeccionLabel->Text = L"Seccion:";
			
			this->cbSeccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbSeccion->Location = System::Drawing::Point(348, 93);
			this->cbSeccion->Name = L"cbSeccion";
			this->cbSeccion->Size = System::Drawing::Size(300, 26);
			
			this->lblEstudianteLabel->AutoSize = true;
			this->lblEstudianteLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblEstudianteLabel->Location = System::Drawing::Point(28, 128);
			this->lblEstudianteLabel->Name = L"lblEstudianteLabel";
			this->lblEstudianteLabel->Size = System::Drawing::Size(90, 20);
			this->lblEstudianteLabel->Text = L"Estudiante:";
			
			this->cbEstudiante->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbEstudiante->Location = System::Drawing::Point(28, 151);
			this->cbEstudiante->Name = L"cbEstudiante";
			this->cbEstudiante->Size = System::Drawing::Size(300, 26);
			
			this->lblFechaLabel->AutoSize = true;
			this->lblFechaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFechaLabel->Location = System::Drawing::Point(348, 128);
			this->lblFechaLabel->Name = L"lblFechaLabel";
			this->lblFechaLabel->Size = System::Drawing::Size(55, 20);
			this->lblFechaLabel->Text = L"Fecha:";
			
			this->dtFecha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtFecha->Location = System::Drawing::Point(348, 151);
			this->dtFecha->Name = L"dtFecha";
			this->dtFecha->Size = System::Drawing::Size(200, 26);
			this->dtFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			
			this->dgvInscripciones->Location = System::Drawing::Point(28, 190);
			this->dgvInscripciones->Size = System::Drawing::Size(680, 270);

			this->dgvInscripciones->TabIndex = 6;
			this->dgvInscripciones->ReadOnly = true;
			this->dgvInscripciones->AllowUserToAddRows = false;
			this->dgvInscripciones->AllowUserToDeleteRows = false;
			this->dgvInscripciones->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &InscripcionForm::dgvInscripciones_CellClick);
			// 
			// btnInsertar
			// 
			this->btnInsertar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInsertar->Location = System::Drawing::Point(726, 190);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(118, 37);
			this->btnInsertar->TabIndex = 7;
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &InscripcionForm::btnInsertar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(726, 237);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(118, 37);
			this->btnEliminar->TabIndex = 8;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &InscripcionForm::btnEliminar_Click);
			// 
			// btnObtener
			// 
			this->btnObtener->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnObtener->Location = System::Drawing::Point(726, 284);
			this->btnObtener->Name = L"btnObtener";
			this->btnObtener->Size = System::Drawing::Size(118, 37);
			this->btnObtener->TabIndex = 9;
			this->btnObtener->Text = L"Obtener";
			this->btnObtener->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnObtener->UseVisualStyleBackColor = true;
			this->btnObtener->Click += gcnew System::EventHandler(this, &InscripcionForm::btnObtener_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(726, 331);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(118, 37);
			this->btnSalir->TabIndex = 10;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &InscripcionForm::btnSalir_Click);
			// 

			// 

			// 
			// lblID
			// 
			this->lblID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblID->Location = System::Drawing::Point(726, 380);
			this->lblID->Name = L"lblID";
			this->lblID->Size = System::Drawing::Size(118, 26);
			this->lblID->TabIndex = 12;
			this->lblID->Text = L"";
			this->lblID->Visible = false;
			// 
			// InscripcionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 458);
			this->Controls->Add(this->lblEstudianteLabel);
			this->Controls->Add(this->cbEstudiante);
			this->Controls->Add(this->lblFacultadLabel);
			this->Controls->Add(this->cbFacultad);
			this->Controls->Add(this->lblCarreraLabel);
			this->Controls->Add(this->cbCarrera);
			this->Controls->Add(this->lblMateriaLabel);
			this->Controls->Add(this->cbMateria);
			this->Controls->Add(this->lblSeccionLabel);
			this->Controls->Add(this->cbSeccion);
			this->Controls->Add(this->lblFechaLabel);
			this->Controls->Add(this->dtFecha);
			this->Controls->Add(this->dgvInscripciones);
			this->Controls->Add(this->btnInsertar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnObtener);
			this->Controls->Add(this->btnSalir);

			this->Controls->Add(this->lblID);
			this->Name = L"InscripcionForm";
			this->Text = L"Gestion de Inscripciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInscripciones))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// =========================================
		// HELPERS
		// =========================================

		
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
				cbSeccion->BeginUpdate(); cbSeccion->DataSource = nullptr; cbSeccion->Items->Clear(); cbSeccion->Items->Add(""); cbSeccion->SelectedIndex = 0; cbSeccion->EndUpdate(); cbSeccion->Enabled = false;
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
				if (cbMateria->SelectedValue != nullptr && cbMateria->SelectedValue->GetType() == System::Int32::typeid)
					cargarSecciones(Convert::ToInt32(cbMateria->SelectedValue));
			} else {
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
				cbSeccion->BeginUpdate(); cbSeccion->DataSource = nullptr; cbSeccion->Items->Clear(); cbSeccion->Items->Add(""); cbSeccion->SelectedIndex = 0; cbSeccion->EndUpdate(); cbSeccion->Enabled = false;
			}
		}

		void cargarSecciones(int id_materia) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt = modelo->listarSeccionesPorMateria(id_materia);
			if (dt != nullptr && dt->Rows->Count > 0) {
				cbSeccion->DataSource    = dt;
				cbSeccion->DisplayMember = "nombre_seccion";
				cbSeccion->ValueMember   = "id_seccion";
				cbSeccion->Enabled = true;
			} else {
				cbSeccion->BeginUpdate(); cbSeccion->DataSource = nullptr; cbSeccion->Items->Clear(); cbSeccion->Items->Add(""); cbSeccion->SelectedIndex = 0; cbSeccion->EndUpdate(); cbSeccion->Enabled = false;
			}
		}

		void old_cargarCombos() {
			CModelo^ modelo = gcnew CModelo();
			cbEstudiante->DataSource    = modelo->listarEstudiantesCombo();
			cbEstudiante->DisplayMember = "estudiante";
			cbEstudiante->ValueMember   = "id_estudiante";
			cbSeccion->DataSource       = modelo->listarSecciones();
			cbSeccion->DisplayMember    = "nombre_seccion";
			cbSeccion->ValueMember      = "id_seccion";
		}

		void cargarTabla() {
			CModelo^ modelo = gcnew CModelo();
			dgvInscripciones->DataSource = modelo->listarInscripciones();
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

	private: System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (cbEstudiante->SelectedValue == nullptr || cbSeccion->SelectedValue == nullptr) {
				MessageBox::Show(L"Seleccione estudiante y seccion.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			int idEst = Convert::ToInt32(cbEstudiante->SelectedValue);
			int idSec = Convert::ToInt32(cbSeccion->SelectedValue);
			CModelo^ control = gcnew CModelo();
			if (control->inscripcionExiste(idEst, idSec)) {
				MessageBox::Show(L"El estudiante ya esta inscrito en esa seccion.", L"Duplicado",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			Inscripcion^ nueva = gcnew Inscripcion();
			nueva->id_estudiante    = idEst;
			nueva->id_seccion       = idSec;
			nueva->fecha_inscripcion = dtFecha->Value.ToString("yyyy-MM-dd");
			if (control->insertarInscripcion(nueva)) {
				MessageBox::Show("Inscripcion registrada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				dgvInscripciones->DataSource = control->listarInscripciones();
				AsignacionForm^ af = gcnew AsignacionForm(nueva->id_estudiante);
				af->ShowDialog();
				Tema::Aplicar(this);

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrWhiteSpace(lblID->Text)) {
				MessageBox::Show("Seleccione una inscripcion para eliminar.");
				return;
			}
			int id = Convert::ToInt32(lblID->Text);
			if (MessageBox::Show("Confirmar eliminacion?", "Eliminar",
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
				return;
			CModelo^ modelo = gcnew CModelo();
			if (modelo->eliminarInscripcion(id)) {
				MessageBox::Show("Inscripcion eliminada.", "Exito",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarTabla();
				lblID->Text = "";
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnObtener_Click(System::Object^ sender, System::EventArgs^ e) {
		cargarTabla();
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvInscripciones_CellClick(System::Object^ sender,
		System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ fila = dgvInscripciones->Rows[e->RowIndex];
			lblID->Text = fila->Cells["id_inscripcion"]->Value->ToString();
		}
	}
	};
}
