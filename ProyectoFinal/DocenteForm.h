#pragma once
#include "Controlador.h"

namespace ProyectoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DocenteForm : public System::Windows::Forms::Form
	{
	public:

		DocenteForm(void)
		{
			InitializeComponent();
			cargarDocentes();
		}

	protected:

		~DocenteForm()
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

		System::Windows::Forms::DataGridView^ dgvDocentes;

		System::Windows::Forms::Button^ btnObtener;
		System::Windows::Forms::Button^ btnInsertar;
		System::Windows::Forms::Button^ btnActualizar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnSalir;

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;

		System::Windows::Forms::TextBox^ txtNombres;
		System::Windows::Forms::TextBox^ txtApellidos;
		System::Windows::Forms::TextBox^ txtCorreo;
		System::Windows::Forms::TextBox^ txtEspecialidad;

		System::Windows::Forms::Label^ lbID;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->dgvDocentes    = (gcnew System::Windows::Forms::DataGridView());
			this->btnObtener     = (gcnew System::Windows::Forms::Button());
			this->btnInsertar    = (gcnew System::Windows::Forms::Button());
			this->btnActualizar  = (gcnew System::Windows::Forms::Button());
			this->btnEliminar    = (gcnew System::Windows::Forms::Button());
			this->btnSalir       = (gcnew System::Windows::Forms::Button());
			this->label1         = (gcnew System::Windows::Forms::Label());
			this->label2         = (gcnew System::Windows::Forms::Label());
			this->label3         = (gcnew System::Windows::Forms::Label());
			this->label4         = (gcnew System::Windows::Forms::Label());
			this->txtNombres     = (gcnew System::Windows::Forms::TextBox());
			this->txtApellidos   = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreo      = (gcnew System::Windows::Forms::TextBox());
			this->txtEspecialidad = (gcnew System::Windows::Forms::TextBox());
			this->lbID           = (gcnew System::Windows::Forms::Label());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dgvDocentes))->BeginInit();

			this->SuspendLayout();

			// =========================================
			// FORM
			// =========================================

			this->ClientSize =
				System::Drawing::Size(900, 480);

			this->Text =
				L"Gestion de Notas - Docentes";

			// =========================================
			// DATAGRIDVIEW
			// =========================================

			this->dgvDocentes->Location =
				System::Drawing::Point(20, 180);

			this->dgvDocentes->Size =
				System::Drawing::Size(740, 260);

			this->dgvDocentes->SelectionMode =
				System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;

			this->dgvDocentes->MultiSelect = false;

			this->dgvDocentes->CellClick +=
				gcnew DataGridViewCellEventHandler(
					this,
					&DocenteForm::dgvDocentes_CellClick);

			// =========================================
			// BOTONES
			// =========================================

			this->btnObtener->Location =
				System::Drawing::Point(790, 180);
			this->btnObtener->Size =
				System::Drawing::Size(90, 32);
			this->btnObtener->Text = L"Obtener";
			this->btnObtener->Click +=
				gcnew EventHandler(this, &DocenteForm::btnObtener_Click);

			this->btnInsertar->Location =
				System::Drawing::Point(790, 222);
			this->btnInsertar->Size =
				System::Drawing::Size(90, 32);
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->Click +=
				gcnew EventHandler(this, &DocenteForm::btnInsertar_Click);

			this->btnActualizar->Location =
				System::Drawing::Point(790, 264);
			this->btnActualizar->Size =
				System::Drawing::Size(90, 32);
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->Click +=
				gcnew EventHandler(this, &DocenteForm::btnActualizar_Click);

			this->btnEliminar->Location =
				System::Drawing::Point(790, 306);
			this->btnEliminar->Size =
				System::Drawing::Size(90, 32);
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Click +=
				gcnew EventHandler(this, &DocenteForm::btnEliminar_Click);

			this->btnSalir->Location =
				System::Drawing::Point(790, 380);
			this->btnSalir->Size =
				System::Drawing::Size(90, 32);
			this->btnSalir->Text = L"Salir";
			this->btnSalir->Click +=
				gcnew EventHandler(this, &DocenteForm::btnSalir_Click);

			// =========================================
			// LABELS
			// =========================================

			this->label1->Text     = L"Nombres:";
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Size     = System::Drawing::Size(90, 20);

			this->label2->Text     = L"Apellidos:";
			this->label2->Location = System::Drawing::Point(20, 60);
			this->label2->Size     = System::Drawing::Size(90, 20);

			this->label3->Text     = L"Correo";
			this->label3->Location = System::Drawing::Point(20, 100);
			this->label3->Size     = System::Drawing::Size(90, 20);

			this->label4->Text     = L"Especialidad";
			this->label4->Location = System::Drawing::Point(20, 140);
			this->label4->Size     = System::Drawing::Size(90, 20);

			// =========================================
			// TEXTBOXES
			// =========================================

			this->txtNombres->Location =
				System::Drawing::Point(130, 18);
			this->txtNombres->Size =
				System::Drawing::Size(220, 22);

			this->txtApellidos->Location =
				System::Drawing::Point(130, 58);
			this->txtApellidos->Size =
				System::Drawing::Size(220, 22);

			this->txtCorreo->Location =
				System::Drawing::Point(130, 98);
			this->txtCorreo->Size =
				System::Drawing::Size(220, 22);

			this->txtEspecialidad->Location =
				System::Drawing::Point(130, 138);
			this->txtEspecialidad->Size =
				System::Drawing::Size(220, 22);

			// =========================================
			// LABEL ID (oculto)
			// =========================================

			this->lbID->Location =
				System::Drawing::Point(400, 20);
			this->lbID->Size =
				System::Drawing::Size(120, 23);
			this->lbID->Visible = false;

			// =========================================
			// AGREGAR CONTROLES
			// =========================================

			this->Controls->Add(this->dgvDocentes);

			this->Controls->Add(this->btnObtener);
			this->Controls->Add(this->btnInsertar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnSalir);

			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);

			this->Controls->Add(this->txtNombres);
			this->Controls->Add(this->txtApellidos);
			this->Controls->Add(this->txtCorreo);
			this->Controls->Add(this->txtEspecialidad);

			this->Controls->Add(this->lbID);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dgvDocentes))->EndInit();

			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void cargarDocentes() {

			CModelo^ modelo = gcnew CModelo();
			dgvDocentes->DataSource = modelo->listarDocentes();
		}

