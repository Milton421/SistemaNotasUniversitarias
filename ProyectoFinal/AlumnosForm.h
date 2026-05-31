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

	public ref class AlumnosForm : public System::Windows::Forms::Form
	{
	public:

		AlumnosForm(void)
		{
			InitializeComponent();
			cargarCarreras();
			CModelo^ modelo = gcnew CModelo();
			dgvEstudiantes->DataSource = modelo->listarEstudiantes();
			
			lbID->Visible = false;
			label1->Visible = false;
			txtCarnet->Visible = false;
			label2->Visible = false;

			Tema::Aplicar(this);
		}

	protected:

		~AlumnosForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		// =========================================
		// CONTROLES
		// =========================================

		System::Windows::Forms::DataGridView^ dgvEstudiantes;
		System::Windows::Forms::Panel^ panelCardForm;

		System::Windows::Forms::Button^ btnObtener;
		System::Windows::Forms::Button^ btnInsertar;
		System::Windows::Forms::Button^ btnActualizar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ labelFecha;

		System::Windows::Forms::TextBox^ txtCarnet;
		System::Windows::Forms::TextBox^ txtNombres;
		System::Windows::Forms::TextBox^ txtApellidos;
		System::Windows::Forms::TextBox^ txtCorreo;
		System::Windows::Forms::TextBox^ txtTelefono;
		System::Windows::Forms::ComboBox^ cbCarrera;
		System::Windows::Forms::DateTimePicker^ dtFecha;

		System::Windows::Forms::Label^ lbID;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->dgvEstudiantes = (gcnew System::Windows::Forms::DataGridView());
			this->panelCardForm = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			this->labelFecha = (gcnew System::Windows::Forms::Label());
			this->dtFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cbCarrera = (gcnew System::Windows::Forms::ComboBox());
			this->btnObtener = (gcnew System::Windows::Forms::Button());
			this->btnInsertar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCarnet = (gcnew System::Windows::Forms::TextBox());
			this->lbID = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEstudiantes))->BeginInit();
			this->panelCardForm->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvEstudiantes
			// 
			this->dgvEstudiantes->AllowUserToAddRows = false;
			this->dgvEstudiantes->AllowUserToDeleteRows = false;
			this->dgvEstudiantes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvEstudiantes->Location = System::Drawing::Point(20, 250);
			this->dgvEstudiantes->MultiSelect = false;
			this->dgvEstudiantes->Name = L"dgvEstudiantes";
			this->dgvEstudiantes->ReadOnly = true;
			this->dgvEstudiantes->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvEstudiantes->Size = System::Drawing::Size(750, 290);
			this->dgvEstudiantes->TabIndex = 1;
			this->dgvEstudiantes->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &AlumnosForm::dgvEstudiantes_DataBindingComplete);
			// 
			// panelCardForm
			// 
			this->panelCardForm->Controls->Add(this->label3);
			this->panelCardForm->Controls->Add(this->txtNombres);
			this->panelCardForm->Controls->Add(this->label4);
			this->panelCardForm->Controls->Add(this->txtApellidos);
			this->panelCardForm->Controls->Add(this->labelFecha);
			this->panelCardForm->Controls->Add(this->dtFecha);
			this->panelCardForm->Controls->Add(this->label5);
			this->panelCardForm->Controls->Add(this->txtCorreo);
			this->panelCardForm->Controls->Add(this->label6);
			this->panelCardForm->Controls->Add(this->txtTelefono);
			this->panelCardForm->Controls->Add(this->label7);
			this->panelCardForm->Controls->Add(this->cbCarrera);
			this->panelCardForm->Location = System::Drawing::Point(20, 20);
			this->panelCardForm->Name = L"panelCardForm";
			this->panelCardForm->Size = System::Drawing::Size(750, 160);
			this->panelCardForm->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(20, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Nombres:";
			// 
			// txtNombres
			// 
			this->txtNombres->Location = System::Drawing::Point(140, 20);
			this->txtNombres->Name = L"txtNombres";
			this->txtNombres->Size = System::Drawing::Size(220, 20);
			this->txtNombres->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(20, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Apellidos:";
			// 
			// txtApellidos
			// 
			this->txtApellidos->Location = System::Drawing::Point(140, 65);
			this->txtApellidos->Name = L"txtApellidos";
			this->txtApellidos->Size = System::Drawing::Size(220, 20);
			this->txtApellidos->TabIndex = 3;
			// 
			// labelFecha
			// 
			this->labelFecha->Location = System::Drawing::Point(20, 110);
			this->labelFecha->Name = L"labelFecha";
			this->labelFecha->Size = System::Drawing::Size(100, 23);
			this->labelFecha->TabIndex = 4;
			this->labelFecha->Text = L"Nacimiento:";
			// 
			// dtFecha
			// 
			this->dtFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtFecha->Location = System::Drawing::Point(140, 110);
			this->dtFecha->Name = L"dtFecha";
			this->dtFecha->Size = System::Drawing::Size(220, 20);
			this->dtFecha->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(400, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 23);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Correo:";
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(500, 20);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(220, 20);
			this->txtCorreo->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(400, 65);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 23);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Telefono:";
			// 
			// txtTelefono
			// 
			this->txtTelefono->Location = System::Drawing::Point(500, 65);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(220, 20);
			this->txtTelefono->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(400, 110);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 23);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Carrera:";
			// 
			// cbCarrera
			// 
			this->cbCarrera->Location = System::Drawing::Point(500, 110);
			this->cbCarrera->Name = L"cbCarrera";
			this->cbCarrera->Size = System::Drawing::Size(220, 21);
			this->cbCarrera->TabIndex = 11;
			// 
			// btnObtener
			// 
			this->btnObtener->Location = System::Drawing::Point(650, 200);
			this->btnObtener->Name = L"btnObtener";
			this->btnObtener->Size = System::Drawing::Size(120, 35);
			this->btnObtener->TabIndex = 2;
			this->btnObtener->Text = L"Refrescar Tabla";
			// 
			// btnInsertar
			// 
			this->btnInsertar->Location = System::Drawing::Point(20, 200);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(120, 35);
			this->btnInsertar->TabIndex = 3;
			this->btnInsertar->Text = L"Insertar";
			// 
			// btnActualizar
			// 
			this->btnActualizar->Location = System::Drawing::Point(150, 200);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(120, 35);
			this->btnActualizar->TabIndex = 4;
			this->btnActualizar->Text = L"Actualizar";
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(280, 200);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(120, 35);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->Location = System::Drawing::Point(410, 200);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(120, 35);
			this->btnLimpiar->TabIndex = 6;
			this->btnLimpiar->Text = L"Limpiar";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Carnet (Auto)";
			// 
			// txtCarnet
			// 
			this->txtCarnet->Location = System::Drawing::Point(0, 0);
			this->txtCarnet->Name = L"txtCarnet";
			this->txtCarnet->Size = System::Drawing::Size(100, 20);
			this->txtCarnet->TabIndex = 9;
			// 
			// lbID
			// 
			this->lbID->Location = System::Drawing::Point(0, 0);
			this->lbID->Name = L"lbID";
			this->lbID->Size = System::Drawing::Size(100, 23);
			this->lbID->TabIndex = 10;
			// 
			// AlumnosForm
			// 
			this->ClientSize = System::Drawing::Size(800, 560);
			this->Controls->Add(this->panelCardForm);
			this->Controls->Add(this->dgvEstudiantes);
			this->Controls->Add(this->btnObtener);
			this->Controls->Add(this->btnInsertar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnLimpiar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtCarnet);
			this->Controls->Add(this->lbID);
			this->Name = L"AlumnosForm";
			this->Text = L"Gestion de Notas - Estudiantes";
			this->Load += gcnew System::EventHandler(this, &AlumnosForm::AlumnosForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEstudiantes))->EndInit();
			this->panelCardForm->ResumeLayout(false);
			this->panelCardForm->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void cargarCarreras() {

			CModelo^ modelo =
				gcnew CModelo();

			DataTable^ dt =
				modelo->listarCarreras();

			cbCarrera->DataSource = dt;

			cbCarrera->DisplayMember =
				"nombre_carrera";

			cbCarrera->ValueMember =
				"id_carrera";
		}

