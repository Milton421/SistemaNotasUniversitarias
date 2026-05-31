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
	/// Formulario de informes y estadisticas academicas.
	/// </summary>
	public ref class InformeForm : public System::Windows::Forms::Form
	{
	public:
		/// <summary>Constructor.</summary>
		InformeForm(void)
		{
			InitializeComponent();
			dgvInforme->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvInforme->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			cargarCombos();
			cargarInformeGeneral();
			Tema::Aplicar(this);
		}

	protected:
		~InformeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dgvInforme;
	private: System::Windows::Forms::Label^  lblFacultad;
	private: System::Windows::Forms::Label^  lblCarrera;
	private: System::Windows::Forms::Label^  lblMateria;
	private: System::Windows::Forms::ComboBox^ cbFacultad;
	private: System::Windows::Forms::ComboBox^ cbCarrera;
	private: System::Windows::Forms::ComboBox^ cbMateria;
	private: System::Windows::Forms::Button^ btnVerTodo;
	private: System::Windows::Forms::Button^ btnPromedios;
	private: System::Windows::Forms::Button^ btnInforme;
	
	private: System::Windows::Forms::Panel^ panelCardAprobados;
	private: System::Windows::Forms::Panel^ panelCardMaxima;
	private: System::Windows::Forms::Panel^ panelCardMinima;

	private: System::Windows::Forms::Label^  lblAprobadosTitulo;
	private: System::Windows::Forms::Label^  lblAprobados;
	private: System::Windows::Forms::Label^  lblMaximaTitulo;
	private: System::Windows::Forms::Label^  lblMaxima;
	private: System::Windows::Forms::Label^  lblMinimaTitulo;
	private: System::Windows::Forms::Label^  lblMinima;
	private: System::Windows::Forms::Label^  lblEstado;

	private: System::Windows::Forms::Panel^ panelCardTotal;
	private: System::Windows::Forms::Panel^ panelCardPromedio;
	private: System::Windows::Forms::Panel^ panelCardReprobados;
	private: System::Windows::Forms::Label^  lblTotalTitulo;
	private: System::Windows::Forms::Label^  lblTotal;
	private: System::Windows::Forms::Label^  lblPromedioTitulo;
	private: System::Windows::Forms::Label^  lblPromedio;
	private: System::Windows::Forms::Label^  lblReprobadosTitulo;
	private: System::Windows::Forms::Label^  lblReprobados;
	private: System::Windows::Forms::Button^ btnExportar;

	private:
		/// <summary>Variable requerida por el disenador.</summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo requerido por el disenador. No modificar el contenido con el editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvInforme       = (gcnew System::Windows::Forms::DataGridView());
			this->lblFacultad      = (gcnew System::Windows::Forms::Label());
			this->lblCarrera       = (gcnew System::Windows::Forms::Label());
			this->lblMateria       = (gcnew System::Windows::Forms::Label());
			this->cbFacultad       = (gcnew System::Windows::Forms::ComboBox());
			this->cbCarrera        = (gcnew System::Windows::Forms::ComboBox());
			this->cbMateria        = (gcnew System::Windows::Forms::ComboBox());
			this->btnVerTodo       = (gcnew System::Windows::Forms::Button());
			this->btnPromedios     = (gcnew System::Windows::Forms::Button());
			this->btnInforme       = (gcnew System::Windows::Forms::Button());
			
			this->panelCardAprobados = (gcnew System::Windows::Forms::Panel());
			this->panelCardMaxima    = (gcnew System::Windows::Forms::Panel());
			this->panelCardMinima    = (gcnew System::Windows::Forms::Panel());

			this->lblAprobadosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblAprobados     = (gcnew System::Windows::Forms::Label());
			this->lblMaximaTitulo  = (gcnew System::Windows::Forms::Label());
			this->lblMaxima        = (gcnew System::Windows::Forms::Label());
			this->lblMinimaTitulo  = (gcnew System::Windows::Forms::Label());
			this->lblMinima        = (gcnew System::Windows::Forms::Label());
			this->lblEstado        = (gcnew System::Windows::Forms::Label());
			this->panelCardTotal      = (gcnew System::Windows::Forms::Panel());
			this->panelCardPromedio   = (gcnew System::Windows::Forms::Panel());
			this->panelCardReprobados = (gcnew System::Windows::Forms::Panel());
			this->lblTotalTitulo      = (gcnew System::Windows::Forms::Label());
			this->lblTotal            = (gcnew System::Windows::Forms::Label());
			this->lblPromedioTitulo   = (gcnew System::Windows::Forms::Label());
			this->lblPromedio         = (gcnew System::Windows::Forms::Label());
			this->lblReprobadosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblReprobados       = (gcnew System::Windows::Forms::Label());
			this->btnExportar         = (gcnew System::Windows::Forms::Button());
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInforme))->BeginInit();
			this->panelCardAprobados->SuspendLayout();
			this->panelCardMaxima->SuspendLayout();
			this->panelCardMinima->SuspendLayout();
			this->panelCardTotal->SuspendLayout();
			this->panelCardPromedio->SuspendLayout();
			this->panelCardReprobados->SuspendLayout();
			this->SuspendLayout();
			
			// 
			// TARJETA: Aprobados
			// 
			this->panelCardAprobados->Name = L"panelCardDash";
			this->panelCardAprobados->Location = System::Drawing::Point(20, 20);
			this->panelCardAprobados->Size = System::Drawing::Size(220, 100);
			this->panelCardAprobados->Controls->Add(this->lblAprobadosTitulo);
			this->panelCardAprobados->Controls->Add(this->lblAprobados);
			// 
			// lblAprobadosTitulo
			// 
			this->lblAprobadosTitulo->AutoSize = true;
			this->lblAprobadosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblAprobadosTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblAprobadosTitulo->Location = System::Drawing::Point(15, 64);
			this->lblAprobadosTitulo->Name = L"lblAprobadosTitulo";
			this->lblAprobadosTitulo->Text = L"Estudiantes Aprobados";
			//
			// lblAprobados
			//
			this->lblAprobados->AutoSize = true;
			this->lblAprobados->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblAprobados->Location = System::Drawing::Point(12, 12);
			this->lblAprobados->Name = L"lblAprobados";
			this->lblAprobados->Text = L"--";

			// 
			// TARJETA: Maxima
			// 
			this->panelCardMaxima->Name = L"panelCardDash";
			this->panelCardMaxima->Location = System::Drawing::Point(260, 20);
			this->panelCardMaxima->Size = System::Drawing::Size(220, 100);
			this->panelCardMaxima->Controls->Add(this->lblMaximaTitulo);
			this->panelCardMaxima->Controls->Add(this->lblMaxima);
			// 
			// lblMaximaTitulo
			// 
			this->lblMaximaTitulo->AutoSize = true;
			this->lblMaximaTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblMaximaTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblMaximaTitulo->Location = System::Drawing::Point(15, 64);
			this->lblMaximaTitulo->Name = L"lblMaximaTitulo";
			this->lblMaximaTitulo->Text = L"Nota Maxima";
			//
			// lblMaxima
			//
			this->lblMaxima->AutoSize = true;
			this->lblMaxima->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblMaxima->Location = System::Drawing::Point(12, 12);
			this->lblMaxima->Name = L"lblMaxima";
			this->lblMaxima->Text = L"--";

			// 
			// TARJETA: Minima
			// 
			this->panelCardMinima->Name = L"panelCardDash";
			this->panelCardMinima->Location = System::Drawing::Point(500, 20);
			this->panelCardMinima->Size = System::Drawing::Size(220, 100);
			this->panelCardMinima->Controls->Add(this->lblMinimaTitulo);
			this->panelCardMinima->Controls->Add(this->lblMinima);
			// 
			// lblMinimaTitulo
			// 
			this->lblMinimaTitulo->AutoSize = true;
			this->lblMinimaTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblMinimaTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblMinimaTitulo->Location = System::Drawing::Point(15, 64);
			this->lblMinimaTitulo->Name = L"lblMinimaTitulo";
			this->lblMinimaTitulo->Text = L"Nota Minima";
			//
			// lblMinima
			//
			this->lblMinima->AutoSize = true;
			this->lblMinima->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblMinima->Location = System::Drawing::Point(12, 12);
			this->lblMinima->Name = L"lblMinima";
			this->lblMinima->Text = L"--";

			
			//
			// TARJETA: Total estudiantes
			//
			this->panelCardTotal->Name = L"panelCardDash";
			this->panelCardTotal->Location = System::Drawing::Point(20, 130);
			this->panelCardTotal->Size = System::Drawing::Size(180, 90);
			this->panelCardTotal->Controls->Add(this->lblTotalTitulo);
			this->panelCardTotal->Controls->Add(this->lblTotal);

			this->lblTotalTitulo->AutoSize = true;
			this->lblTotalTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblTotalTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblTotalTitulo->Location = System::Drawing::Point(15, 64);
			this->lblTotalTitulo->Text = L"Total Estudiantes";

			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblTotal->Location = System::Drawing::Point(12, 12);
			this->lblTotal->Text = L"--";

			//
			// TARJETA: Promedio general
			//
			this->panelCardPromedio->Name = L"panelCardDash";
			this->panelCardPromedio->Location = System::Drawing::Point(210, 130);
			this->panelCardPromedio->Size = System::Drawing::Size(180, 90);
			this->panelCardPromedio->Controls->Add(this->lblPromedioTitulo);
			this->panelCardPromedio->Controls->Add(this->lblPromedio);

			this->lblPromedioTitulo->AutoSize = true;
			this->lblPromedioTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblPromedioTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblPromedioTitulo->Location = System::Drawing::Point(15, 64);
			this->lblPromedioTitulo->Text = L"Promedio General";

			this->lblPromedio->AutoSize = true;
			this->lblPromedio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblPromedio->Location = System::Drawing::Point(12, 12);
			this->lblPromedio->Text = L"--";

			//
			// TARJETA: % Reprobados
			//
			this->panelCardReprobados->Name = L"panelCardDash";
			this->panelCardReprobados->Location = System::Drawing::Point(400, 130);
			this->panelCardReprobados->Size = System::Drawing::Size(180, 90);
			this->panelCardReprobados->Controls->Add(this->lblReprobadosTitulo);
			this->panelCardReprobados->Controls->Add(this->lblReprobados);

			this->lblReprobadosTitulo->AutoSize = true;
			this->lblReprobadosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular));
			this->lblReprobadosTitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 120);
			this->lblReprobadosTitulo->Location = System::Drawing::Point(15, 64);
			this->lblReprobadosTitulo->Text = L"% Reprobados";

			this->lblReprobados->AutoSize = true;
			this->lblReprobados->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
			this->lblReprobados->Location = System::Drawing::Point(12, 12);
			this->lblReprobados->Text = L"--";

			//
			// btnExportar
			//
			this->btnExportar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnExportar->Location = System::Drawing::Point(715, 170);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(120, 28);
			this->btnExportar->Text = L"Exportar CSV";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &InformeForm::btnExportar_Click);

			// 
			// Filtros
			// 
			this->lblFacultad->AutoSize = true;
			this->lblFacultad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFacultad->Location = System::Drawing::Point(20, 235);
			this->lblFacultad->Name = L"lblFacultad";
			this->lblFacultad->Size = System::Drawing::Size(70, 20);
			this->lblFacultad->Text = L"Facultad:";
			
			this->cbFacultad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbFacultad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbFacultad->Location = System::Drawing::Point(100, 232);
			this->cbFacultad->Name = L"cbFacultad";
			this->cbFacultad->Size = System::Drawing::Size(200, 26);
			this->cbFacultad->SelectedIndexChanged += gcnew System::EventHandler(this, &InformeForm::cbFacultad_SelectedIndexChanged);
			
			this->lblCarrera->AutoSize = true;
			this->lblCarrera->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCarrera->Location = System::Drawing::Point(310, 235);
			this->lblCarrera->Name = L"lblCarrera";
			this->lblCarrera->Size = System::Drawing::Size(60, 20);
			this->lblCarrera->Text = L"Carrera:";
			
			this->cbCarrera->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbCarrera->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbCarrera->Location = System::Drawing::Point(380, 232);
			this->cbCarrera->Name = L"cbCarrera";
			this->cbCarrera->Size = System::Drawing::Size(200, 26);
			this->cbCarrera->SelectedIndexChanged += gcnew System::EventHandler(this, &InformeForm::cbCarrera_SelectedIndexChanged);
			
			this->lblMateria->AutoSize = true;
			this->lblMateria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblMateria->Location = System::Drawing::Point(20, 270);
			this->lblMateria->Name = L"lblMateria";
			this->lblMateria->Size = System::Drawing::Size(60, 20);
			this->lblMateria->Text = L"Materia:";
			
			this->cbMateria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbMateria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbMateria->Location = System::Drawing::Point(100, 267);
			this->cbMateria->Name = L"cbMateria";
			this->cbMateria->Size = System::Drawing::Size(200, 26);
			this->cbMateria->SelectedIndexChanged += gcnew System::EventHandler(this, &InformeForm::cbMateria_SelectedIndexChanged);
			
			// Buttons
			this->btnVerTodo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnVerTodo->Location = System::Drawing::Point(320, 267);
			this->btnVerTodo->Name = L"btnVerTodo";
			this->btnVerTodo->Size = System::Drawing::Size(100, 28);
			this->btnVerTodo->Text = L"Ver Todo";
			this->btnVerTodo->UseVisualStyleBackColor = true;
			this->btnVerTodo->Click += gcnew System::EventHandler(this, &InformeForm::btnVerTodo_Click);

			this->btnPromedios->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnPromedios->Location = System::Drawing::Point(430, 267);
			this->btnPromedios->Name = L"btnPromedios";
			this->btnPromedios->Size = System::Drawing::Size(115, 28);
			this->btnPromedios->Text = L"Promedios";
			this->btnPromedios->UseVisualStyleBackColor = true;
			this->btnPromedios->Click += gcnew System::EventHandler(this, &InformeForm::btnPromedios_Click);

			this->btnInforme->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnInforme->Location = System::Drawing::Point(555, 267);
			this->btnInforme->Name = L"btnInforme";
			this->btnInforme->Size = System::Drawing::Size(150, 28);
			this->btnInforme->Text = L"Informe Completo";
			this->btnInforme->UseVisualStyleBackColor = true;
			this->btnInforme->Click += gcnew System::EventHandler(this, &InformeForm::btnInforme_Click);
			
			// DGV
			this->dgvInforme->Location = System::Drawing::Point(20, 305);
			this->dgvInforme->Size = System::Drawing::Size(850, 300);

			this->dgvInforme->AllowUserToDeleteRows = false;
			this->dgvInforme->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &InformeForm::dgvInforme_DataBindingComplete);
			// 
			// lblEstado
			// 
			this->lblEstado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lblEstado->AutoSize = true;
			this->lblEstado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblEstado->Location = System::Drawing::Point(20, 500);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Text = L"";
			// 
			// InformeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 650);
			this->Controls->Add(this->panelCardAprobados);
			this->Controls->Add(this->panelCardMaxima);
			this->Controls->Add(this->panelCardMinima);
			this->Controls->Add(this->panelCardTotal);
			this->Controls->Add(this->panelCardPromedio);
			this->Controls->Add(this->panelCardReprobados);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->panelCardMaxima);
			this->Controls->Add(this->panelCardMinima);
			this->Controls->Add(this->dgvInforme);
			this->Controls->Add(this->lblFacultad);
			this->Controls->Add(this->cbFacultad);
			this->Controls->Add(this->lblCarrera);
			this->Controls->Add(this->cbCarrera);
			this->Controls->Add(this->lblMateria);
			this->Controls->Add(this->cbMateria);
			this->Controls->Add(this->btnVerTodo);
			this->Controls->Add(this->btnPromedios);
			this->Controls->Add(this->btnInforme);
			this->Controls->Add(this->lblEstado);
			this->Name = L"InformeForm";
			this->Text = L"Dashboard de Informes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInforme))->EndInit();
			this->panelCardTotal->ResumeLayout(false);
			this->panelCardTotal->PerformLayout();
			this->panelCardPromedio->ResumeLayout(false);
			this->panelCardPromedio->PerformLayout();
			this->panelCardReprobados->ResumeLayout(false);
			this->panelCardReprobados->PerformLayout();
			this->panelCardAprobados->ResumeLayout(false);
			this->panelCardAprobados->PerformLayout();
			this->panelCardMaxima->ResumeLayout(false);
			this->panelCardMaxima->PerformLayout();
			this->panelCardMinima->ResumeLayout(false);
			this->panelCardMinima->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// =========================================
		// HELPERS
		// =========================================

		int obtenerIdMateriaSeleccionada() {
			if (cbMateria->SelectedIndex <= 0) return -1;
			try {
				DataRowView^ drv = dynamic_cast<DataRowView^>(cbMateria->SelectedItem);
				if (drv != nullptr)
					return Convert::ToInt32(drv["id_materia"]);
			}
			catch (Exception^) {}
			return -1;
		}

		void actualizarEstadisticas(int idMateria) {
			try {
				CModelo^ ctrl = gcnew CModelo();
				int aprobados = 0, total = 0;
				float mx = 0, mn = 0, prom = 0;

				if (idMateria < 0) {
					aprobados = ctrl->numeroAprobados();
					total     = ctrl->totalEstudiantes();
					mx        = ctrl->notaMaxima();
					mn        = ctrl->notaMinima();
					prom      = ctrl->promedioGeneral();
				} else {
					aprobados = ctrl->numeroAprobadosPorMateria(idMateria);
					total     = ctrl->totalEstudiantesPorMateria(idMateria);
					mx        = ctrl->notaMaximaPorMateria(idMateria);
					mn        = ctrl->notaMinimaPorMateria(idMateria);
					prom      = ctrl->promedioPorMateriaValor(idMateria);
				}

				int reprobados = total - aprobados;
				float pctRep   = (total > 0) ? (reprobados * 100.0f / total) : 0.0f;

				lblAprobados->Text = aprobados.ToString();
				lblMaxima->Text    = (mx > 0) ? mx.ToString("F2") : "--";
				lblMinima->Text    = (mn > 0) ? mn.ToString("F2") : "--";
				lblTotal->Text     = total.ToString();
				lblPromedio->Text  = (total > 0) ? prom.ToString("F2") : "--";
				lblReprobados->Text = pctRep.ToString("F1") + "%";
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error estadisticas:\n" + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		void cargarInformeGeneral() {
			try {
				CModelo^ ctrl = gcnew CModelo();
				dgvInforme->DataSource = ctrl->informeGeneral();
				actualizarEstadisticas(-1);
				lblEstado->Text = L"Informe general cargado.";
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error informe general:\n" + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void cargarInformePorMateria(int idMateria) {
			try {
				CModelo^ ctrl = gcnew CModelo();
				dgvInforme->DataSource = ctrl->informePorMateria(idMateria);
				actualizarEstadisticas(idMateria);
				lblEstado->Text = L"Informe filtrado por materia.";
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error informe por materia:\n" + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		
		
		void cargarCombos() {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dtFac = modelo->listarFacultadesCombo();
			
			DataRow^ rowF = dtFac->NewRow();
			rowF["id_facultad"] = safe_cast<System::Object^>(0);
			rowF["nombre_facultad"] = "-- Todas las facultades --";
			dtFac->Rows->InsertAt(rowF, 0);
			
			cbFacultad->DataSource    = dtFac;
			cbFacultad->DisplayMember = "nombre_facultad";
			cbFacultad->ValueMember   = "id_facultad";
		}

		void cargarCarreras(int id_facultad) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt;
			if (id_facultad <= 0) {
				dt = modelo->listarCarreras();
			} else {
				dt = modelo->listarCarrerasPorFacultad(id_facultad);
			}
			
			DataRow^ rowC = dt->NewRow();
			rowC["id_carrera"] = safe_cast<System::Object^>(0);
			rowC["nombre_carrera"] = "-- Todas las carreras --";
			dt->Rows->InsertAt(rowC, 0);

			if (dt != nullptr && dt->Rows->Count > 0) {
				cbCarrera->DataSource    = dt;
				cbCarrera->DisplayMember = "nombre_carrera";
				cbCarrera->ValueMember   = "id_carrera";
				cbCarrera->Enabled = true;
			} else {
				cbCarrera->BeginUpdate(); cbCarrera->DataSource = nullptr; cbCarrera->Items->Clear(); cbCarrera->Items->Add(""); cbCarrera->SelectedIndex = 0; cbCarrera->EndUpdate(); cbCarrera->Enabled = false;
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
			}
		}

		void cargarMaterias(int id_carrera) {
			CModelo^ modelo = gcnew CModelo();
			DataTable^ dt;
			if (id_carrera <= 0) {
				dt = modelo->listarMaterias();
			} else {
				dt = modelo->listarMateriasPorCarrera(id_carrera);
			}
			
			DataRow^ rowM = dt->NewRow();
			rowM["id_materia"] = safe_cast<System::Object^>(0);
			rowM["nombre_materia"] = "-- Todas las materias --";
			dt->Rows->InsertAt(rowM, 0);

			if (dt != nullptr && dt->Rows->Count > 0) {
				cbMateria->DataSource    = dt;
				cbMateria->DisplayMember = "nombre_materia";
				cbMateria->ValueMember   = "id_materia";
				cbMateria->Enabled = true;
			} else {
				cbMateria->BeginUpdate(); cbMateria->DataSource = nullptr; cbMateria->Items->Clear(); cbMateria->Items->Add(""); cbMateria->SelectedIndex = 0; cbMateria->EndUpdate(); cbMateria->Enabled = false;
			}
		}

		void old_cargarMaterias() {
			try {
				CModelo^ ctrl = gcnew CModelo();
				DataTable^ dt = ctrl->listarMaterias();
				DataRow^ filaTop = dt->NewRow();
				filaTop["id_materia"]     = -1;
				filaTop["nombre_materia"] = "-- Todas las materias --";
				dt->Rows->InsertAt(filaTop, 0);
				cbMateria->DataSource    = dt;
				cbMateria->DisplayMember = "nombre_materia";
				cbMateria->ValueMember   = "id_materia";
				cbMateria->SelectedIndex = 0;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error cargando materias:\n" + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		void colorearFilasPorEstado() {
			for (int i = 0; i < dgvInforme->Rows->Count; i++) {
				DataGridViewRow^ fila = dgvInforme->Rows[i];
				if (dgvInforme->Columns->Contains("estado")) {
					String^ estado = fila->Cells["estado"]->Value != nullptr
						? fila->Cells["estado"]->Value->ToString()->ToUpper() : "";
					if (estado == "APROBADO") {
						fila->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(220, 255, 220);
						fila->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(0, 100, 0);
					}
					else if (estado == "REPROBADO") {
						fila->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(255, 220, 220);
						fila->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(150, 0, 0);
					}
				}
			}
		}

		// =========================================
		// EVENTOS
		// =========================================

	
	private: System::Void cbFacultad_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbFacultad->SelectedValue != nullptr && cbFacultad->SelectedValue->GetType() == System::Int32::typeid) {
			cargarCarreras(Convert::ToInt32(cbFacultad->SelectedValue));
			// Refresca la tabla con todas las materias de la facultad
			cargarInformeGeneral();
		}
	}

	private: System::Void cbCarrera_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbCarrera->SelectedValue != nullptr && cbCarrera->SelectedValue->GetType() == System::Int32::typeid) {
			cargarMaterias(Convert::ToInt32(cbCarrera->SelectedValue));
			// Refresca la tabla con todas las materias de la carrera
			cargarInformeGeneral();
		}
	}


	private: System::Void cbMateria_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int id = obtenerIdMateriaSeleccionada();
		if (id < 0) cargarInformeGeneral();
		else        cargarInformePorMateria(id);
	}

		private: System::Void btnVerTodo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cbFacultad->Items->Count > 0) cbFacultad->SelectedIndex = 0;
		if (cbCarrera->Items->Count > 0) cbCarrera->SelectedIndex = 0;
		if (cbMateria->Items->Count > 0) cbMateria->SelectedIndex = 0;
		cargarInformeGeneral();
	}

	private: System::Void btnPromedios_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			CModelo^ ctrl = gcnew CModelo();
			int id = obtenerIdMateriaSeleccionada();
			dgvInforme->DataSource = (id < 0)
				? ctrl->promedioEstudiantes()
				: ctrl->promedioPorMateria(id);
			actualizarEstadisticas(id);
			lblEstado->Text = L"Vista de promedios cargada.";
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error promedios:\n" + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnInforme_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = obtenerIdMateriaSeleccionada();
		if (id < 0) cargarInformeGeneral();
		else        cargarInformePorMateria(id);
	}


	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dgvInforme->Rows->Count == 0) {
			MessageBox::Show("No hay datos para exportar.", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		SaveFileDialog^ dlg = gcnew SaveFileDialog();
		dlg->Filter   = "Excel CSV (*.csv)|*.csv";
		dlg->FileName = "informe_notas.csv";
		if (dlg->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;
		try {
			// UTF-8 con BOM para que Excel lo detecte correctamente
			System::Text::Encoding^ enc = gcnew System::Text::UTF8Encoding(true);
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(dlg->FileName, false, enc);
			System::Globalization::CultureInfo^ inv = System::Globalization::CultureInfo::InvariantCulture;

			// Encabezados separados por punto y coma (estandar Excel en espanol)
			System::Collections::Generic::List<String^>^ cols =
				gcnew System::Collections::Generic::List<String^>();
			for each (DataGridViewColumn^ col in dgvInforme->Columns)
				if (col->Visible) cols->Add(col->HeaderText);
			sw->WriteLine(String::Join(";", cols));

			// Filas
			for each (DataGridViewRow^ row in dgvInforme->Rows) {
				System::Collections::Generic::List<String^>^ vals =
					gcnew System::Collections::Generic::List<String^>();
				for each (DataGridViewCell^ cell in row->Cells) {
					if (!dgvInforme->Columns[cell->ColumnIndex]->Visible) continue;
					String^ header = dgvInforme->Columns[cell->ColumnIndex]->HeaderText;
					String^ val    = cell->Value != nullptr ? cell->Value->ToString() : "";
					// Columnas numericas: formatear a 2 decimales con coma (estilo espanol)
					bool esNumerico = (header == "Promedio" || header == "Nota Max." || header == "Nota Min.");
					if (esNumerico && val->Length > 0) {
						double d;
						if (double::TryParse(val, System::Globalization::NumberStyles::Any, inv, d))
							val = d.ToString("F2")->Replace(".", ",");
					}
					vals->Add(val);
				}
				sw->WriteLine(String::Join(";", vals));
			}
			sw->Close();
			MessageBox::Show("Archivo exportado correctamente.\nAbra el archivo con Excel.", "Exportar CSV",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al exportar:\n" + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void dgvInforme_DataBindingComplete(System::Object^ sender,
		System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e) {

		colorearFilasPorEstado();

		// Renombrar encabezados
		if (dgvInforme->Columns->Contains("carnet"))       dgvInforme->Columns["carnet"]->HeaderText       = L"Carnet";
		if (dgvInforme->Columns->Contains("estudiante"))   dgvInforme->Columns["estudiante"]->HeaderText   = L"Estudiante";
		if (dgvInforme->Columns->Contains("promedio"))     dgvInforme->Columns["promedio"]->HeaderText     = L"Promedio";
		if (dgvInforme->Columns->Contains("maxima"))       dgvInforme->Columns["maxima"]->HeaderText       = L"Nota Max.";
		if (dgvInforme->Columns->Contains("minima"))       dgvInforme->Columns["minima"]->HeaderText       = L"Nota Min.";
		if (dgvInforme->Columns->Contains("estado"))       dgvInforme->Columns["estado"]->HeaderText       = L"Estado";
		if (dgvInforme->Columns->Contains("nombre_materia")) dgvInforme->Columns["nombre_materia"]->HeaderText = L"Materia";
		if (dgvInforme->Columns->Contains("nombre_seccion")) dgvInforme->Columns["nombre_seccion"]->HeaderText = L"Seccion";

		// Ocultar columnas internas
		if (dgvInforme->Columns->Contains("id_estudiante")) dgvInforme->Columns["id_estudiante"]->Visible = false;
		if (dgvInforme->Columns->Contains("id_materia"))    dgvInforme->Columns["id_materia"]->Visible    = false;
		if (dgvInforme->Columns->Contains("id_seccion"))    dgvInforme->Columns["id_seccion"]->Visible    = false;

		// Formatear decimales a 2 cifras
		if (dgvInforme->Columns->Contains("promedio")) dgvInforme->Columns["promedio"]->DefaultCellStyle->Format = "F2";
		if (dgvInforme->Columns->Contains("maxima"))   dgvInforme->Columns["maxima"]->DefaultCellStyle->Format   = "F2";
		if (dgvInforme->Columns->Contains("minima"))   dgvInforme->Columns["minima"]->DefaultCellStyle->Format   = "F2";

		lblEstado->Text = "Total de registros: " + dgvInforme->Rows->Count.ToString();
	}
	};
}
