#pragma once
#include "Tema.h"
#include "Controlador.h"
#include "AlumnosForm.h"
#include "AsignacionForm.h"
#include "InscripcionForm.h"
#include "NotaForm.h"
#include "InformeForm.h"
#include "GestionAcademicaForm.h"

namespace ProyectoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Formulario principal del sistema de gestion de notas.
	/// </summary>
	public ref class PrincipalForm : public System::Windows::Forms::Form
	{
	public:
		/// <summary>Constructor.</summary>
		PrincipalForm(void)
		{
			InitializeComponent();
			Tema::Aplicar(this);
		}

	protected:
		/// <summary>Libera recursos.</summary>
		~PrincipalForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblTitulo;
	private: System::Windows::Forms::Button^ btnEstudiantes;
	private: System::Windows::Forms::Button^ btnInscripciones;
	private: System::Windows::Forms::Button^ btnNotas;
	private: System::Windows::Forms::Button^ btnAsignaciones;
	private: System::Windows::Forms::Button^ btnInformes;
	private: System::Windows::Forms::Button^ btnGestionAcademica;
	private: System::Windows::Forms::Button^ btnSalirApp;

	private: System::Windows::Forms::Panel^ panelSidebar;
	private: System::Windows::Forms::Panel^ panelHeader;
	private: System::Windows::Forms::Panel^ panelContent;

	private: Form^ formularioActivo = nullptr;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitulo       = (gcnew System::Windows::Forms::Label());
			this->btnEstudiantes  = (gcnew System::Windows::Forms::Button());
			this->btnInscripciones = (gcnew System::Windows::Forms::Button());
			this->btnNotas        = (gcnew System::Windows::Forms::Button());
			this->btnAsignaciones = (gcnew System::Windows::Forms::Button());
			this->btnInformes     = (gcnew System::Windows::Forms::Button());
			this->btnGestionAcademica = (gcnew System::Windows::Forms::Button());
			this->btnSalirApp     = (gcnew System::Windows::Forms::Button());
			this->panelSidebar    = (gcnew System::Windows::Forms::Panel());
			this->panelHeader     = (gcnew System::Windows::Forms::Panel());
			this->panelContent    = (gcnew System::Windows::Forms::Panel());
			
			this->panelSidebar->SuspendLayout();
			this->panelHeader->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Height = 70;
			this->panelHeader->BackColor = Color::FromArgb(255, 255, 255);
			this->panelHeader->Controls->Add(this->lblTitulo);
			this->panelHeader->Name = L"panelHeader";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = false;
			this->lblTitulo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"SISTEMA GESTION DE NOTAS";
			// 
			// panelSidebar
			// 
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 240;
			this->panelSidebar->BackColor = Color::FromArgb(255, 255, 255);
			this->panelSidebar->Controls->Add(this->btnInformes);
			this->panelSidebar->Controls->Add(this->btnNotas);
			this->panelSidebar->Controls->Add(this->btnAsignaciones);
			this->panelSidebar->Controls->Add(this->btnInscripciones);
			this->panelSidebar->Controls->Add(this->btnEstudiantes);
			this->panelSidebar->Controls->Add(this->btnGestionAcademica);
			this->panelSidebar->Controls->Add(this->btnSalirApp);
			this->panelSidebar->Name = L"panelSidebar";
			// 
			// btnSalirApp
			// 
			this->btnSalirApp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnSalirApp->Height = 50;
			this->btnSalirApp->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnSalirApp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSalirApp->Name = L"btnSalirApp";
			this->btnSalirApp->Text = L"  Salir del Sistema";
			this->btnSalirApp->Click += gcnew System::EventHandler(this, &PrincipalForm::btnSalirApp_Click);
			// 
			// btnEstudiantes
			// 
			this->btnEstudiantes->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnEstudiantes->Height = 50;
			this->btnEstudiantes->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnEstudiantes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEstudiantes->Name = L"btnEstudiantes";
			this->btnEstudiantes->Text = L"  Gestion Estudiantes";
			this->btnEstudiantes->Click += gcnew System::EventHandler(this, &PrincipalForm::btnEstudiantes_Click);
			// 
			// btnInscripciones
			// 
			this->btnInscripciones->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnInscripciones->Height = 50;
			this->btnInscripciones->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnInscripciones->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnInscripciones->Name = L"btnInscripciones";
			this->btnInscripciones->Text = L"  Gestion Inscripciones";
			this->btnInscripciones->Click += gcnew System::EventHandler(this, &PrincipalForm::btnInscripciones_Click);
			// 
			// btnNotas
			// 
			this->btnNotas->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnNotas->Height = 50;
			this->btnNotas->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnNotas->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnNotas->Name = L"btnNotas";
			this->btnNotas->Text = L"  Gestion Notas";
			this->btnNotas->Click += gcnew System::EventHandler(this, &PrincipalForm::btnNotas_Click);
			// 
			// btnAsignaciones
			// 
			this->btnAsignaciones->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnAsignaciones->Height = 50;
			this->btnAsignaciones->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnAsignaciones->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAsignaciones->Name = L"btnAsignaciones";
			this->btnAsignaciones->Text = L"  Asignaciones";
			this->btnAsignaciones->Click += gcnew System::EventHandler(this, &PrincipalForm::btnAsignaciones_Click);
			// 
			// btnInformes
			// 
			this->btnInformes->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnInformes->Height = 50;
			this->btnInformes->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnInformes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnInformes->Name = L"btnInformes";
			this->btnInformes->Text = L"  Informes";
			this->btnInformes->Click += gcnew System::EventHandler(this, &PrincipalForm::btnInformes_Click);
			// 
			// btnGestionAcademica
			// 
			this->btnGestionAcademica->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnGestionAcademica->Height = 50;
			this->btnGestionAcademica->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btnGestionAcademica->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnGestionAcademica->Name = L"btnGestionAcademica";
			this->btnGestionAcademica->Text = L"  Gestion Academica";
			this->btnGestionAcademica->Click += gcnew System::EventHandler(this, &PrincipalForm::btnGestionAcademica_Click);
			// 
			// panelContent
			// 
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->BackColor = Color::FromArgb(248, 249, 250);
			this->panelContent->Name = L"panelContent";
			// 
			// PrincipalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 600);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelHeader);
			this->Name = L"PrincipalForm";
			this->Text = L"Sistema Gestion de Notas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &PrincipalForm::PrincipalForm_Load);
			this->panelSidebar->ResumeLayout(false);
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void PrincipalForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CModelo^ modelo = gcnew CModelo();
		if (!modelo->probarConexion()) {
			MessageBox::Show(
				L"No se pudo conectar a la base de datos MySQL.\n\n"
				L"Asegurese de que el servidor MySQL este en ejecucion y que las credenciales "
				L"(root / 123456789) sean correctas en ConexionBD.h.\n\n"
				L"La aplicacion se ejecutara, pero algunas funciones fallaran sin conexion.",
				L"Error de Conexion", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: void marcarBotonActivo(Button^ botonActivo) {
		array<Button^>^ botones = { btnGestionAcademica, btnEstudiantes, btnInscripciones, btnAsignaciones, btnNotas, btnInformes };
		for each (Button^ btn in botones) {
			if (btn == botonActivo) {
				btn->Tag       = "activo";
				btn->FlatStyle = FlatStyle::Flat;
				btn->FlatAppearance->BorderSize  = 0;
				btn->FlatAppearance->BorderColor = Color::FromArgb(21, 101, 192);
				btn->BackColor = Color::FromArgb(21, 101, 192);   
				btn->ForeColor = Color::White;
				btn->Font      = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
				btn->Padding   = System::Windows::Forms::Padding(6, 0, 0, 0);
			} else {
				btn->Tag       = "";
				btn->FlatStyle = FlatStyle::Standard;
				btn->FlatAppearance->BorderSize = 0;
				btn->BackColor = Color::FromArgb(240, 240, 240);
				btn->ForeColor = Color::Black;
				btn->Font      = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Regular);
				btn->Padding   = System::Windows::Forms::Padding(0);
			}
		}
		Tema::Aplicar(this);
	}

	private: void abrirFormularioHijo(Form^ formHijo) {
		if (formularioActivo != nullptr) {
			formularioActivo->Close();
		}
		formularioActivo = formHijo;
		formHijo->TopLevel = false;
		formHijo->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		formHijo->Dock = System::Windows::Forms::DockStyle::Fill;
		
		// Ocultar botones salir de los hijos
		for each (Control^ c in formHijo->Controls) {
			if (c->Name == "btnSalir") c->Visible = false;
		}

		this->panelContent->Controls->Add(formHijo);
		formHijo->BringToFront();
		formHijo->Show();
		
		Tema::Aplicar(this); 
	}

	private: System::Void btnEstudiantes_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnEstudiantes);
		abrirFormularioHijo(gcnew AlumnosForm());
	}

	private: System::Void btnInscripciones_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnInscripciones);
		abrirFormularioHijo(gcnew InscripcionForm());
	}

	private: System::Void btnNotas_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnNotas);
		abrirFormularioHijo(gcnew NotaForm());
	}

	private: System::Void btnAsignaciones_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnAsignaciones);
		abrirFormularioHijo(gcnew AsignacionForm());
	}

	private: System::Void btnInformes_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnInformes);
		abrirFormularioHijo(gcnew InformeForm());
	}

	private: System::Void btnGestionAcademica_Click(System::Object^ sender, System::EventArgs^ e) {
		marcarBotonActivo(btnGestionAcademica);
		abrirFormularioHijo(gcnew GestionAcademicaForm());
	}

	private: System::Void btnSalirApp_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
