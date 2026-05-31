#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;


ref class Tema {
public:
    /// <summary>Aplica el tema actual al form y todos sus controles.</summary>
    static void Aplicar(Form^ f) {
        Color fondo, texto, input, boton;
        ObtenerColores(fondo, texto, input, boton);
        f->BackColor = fondo;
        f->ForeColor = texto;
        AplicarControles(f->Controls, fondo, texto, input, boton);
    }

private:
    static void ObtenerColores(Color% fondo, Color% texto, Color% input, Color% boton) {
        fondo = Color::FromArgb(233, 243, 255);
        texto = Color::Black; 
        input = Color::White;
        boton = Color::FromArgb(30, 144, 255);
    }

    static void AplicarControles(Control::ControlCollection^ controles,
        Color fondo, Color texto, Color input, Color boton)
    {
        System::Drawing::Font^ fuenteBase = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Regular);
        System::Drawing::Font^ fuenteBoton = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Regular);

        for each (Control^ c in controles) {
            
            c->Font = fuenteBase;

            Button^ btn = dynamic_cast<Button^>(c);
            if (btn != nullptr) {
                btn->Cursor = Cursors::Hand;
                btn->Font = fuenteBoton;
                
                if (btn->Tag != nullptr && btn->Tag->ToString() == L"activo") {
                    continue;
                }

                if (btn->Parent != nullptr && btn->Parent->Name == L"panelSidebar") {
                    // Botones del menu lateral
                    btn->FlatStyle = FlatStyle::Standard;
                    btn->BackColor = Color::FromArgb(240, 240, 240);
                    btn->ForeColor = Color::Black;
                } else {
                    // Botones principales
                    btn->FlatStyle = FlatStyle::Standard;
                    btn->BackColor = Color::FromArgb(220, 238, 255);
                    btn->ForeColor = Color::Black;
                }
                continue;
            }
            // --- TextBox ---
            TextBox^ txt = dynamic_cast<TextBox^>(c);
            if (txt != nullptr) {
                txt->BackColor = input;
                txt->ForeColor = texto;
                txt->BorderStyle = BorderStyle::Fixed3D;
                continue;
            }
            // --- ComboBox ---
            ComboBox^ cb = dynamic_cast<ComboBox^>(c);
            if (cb != nullptr) {
                cb->BackColor = input;
                cb->ForeColor = texto;
                cb->FlatStyle = FlatStyle::Flat;
                continue;
            }
            // --- DateTimePicker ---
            DateTimePicker^ dtp = dynamic_cast<DateTimePicker^>(c);
            if (dtp != nullptr) {
                dtp->CalendarMonthBackground = input;
                dtp->CalendarForeColor = texto;
                continue;
            }
            // --- Label ---
            Label^ lbl = dynamic_cast<Label^>(c);
            if (lbl != nullptr) {
                lbl->ForeColor = texto;
                continue;
            }
            // --- DataGridView ---
            DataGridView^ dgv = dynamic_cast<DataGridView^>(c);
            if (dgv != nullptr) {
                AplicarDGV(dgv, texto);
                continue;
            }
            // --- TabControl ---
            TabControl^ tab = dynamic_cast<TabControl^>(c);
            if (tab != nullptr) {
                tab->DrawMode = TabDrawMode::Normal;
                
                // Tab pages colors
                for each (TabPage^ tp in tab->TabPages) {
                    tp->BackColor = fondo;
                    tp->ForeColor = texto;
                }
                AplicarControles(tab->Controls, fondo, texto, input, boton);
                continue;
            }
            // --- GroupBox ---
            GroupBox^ grp = dynamic_cast<GroupBox^>(c);
            if (grp != nullptr) {
                grp->BackColor = fondo;
                grp->ForeColor = texto;
                // Make GroupBox look cleaner with bold font
                grp->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
                AplicarControles(grp->Controls, fondo, texto, input, boton);
                continue;
            }
            // --- Panel ---
            Panel^ pan = dynamic_cast<Panel^>(c);
            if (pan != nullptr) {
                if (pan->Name == L"panelSidebar") {
                    pan->BackColor = Color::FromArgb(240, 240, 240); 
                }
                else if (pan->Name == L"panelHeader") {
                    pan->BackColor = fondo; 
                    pan->ForeColor = texto;
                }
                else if (pan->Name == L"panelContent") {
                    pan->BackColor = fondo;
                }
                else if (pan->Name == L"panelCardDash" || pan->Name == L"panelCardForm") {
                    pan->BackColor = fondo;
                    pan->BorderStyle = BorderStyle::Fixed3D;
                }
                else {
                    pan->BackColor = fondo;
                }
                AplicarControles(pan->Controls, fondo, texto, input, boton);
                continue;
            }
            // --- Formularios anidados ---
            Form^ frm = dynamic_cast<Form^>(c);
            if (frm != nullptr) {
                frm->BackColor = fondo;
                frm->ForeColor = texto;
                AplicarControles(frm->Controls, fondo, texto, input, boton);
                continue;
            }
            // --- Otros contenedores ---
            if (c->Controls->Count > 0)
                AplicarControles(c->Controls, fondo, texto, input, boton);
        }
    }

    static void AplicarDGV(DataGridView^ dgv, Color texto) {
        dgv->BorderStyle = BorderStyle::Fixed3D;
        dgv->CellBorderStyle = DataGridViewCellBorderStyle::Single;
        dgv->EnableHeadersVisualStyles = true; 
        dgv->RowTemplate->Height = 25; 
        dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dgv->RowHeadersVisible = true; 
        dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; 
        dgv->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right); 
        
        dgv->BackgroundColor = Color::White;
        dgv->GridColor = Color::LightGray;
        
        dgv->DefaultCellStyle->BackColor = Color::White;
        dgv->DefaultCellStyle->ForeColor = texto;
        dgv->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 120, 215);
        dgv->DefaultCellStyle->SelectionForeColor = Color::White;

        dgv->AlternatingRowsDefaultCellStyle->BackColor = Color::White;
    }
};