#pragma endregion

		// =========================================
		// OBTENER
		// =========================================

	private: System::Void btnObtener_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		cargarDocentes();
	}

		// =========================================
		// INSERTAR
		// =========================================

	private: System::Void btnInsertar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (txtNombres->Text->Trim() == "" ||
				txtApellidos->Text->Trim() == "") {
				MessageBox::Show(L"Nombres y Apellidos son obligatorios.");
				return;
			}

			Docente^ nuevo = gcnew Docente();

			nuevo->nombres      = txtNombres->Text->Trim();
			nuevo->apellidos    = txtApellidos->Text->Trim();
			nuevo->correo       = txtCorreo->Text->Trim();
			nuevo->especialidad = txtEspecialidad->Text->Trim();

			CModelo^ control = gcnew CModelo();

			if (control->insertarDocente(nuevo)) {

				MessageBox::Show(L"Docente insertado correctamente.");
				cargarDocentes();
				limpiarCampos();
			}
			else {
				MessageBox::Show(L"No se pudo insertar el docente.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

		// =========================================
		// ACTUALIZAR
		// =========================================

	private: System::Void btnActualizar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (lbID->Text == "") {
				MessageBox::Show(L"Seleccione un docente de la tabla.");
				return;
			}

			if (txtNombres->Text->Trim() == "" ||
				txtApellidos->Text->Trim() == "") {
				MessageBox::Show(L"Nombres y Apellidos son obligatorios.");
				return;
			}

			Docente^ editado = gcnew Docente();

			editado->id_docente   = Convert::ToInt32(lbID->Text);
			editado->nombres      = txtNombres->Text->Trim();
			editado->apellidos    = txtApellidos->Text->Trim();
			editado->correo       = txtCorreo->Text->Trim();
			editado->especialidad = txtEspecialidad->Text->Trim();

			CModelo^ control = gcnew CModelo();

			if (control->actualizarDocente(editado)) {

				MessageBox::Show(L"Docente actualizado correctamente.");
				cargarDocentes();
				limpiarCampos();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

		// =========================================
		// ELIMINAR
		// =========================================

	private: System::Void btnEliminar_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		try {

			if (lbID->Text == "") {
				MessageBox::Show(L"Seleccione un docente de la tabla.");
				return;
			}

			int id = Convert::ToInt32(lbID->Text);

			CModelo^ control = gcnew CModelo();

			if (control->eliminarDocente(id)) {

				MessageBox::Show(L"Docente eliminado.");
				cargarDocentes();
				limpiarCampos();
			}
			else {
				MessageBox::Show(
					L"No se pudo eliminar. El docente puede estar asignado a una seccion.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

		// =========================================
		// SELECCIONAR FILA
		// =========================================

	private: System::Void dgvDocentes_CellClick(
		System::Object^ sender,
		System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		if (e->RowIndex >= 0) {

			DataGridViewRow^ fila =
				dgvDocentes->Rows[e->RowIndex];

			lbID->Text =
				fila->Cells["id_docente"]->Value->ToString();

			txtNombres->Text =
				fila->Cells["nombres"]->Value->ToString();

			txtApellidos->Text =
				fila->Cells["apellidos"]->Value->ToString();

			txtCorreo->Text =
				fila->Cells["correo"]->Value->ToString();

			txtEspecialidad->Text =
				fila->Cells["especialidad"]->Value->ToString();
		}
	}

		// =========================================
		// SALIR
		// =========================================

	private: System::Void btnSalir_Click(
		System::Object^ sender,
		System::EventArgs^ e) {

		Close();
	}

		// =========================================
		// LIMPIAR CAMPOS
		// =========================================

	private: void limpiarCampos() {
		lbID->Text            = "";
		txtNombres->Text      = "";
		txtApellidos->Text    = "";
		txtCorreo->Text       = "";
		txtEspecialidad->Text = "";
	}

	};
}