#pragma endregion

		// =========================================
		// OBTENER
		// =========================================

	private: System::Void btnObtener_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		CModelo^ modelo =
			gcnew CModelo();

		dgvEstudiantes->DataSource =
			modelo->listarEstudiantes();
	}

		   // =========================================
		   // INSERTAR
		   // =========================================

	private: System::Void btnInsertar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (txtNombres->Text->Trim() == "") {
				MessageBox::Show(L"Los nombres son obligatorios.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txtApellidos->Text->Trim() == "") {
				MessageBox::Show(L"Los apellidos son obligatorios.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (cbCarrera->SelectedValue == nullptr) {
				MessageBox::Show(L"Seleccione una carrera.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}

			Estudiante^ nuevo =
				gcnew Estudiante();

			nuevo->carnet =
				txtCarnet->Text;

			nuevo->nombres =
				txtNombres->Text;

			nuevo->apellidos =
				txtApellidos->Text;

			nuevo->correo =
				txtCorreo->Text;

			nuevo->telefono =
				txtTelefono->Text;

			nuevo->fecha_nacimiento =
				dtFecha->Value.ToString("yyyy-MM-dd");

			nuevo->id_carrera =
				Convert::ToInt32(cbCarrera->SelectedValue);

			CModelo^ control =
				gcnew CModelo();
			
			nuevo->carnet =
				control->generarCarnet();

			if (control->insertarEstudiante(nuevo)) {

				MessageBox::Show(
					"Estudiante insertado.");

				dgvEstudiantes->DataSource =
					control->listarEstudiantes();
			}
			else {

				MessageBox::Show(
					"No se pudo insertar.");
			}
		}
		catch (Exception^ ex) {

			MessageBox::Show(
				ex->Message);
		}
	}

		   // =========================================
		   // ACTUALIZAR
		   // =========================================

	private: System::Void btnActualizar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (String::IsNullOrWhiteSpace(lbID->Text)) {
				MessageBox::Show(L"Seleccione un estudiante de la tabla.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txtCarnet->Text->Trim() == "") {
				MessageBox::Show(L"El carnet es obligatorio.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txtNombres->Text->Trim() == "") {
				MessageBox::Show(L"Los nombres son obligatorios.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txtApellidos->Text->Trim() == "") {
				MessageBox::Show(L"Los apellidos son obligatorios.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}

			Estudiante^ editado =
				gcnew Estudiante();

			editado->id_estudiante =
				Convert::ToInt32(lbID->Text);

			editado->carnet =
				txtCarnet->Text;

			editado->nombres =
				txtNombres->Text;

			editado->apellidos =
				txtApellidos->Text;

			editado->correo =
				txtCorreo->Text;

			editado->telefono =
				txtTelefono->Text;

			editado->fecha_nacimiento =
				dtFecha->Value.ToString("yyyy-MM-dd");

			editado->id_carrera =
				Convert::ToInt32(cbCarrera->SelectedValue);

			CModelo^ control =
				gcnew CModelo();

			if (control->actualizarEstudiante(editado)) {

				MessageBox::Show(
					"Registro actualizado.");

				dgvEstudiantes->DataSource =
					control->listarEstudiantes();
			}
		}
		catch (Exception^ ex) {

			MessageBox::Show(
				ex->Message);
		}
	}

		   // =========================================
		   // ELIMINAR
		   // =========================================

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		lbID->Text = L"";
		txtCarnet->Clear();
		txtNombres->Clear();
		txtApellidos->Clear();
		txtCorreo->Clear();
		txtTelefono->Clear();
		dtFecha->Value = System::DateTime::Now;
		if (cbCarrera->Items->Count > 0) cbCarrera->SelectedIndex = 0;
		if (dgvEstudiantes->SelectedRows->Count > 0) dgvEstudiantes->ClearSelection();
	}

	private: System::Void btnEliminar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (String::IsNullOrWhiteSpace(lbID->Text)) {
				MessageBox::Show(L"Seleccione un estudiante de la tabla.", L"Validacion",
					MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (MessageBox::Show(L"Confirmar eliminacion?", L"Eliminar",
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
				return;

			int id =
				Convert::ToInt32(lbID->Text);

			CModelo^ control =
				gcnew CModelo();

			if (control->eliminarEstudiante(id)) {

				MessageBox::Show(
					"Registro eliminado.");

				dgvEstudiantes->DataSource =
					control->listarEstudiantes();
			}
		}
		catch (Exception^ ex) {

			MessageBox::Show(
				ex->Message);
		}
	}


	private: System::Void dgvEstudiantes_CellClick(
		System::Object^ sender,
		System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		if (e->RowIndex >= 0) {

			DataGridViewRow^ fila =
				dgvEstudiantes->Rows[e->RowIndex];

			lbID->Text =
				fila->Cells["id_estudiante"]->Value->ToString();

			txtCarnet->Text =
				fila->Cells["carnet"]->Value->ToString();

			txtNombres->Text =
				fila->Cells["nombres"]->Value->ToString();

			txtApellidos->Text =
				fila->Cells["apellidos"]->Value->ToString();

			txtCorreo->Text =
				fila->Cells["correo"]->Value->ToString();

			txtTelefono->Text =
				fila->Cells["telefono"]->Value->ToString();

			cbCarrera->SelectedValue =
				fila->Cells["id_carrera"]->Value;

			try {
				String^ fechaStr = fila->Cells["fecha_nacimiento"]->Value->ToString();
				if (!String::IsNullOrWhiteSpace(fechaStr))
					dtFecha->Value = DateTime::Parse(fechaStr);
			}
			catch (Exception^) {}
		}
	}

	private: System::Void dgvEstudiantes_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {
		if (dgvEstudiantes->Columns->Contains("id_estudiante"))
			dgvEstudiantes->Columns["id_estudiante"]->Visible = false;
		if (dgvEstudiantes->Columns->Contains("id_carrera"))
			dgvEstudiantes->Columns["id_carrera"]->Visible = false;

		if (dgvEstudiantes->Columns->Contains("carnet")) dgvEstudiantes->Columns["carnet"]->HeaderText = L"Carnet";
		if (dgvEstudiantes->Columns->Contains("nombres")) dgvEstudiantes->Columns["nombres"]->HeaderText = L"Nombres";
		if (dgvEstudiantes->Columns->Contains("apellidos")) dgvEstudiantes->Columns["apellidos"]->HeaderText = L"Apellidos";
		if (dgvEstudiantes->Columns->Contains("correo")) {
			dgvEstudiantes->Columns["correo"]->HeaderText = L"Correo";
			dgvEstudiantes->Columns["correo"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		}
		if (dgvEstudiantes->Columns->Contains("telefono")) dgvEstudiantes->Columns["telefono"]->HeaderText = L"Telefono";
		if (dgvEstudiantes->Columns->Contains("fecha_nacimiento")) dgvEstudiantes->Columns["fecha_nacimiento"]->HeaderText = L"Fecha Nac.";
		if (dgvEstudiantes->Columns->Contains("carrera")) {
			dgvEstudiantes->Columns["carrera"]->HeaderText = L"Carrera";
			dgvEstudiantes->Columns["carrera"]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		}
	}

	private: System::Void AlumnosForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
