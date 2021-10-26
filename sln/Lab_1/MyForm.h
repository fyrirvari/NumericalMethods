#pragma once
#include <vector>

namespace NumericalMethods {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;
	using namespace std;


	// difeq
	vector<double> test_f(double x, vector<double> v)
	{
		return vector<double>{
			(-1) * 5 / 2 * v[0] // du/dx
		};
	}
	auto get_test_sol(double C)
	{
		return [C](double x) {
			return C * exp(-5 * x / 2);
		};
	}

	vector<double> main1_f(double x, vector<double> v)
	{
		return vector<double>{
			log(x + 1)* pow(v[0], 2) / (pow(x, 2) + 1) + v[0] - pow(v[0], 3) * sin(10 * x)
		};
	}

	double a_;
	double b_;

	vector<double> main2_f(double x, vector<double> v)
	{
		return vector<double>{
			v[1],
			-a_ * pow(v[1], 2) - b_ * sin(v[0])
		};
	}
	


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			tab_frame->SelectTab(tab_frame->Controls->IndexOf(method_tab));
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ task_selection;
	private: System::Windows::Forms::Label^ task_selection_label;
	private: System::Windows::Forms::Label^ task_params_label;
	private: System::Windows::Forms::Label^ x0_label;
	private: System::Windows::Forms::Label^ u0_label;
	private: System::Windows::Forms::Label^ w0_label;
	private: System::Windows::Forms::TextBox^ x0_textbox;
	private: System::Windows::Forms::TextBox^ u0_textbox;
	private: System::Windows::Forms::TextBox^ w0_textbox;
	private: System::Windows::Forms::Label^ method_params_label;
	private: System::Windows::Forms::Label^ h0_label;
	private: System::Windows::Forms::Label^ is_locerr_required_label;
	private: System::Windows::Forms::Label^ locerr_accuracy_label;
	private: System::Windows::Forms::TextBox^ h0_textbox;
	private: System::Windows::Forms::CheckBox^ is_locerr_required_checkbox;
	private: System::Windows::Forms::TextBox^ locerr_accuracy_textbox;
	private: System::Windows::Forms::Label^ max_number_of_steps_label;
	private: System::Windows::Forms::Label^ right_border_label;
	private: System::Windows::Forms::Label^ right_border_accuracy_label;
	private: System::Windows::Forms::TextBox^ max_number_of_steps_textbox;
	private: System::Windows::Forms::TextBox^ right_border_textbox;
	private: System::Windows::Forms::TextBox^ right_border_accuracy_textbox;
	private: System::Windows::Forms::Button^ calculate_button;
	private: System::Windows::Forms::DataGridView^ data_frame;
	private: System::Windows::Forms::TabControl^ tab_frame;
	private: System::Windows::Forms::TabPage^ task_formulation_tab;
	private: System::Windows::Forms::TabPage^ method_tab;
	private: System::Windows::Forms::TabPage^ phase_portrait_tab;
	private: System::Windows::Forms::TabPage^ v_x_graph_tab;
	private: System::Windows::Forms::TabPage^ w_x_graph_tab;

	private: ZedGraph::ZedGraphControl^ phase_portrait_graphcontrol;
	private: ZedGraph::ZedGraphControl^ v_x_graph_graphcontrol;
	private: ZedGraph::ZedGraphControl^ w_x_graph_graphcontrol;
	private: System::Windows::Forms::TabPage^ reference_tab;
	private: System::Windows::Forms::PictureBox^ task_formulation_picturebox;
	private: System::Windows::Forms::Label^ a_coef_label;
	private: System::Windows::Forms::Label^ b_coef_label;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ x0_textbox0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ i_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ x_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vi_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v2i_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vi_v2i_diff_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wi_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ w2i_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wi_w2i_diff_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ locerr_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ hi_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C1_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C2_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ui_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ui_vi_abs_diff_table;
	private: System::Windows::Forms::Label^ max_abs_ui_vi_diff_label;
	private: System::Windows::Forms::Label^ h_min_label;
	private: System::Windows::Forms::Label^ h_max_label;
	private: System::Windows::Forms::Label^ C2_label;
	private: System::Windows::Forms::Label^ C1_label;
	private: System::Windows::Forms::Label^ max_abs_locerr_label;
	private: System::Windows::Forms::Label^ x_right_border_diff_label;
	private: System::Windows::Forms::Label^ number_of_steps_label;
	private: System::Windows::Forms::PictureBox^ method_description_picturebox;



	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->task_selection = (gcnew System::Windows::Forms::ComboBox());
			this->task_selection_label = (gcnew System::Windows::Forms::Label());
			this->task_params_label = (gcnew System::Windows::Forms::Label());
			this->x0_label = (gcnew System::Windows::Forms::Label());
			this->u0_label = (gcnew System::Windows::Forms::Label());
			this->w0_label = (gcnew System::Windows::Forms::Label());
			this->x0_textbox = (gcnew System::Windows::Forms::TextBox());
			this->u0_textbox = (gcnew System::Windows::Forms::TextBox());
			this->w0_textbox = (gcnew System::Windows::Forms::TextBox());
			this->method_params_label = (gcnew System::Windows::Forms::Label());
			this->h0_label = (gcnew System::Windows::Forms::Label());
			this->is_locerr_required_label = (gcnew System::Windows::Forms::Label());
			this->locerr_accuracy_label = (gcnew System::Windows::Forms::Label());
			this->h0_textbox = (gcnew System::Windows::Forms::TextBox());
			this->is_locerr_required_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->locerr_accuracy_textbox = (gcnew System::Windows::Forms::TextBox());
			this->max_number_of_steps_label = (gcnew System::Windows::Forms::Label());
			this->right_border_label = (gcnew System::Windows::Forms::Label());
			this->right_border_accuracy_label = (gcnew System::Windows::Forms::Label());
			this->max_number_of_steps_textbox = (gcnew System::Windows::Forms::TextBox());
			this->right_border_textbox = (gcnew System::Windows::Forms::TextBox());
			this->right_border_accuracy_textbox = (gcnew System::Windows::Forms::TextBox());
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->data_frame = (gcnew System::Windows::Forms::DataGridView());
			this->i_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->x_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vi_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v2i_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vi_v2i_diff_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wi_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->w2i_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wi_w2i_diff_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->locerr_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hi_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C1_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ui_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ui_vi_abs_diff_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tab_frame = (gcnew System::Windows::Forms::TabControl());
			this->task_formulation_tab = (gcnew System::Windows::Forms::TabPage());
			this->task_formulation_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->method_tab = (gcnew System::Windows::Forms::TabPage());
			this->reference_tab = (gcnew System::Windows::Forms::TabPage());
			this->max_abs_ui_vi_diff_label = (gcnew System::Windows::Forms::Label());
			this->h_min_label = (gcnew System::Windows::Forms::Label());
			this->h_max_label = (gcnew System::Windows::Forms::Label());
			this->C2_label = (gcnew System::Windows::Forms::Label());
			this->C1_label = (gcnew System::Windows::Forms::Label());
			this->max_abs_locerr_label = (gcnew System::Windows::Forms::Label());
			this->x_right_border_diff_label = (gcnew System::Windows::Forms::Label());
			this->number_of_steps_label = (gcnew System::Windows::Forms::Label());
			this->phase_portrait_tab = (gcnew System::Windows::Forms::TabPage());
			this->phase_portrait_graphcontrol = (gcnew ZedGraph::ZedGraphControl());
			this->v_x_graph_tab = (gcnew System::Windows::Forms::TabPage());
			this->v_x_graph_graphcontrol = (gcnew ZedGraph::ZedGraphControl());
			this->w_x_graph_tab = (gcnew System::Windows::Forms::TabPage());
			this->w_x_graph_graphcontrol = (gcnew ZedGraph::ZedGraphControl());
			this->a_coef_label = (gcnew System::Windows::Forms::Label());
			this->b_coef_label = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->x0_textbox0 = (gcnew System::Windows::Forms::TextBox());
			this->method_description_picturebox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_frame))->BeginInit();
			this->tab_frame->SuspendLayout();
			this->task_formulation_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->task_formulation_picturebox))->BeginInit();
			this->method_tab->SuspendLayout();
			this->reference_tab->SuspendLayout();
			this->phase_portrait_tab->SuspendLayout();
			this->v_x_graph_tab->SuspendLayout();
			this->w_x_graph_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->method_description_picturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// task_selection
			// 
			this->task_selection->FormattingEnabled = true;
			this->task_selection->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Тестовая задача (5)", L"Основная задача 1", L"Основная задача 2" });
			this->task_selection->Location = System::Drawing::Point(29, 25);
			this->task_selection->Name = L"task_selection";
			this->task_selection->Size = System::Drawing::Size(196, 21);
			this->task_selection->TabIndex = 0;
			this->task_selection->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::task_selection_SelectedIndexChanged);
			// 
			// task_selection_label
			// 
			this->task_selection_label->AutoSize = true;
			this->task_selection_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->task_selection_label->Location = System::Drawing::Point(26, 9);
			this->task_selection_label->Name = L"task_selection_label";
			this->task_selection_label->Size = System::Drawing::Size(90, 13);
			this->task_selection_label->TabIndex = 1;
			this->task_selection_label->Text = L"Выбор задачи";
			// 
			// task_params_label
			// 
			this->task_params_label->AutoSize = true;
			this->task_params_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->task_params_label->Location = System::Drawing::Point(279, 9);
			this->task_params_label->Name = L"task_params_label";
			this->task_params_label->Size = System::Drawing::Size(155, 13);
			this->task_params_label->TabIndex = 2;
			this->task_params_label->Text = L"Параметры задачи Коши";
			// 
			// x0_label
			// 
			this->x0_label->AutoSize = true;
			this->x0_label->Location = System::Drawing::Point(279, 25);
			this->x0_label->MaximumSize = System::Drawing::Size(25, 15);
			this->x0_label->MinimumSize = System::Drawing::Size(25, 15);
			this->x0_label->Name = L"x0_label";
			this->x0_label->Size = System::Drawing::Size(25, 15);
			this->x0_label->TabIndex = 3;
			this->x0_label->Text = L"x0";
			// 
			// u0_label
			// 
			this->u0_label->AutoSize = true;
			this->u0_label->Location = System::Drawing::Point(279, 64);
			this->u0_label->MaximumSize = System::Drawing::Size(25, 15);
			this->u0_label->MinimumSize = System::Drawing::Size(25, 15);
			this->u0_label->Name = L"u0_label";
			this->u0_label->Size = System::Drawing::Size(25, 15);
			this->u0_label->TabIndex = 4;
			this->u0_label->Text = L"u0";
			// 
			// w0_label
			// 
			this->w0_label->AutoSize = true;
			this->w0_label->Location = System::Drawing::Point(279, 105);
			this->w0_label->MaximumSize = System::Drawing::Size(25, 15);
			this->w0_label->MinimumSize = System::Drawing::Size(25, 15);
			this->w0_label->Name = L"w0_label";
			this->w0_label->Size = System::Drawing::Size(25, 15);
			this->w0_label->TabIndex = 5;
			this->w0_label->Text = L"u\'0";
			// 
			// x0_textbox
			// 
			this->x0_textbox->Location = System::Drawing::Point(334, 26);
			this->x0_textbox->Name = L"x0_textbox";
			this->x0_textbox->Size = System::Drawing::Size(100, 20);
			this->x0_textbox->TabIndex = 6;
			this->x0_textbox->Text = L"0";
			// 
			// u0_textbox
			// 
			this->u0_textbox->Location = System::Drawing::Point(334, 64);
			this->u0_textbox->Name = L"u0_textbox";
			this->u0_textbox->Size = System::Drawing::Size(100, 20);
			this->u0_textbox->TabIndex = 7;
			this->u0_textbox->Text = L"1";
			// 
			// w0_textbox
			// 
			this->w0_textbox->Location = System::Drawing::Point(334, 102);
			this->w0_textbox->Name = L"w0_textbox";
			this->w0_textbox->Size = System::Drawing::Size(100, 20);
			this->w0_textbox->TabIndex = 8;
			this->w0_textbox->Text = L"2";
			// 
			// method_params_label
			// 
			this->method_params_label->AutoSize = true;
			this->method_params_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->method_params_label->Location = System::Drawing::Point(489, 9);
			this->method_params_label->Name = L"method_params_label";
			this->method_params_label->Size = System::Drawing::Size(122, 13);
			this->method_params_label->TabIndex = 9;
			this->method_params_label->Text = L"Параметры метода";
			// 
			// h0_label
			// 
			this->h0_label->AutoSize = true;
			this->h0_label->Location = System::Drawing::Point(489, 25);
			this->h0_label->Name = L"h0_label";
			this->h0_label->Size = System::Drawing::Size(86, 13);
			this->h0_label->TabIndex = 10;
			this->h0_label->Text = L"Начальный шаг";
			// 
			// is_locerr_required_label
			// 
			this->is_locerr_required_label->AutoSize = true;
			this->is_locerr_required_label->Location = System::Drawing::Point(489, 64);
			this->is_locerr_required_label->MaximumSize = System::Drawing::Size(150, 0);
			this->is_locerr_required_label->Name = L"is_locerr_required_label";
			this->is_locerr_required_label->Size = System::Drawing::Size(130, 26);
			this->is_locerr_required_label->TabIndex = 11;
			this->is_locerr_required_label->Text = L"Учитывать контроль локальной погрешности";
			// 
			// locerr_accuracy_label
			// 
			this->locerr_accuracy_label->AutoSize = true;
			this->locerr_accuracy_label->Location = System::Drawing::Point(489, 107);
			this->locerr_accuracy_label->MaximumSize = System::Drawing::Size(150, 0);
			this->locerr_accuracy_label->Name = L"locerr_accuracy_label";
			this->locerr_accuracy_label->Size = System::Drawing::Size(114, 26);
			this->locerr_accuracy_label->TabIndex = 12;
			this->locerr_accuracy_label->Text = L"Точность локальной погрешности";
			this->locerr_accuracy_label->Visible = false;
			// 
			// h0_textbox
			// 
			this->h0_textbox->Location = System::Drawing::Point(650, 26);
			this->h0_textbox->Name = L"h0_textbox";
			this->h0_textbox->Size = System::Drawing::Size(100, 20);
			this->h0_textbox->TabIndex = 13;
			this->h0_textbox->Text = L"0,01";
			// 
			// is_locerr_required_checkbox
			// 
			this->is_locerr_required_checkbox->AutoSize = true;
			this->is_locerr_required_checkbox->Location = System::Drawing::Point(650, 70);
			this->is_locerr_required_checkbox->Name = L"is_locerr_required_checkbox";
			this->is_locerr_required_checkbox->Size = System::Drawing::Size(15, 14);
			this->is_locerr_required_checkbox->TabIndex = 14;
			this->is_locerr_required_checkbox->UseVisualStyleBackColor = true;
			this->is_locerr_required_checkbox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::is_locerr_required_checkbox_CheckedChanged);
			// 
			// locerr_accuracy_textbox
			// 
			this->locerr_accuracy_textbox->Location = System::Drawing::Point(650, 107);
			this->locerr_accuracy_textbox->Name = L"locerr_accuracy_textbox";
			this->locerr_accuracy_textbox->Size = System::Drawing::Size(100, 20);
			this->locerr_accuracy_textbox->TabIndex = 15;
			this->locerr_accuracy_textbox->Text = L"0,0000001";
			this->locerr_accuracy_textbox->Visible = false;
			// 
			// max_number_of_steps_label
			// 
			this->max_number_of_steps_label->AutoSize = true;
			this->max_number_of_steps_label->Location = System::Drawing::Point(816, 25);
			this->max_number_of_steps_label->MaximumSize = System::Drawing::Size(150, 0);
			this->max_number_of_steps_label->Name = L"max_number_of_steps_label";
			this->max_number_of_steps_label->Size = System::Drawing::Size(150, 13);
			this->max_number_of_steps_label->TabIndex = 16;
			this->max_number_of_steps_label->Text = L"Максимальное число шагов";
			// 
			// right_border_label
			// 
			this->right_border_label->AutoSize = true;
			this->right_border_label->Location = System::Drawing::Point(816, 71);
			this->right_border_label->Name = L"right_border_label";
			this->right_border_label->Size = System::Drawing::Size(89, 13);
			this->right_border_label->TabIndex = 17;
			this->right_border_label->Text = L"Правая граница";
			// 
			// right_border_accuracy_label
			// 
			this->right_border_accuracy_label->AutoSize = true;
			this->right_border_accuracy_label->Location = System::Drawing::Point(817, 110);
			this->right_border_accuracy_label->MaximumSize = System::Drawing::Size(150, 0);
			this->right_border_accuracy_label->Name = L"right_border_accuracy_label";
			this->right_border_accuracy_label->Size = System::Drawing::Size(149, 26);
			this->right_border_accuracy_label->TabIndex = 18;
			this->right_border_accuracy_label->Text = L"Точность выхода на правую границу";
			// 
			// max_number_of_steps_textbox
			// 
			this->max_number_of_steps_textbox->Location = System::Drawing::Point(999, 26);
			this->max_number_of_steps_textbox->Name = L"max_number_of_steps_textbox";
			this->max_number_of_steps_textbox->Size = System::Drawing::Size(100, 20);
			this->max_number_of_steps_textbox->TabIndex = 19;
			this->max_number_of_steps_textbox->Text = L"1000";
			// 
			// right_border_textbox
			// 
			this->right_border_textbox->Location = System::Drawing::Point(999, 71);
			this->right_border_textbox->Name = L"right_border_textbox";
			this->right_border_textbox->Size = System::Drawing::Size(100, 20);
			this->right_border_textbox->TabIndex = 20;
			this->right_border_textbox->Text = L"15";
			// 
			// right_border_accuracy_textbox
			// 
			this->right_border_accuracy_textbox->Location = System::Drawing::Point(999, 110);
			this->right_border_accuracy_textbox->Name = L"right_border_accuracy_textbox";
			this->right_border_accuracy_textbox->Size = System::Drawing::Size(100, 20);
			this->right_border_accuracy_textbox->TabIndex = 21;
			this->right_border_accuracy_textbox->Text = L"0,0000001";
			// 
			// calculate_button
			// 
			this->calculate_button->Location = System::Drawing::Point(29, 105);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(196, 36);
			this->calculate_button->TabIndex = 22;
			this->calculate_button->Text = L"Вычислить";
			this->calculate_button->UseVisualStyleBackColor = true;
			this->calculate_button->Visible = false;
			this->calculate_button->Click += gcnew System::EventHandler(this, &MyForm::calculate_button_Click);
			// 
			// data_frame
			// 
			this->data_frame->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_frame->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(14) {
				this->i_table,
					this->x_table, this->vi_table, this->v2i_table, this->vi_v2i_diff_table, this->wi_table, this->w2i_table, this->wi_w2i_diff_table,
					this->locerr_table, this->hi_table, this->C1_table, this->C2_table, this->ui_table, this->ui_vi_abs_diff_table
			});
			this->data_frame->Location = System::Drawing::Point(29, 147);
			this->data_frame->Name = L"data_frame";
			this->data_frame->Size = System::Drawing::Size(458, 522);
			this->data_frame->TabIndex = 23;
			this->data_frame->Visible = false;
			// 
			// i_table
			// 
			this->i_table->HeaderText = L"i";
			this->i_table->Name = L"i_table";
			this->i_table->Width = 50;
			// 
			// x_table
			// 
			this->x_table->HeaderText = L"x";
			this->x_table->Name = L"x_table";
			// 
			// vi_table
			// 
			this->vi_table->HeaderText = L"vi";
			this->vi_table->Name = L"vi_table";
			// 
			// v2i_table
			// 
			this->v2i_table->HeaderText = L"v2i";
			this->v2i_table->Name = L"v2i_table";
			this->v2i_table->Visible = false;
			// 
			// vi_v2i_diff_table
			// 
			this->vi_v2i_diff_table->HeaderText = L"vi - v2i";
			this->vi_v2i_diff_table->Name = L"vi_v2i_diff_table";
			this->vi_v2i_diff_table->Visible = false;
			// 
			// wi_table
			// 
			this->wi_table->HeaderText = L"wi";
			this->wi_table->Name = L"wi_table";
			// 
			// w2i_table
			// 
			this->w2i_table->HeaderText = L"w2i";
			this->w2i_table->Name = L"w2i_table";
			this->w2i_table->Visible = false;
			// 
			// wi_w2i_diff_table
			// 
			this->wi_w2i_diff_table->HeaderText = L"wi - w2i";
			this->wi_w2i_diff_table->Name = L"wi_w2i_diff_table";
			this->wi_w2i_diff_table->Visible = false;
			// 
			// locerr_table
			// 
			this->locerr_table->HeaderText = L"ОЛП";
			this->locerr_table->Name = L"locerr_table";
			this->locerr_table->Visible = false;
			// 
			// hi_table
			// 
			this->hi_table->HeaderText = L"hi";
			this->hi_table->Name = L"hi_table";
			// 
			// C1_table
			// 
			this->C1_table->HeaderText = L"C1";
			this->C1_table->Name = L"C1_table";
			this->C1_table->Width = 50;
			// 
			// C2_table
			// 
			this->C2_table->HeaderText = L"C2";
			this->C2_table->Name = L"C2_table";
			this->C2_table->Width = 50;
			// 
			// ui_table
			// 
			this->ui_table->HeaderText = L"ui";
			this->ui_table->Name = L"ui_table";
			// 
			// ui_vi_abs_diff_table
			// 
			this->ui_vi_abs_diff_table->HeaderText = L"|ui - vi|";
			this->ui_vi_abs_diff_table->Name = L"ui_vi_abs_diff_table";
			// 
			// tab_frame
			// 
			this->tab_frame->Controls->Add(this->task_formulation_tab);
			this->tab_frame->Controls->Add(this->method_tab);
			this->tab_frame->Location = System::Drawing::Point(494, 147);
			this->tab_frame->Name = L"tab_frame";
			this->tab_frame->SelectedIndex = 0;
			this->tab_frame->Size = System::Drawing::Size(659, 522);
			this->tab_frame->TabIndex = 24;
			// 
			// task_formulation_tab
			// 
			this->task_formulation_tab->Controls->Add(this->task_formulation_picturebox);
			this->task_formulation_tab->Location = System::Drawing::Point(4, 22);
			this->task_formulation_tab->Name = L"task_formulation_tab";
			this->task_formulation_tab->Padding = System::Windows::Forms::Padding(3);
			this->task_formulation_tab->Size = System::Drawing::Size(651, 496);
			this->task_formulation_tab->TabIndex = 0;
			this->task_formulation_tab->Text = L"Постановка задачи";
			this->task_formulation_tab->UseVisualStyleBackColor = true;
			// 
			// task_formulation_picturebox
			// 
			this->task_formulation_picturebox->Location = System::Drawing::Point(0, 0);
			this->task_formulation_picturebox->Name = L"task_formulation_picturebox";
			this->task_formulation_picturebox->Size = System::Drawing::Size(651, 496);
			this->task_formulation_picturebox->TabIndex = 25;
			this->task_formulation_picturebox->TabStop = false;
			// 
			// method_tab
			// 
			this->method_tab->Controls->Add(this->method_description_picturebox);
			this->method_tab->Location = System::Drawing::Point(4, 22);
			this->method_tab->Name = L"method_tab";
			this->method_tab->Padding = System::Windows::Forms::Padding(3);
			this->method_tab->Size = System::Drawing::Size(651, 496);
			this->method_tab->TabIndex = 1;
			this->method_tab->Text = L"Численный метод";
			this->method_tab->UseVisualStyleBackColor = true;
			// 
			// reference_tab
			// 
			this->reference_tab->Controls->Add(this->max_abs_ui_vi_diff_label);
			this->reference_tab->Controls->Add(this->h_min_label);
			this->reference_tab->Controls->Add(this->h_max_label);
			this->reference_tab->Controls->Add(this->C2_label);
			this->reference_tab->Controls->Add(this->C1_label);
			this->reference_tab->Controls->Add(this->max_abs_locerr_label);
			this->reference_tab->Controls->Add(this->x_right_border_diff_label);
			this->reference_tab->Controls->Add(this->number_of_steps_label);
			this->reference_tab->Location = System::Drawing::Point(4, 22);
			this->reference_tab->Name = L"reference_tab";
			this->reference_tab->Size = System::Drawing::Size(651, 496);
			this->reference_tab->TabIndex = 5;
			this->reference_tab->Text = L"Справка";
			this->reference_tab->UseVisualStyleBackColor = true;
			// 
			// max_abs_ui_vi_diff_label
			// 
			this->max_abs_ui_vi_diff_label->AutoSize = true;
			this->max_abs_ui_vi_diff_label->Location = System::Drawing::Point(48, 306);
			this->max_abs_ui_vi_diff_label->Name = L"max_abs_ui_vi_diff_label";
			this->max_abs_ui_vi_diff_label->Size = System::Drawing::Size(41, 13);
			this->max_abs_ui_vi_diff_label->TabIndex = 7;
			this->max_abs_ui_vi_diff_label->Text = L"max_abs_ui_vi_diff_label";
			// 
			// h_min_label
			// 
			this->h_min_label->AutoSize = true;
			this->h_min_label->Location = System::Drawing::Point(48, 241);
			this->h_min_label->Name = L"h_min_label";
			this->h_min_label->Size = System::Drawing::Size(41, 13);
			this->h_min_label->TabIndex = 6;
			this->h_min_label->Text = L"h_min_label";
			// 
			// h_max_label
			// 
			this->h_max_label->AutoSize = true;
			this->h_max_label->Location = System::Drawing::Point(48, 187);
			this->h_max_label->Name = L"h_max_label";
			this->h_max_label->Size = System::Drawing::Size(41, 13);
			this->h_max_label->TabIndex = 5;
			this->h_max_label->Text = L"h_max_label";
			// 
			// C2_label
			// 
			this->C2_label->AutoSize = true;
			this->C2_label->Location = System::Drawing::Point(299, 134);
			this->C2_label->Name = L"C2_label";
			this->C2_label->Size = System::Drawing::Size(41, 13);
			this->C2_label->TabIndex = 4;
			this->C2_label->Text = L"C2_label";
			// 
			// C1_label
			// 
			this->C1_label->AutoSize = true;
			this->C1_label->Location = System::Drawing::Point(48, 134);
			this->C1_label->Name = L"C1_label";
			this->C1_label->Size = System::Drawing::Size(41, 13);
			this->C1_label->TabIndex = 3;
			this->C1_label->Text = L"C1_label";
			// 
			// max_abs_locerr_label
			// 
			this->max_abs_locerr_label->AutoSize = true;
			this->max_abs_locerr_label->Location = System::Drawing::Point(48, 82);
			this->max_abs_locerr_label->Name = L"max_abs_locerr_label";
			this->max_abs_locerr_label->Size = System::Drawing::Size(41, 13);
			this->max_abs_locerr_label->TabIndex = 2;
			this->max_abs_locerr_label->Text = L"max_abs_locerr_label";
			// 
			// x_right_border_diff_label
			// 
			this->x_right_border_diff_label->AutoSize = true;
			this->x_right_border_diff_label->Location = System::Drawing::Point(299, 37);
			this->x_right_border_diff_label->Name = L"x_right_border_diff_label";
			this->x_right_border_diff_label->Size = System::Drawing::Size(41, 13);
			this->x_right_border_diff_label->TabIndex = 1;
			this->x_right_border_diff_label->Text = L"x_right_border_diff_label";
			// 
			// number_of_steps_label
			// 
			this->number_of_steps_label->AutoSize = true;
			this->number_of_steps_label->Location = System::Drawing::Point(48, 37);
			this->number_of_steps_label->Name = L"number_of_steps_label";
			this->number_of_steps_label->Size = System::Drawing::Size(41, 13);
			this->number_of_steps_label->TabIndex = 0;
			this->number_of_steps_label->Text = L"number_of_steps_label";
			// 
			// phase_portrait_tab
			// 
			this->phase_portrait_tab->Controls->Add(this->phase_portrait_graphcontrol);
			this->phase_portrait_tab->Location = System::Drawing::Point(4, 22);
			this->phase_portrait_tab->Name = L"phase_portrait_tab";
			this->phase_portrait_tab->Size = System::Drawing::Size(651, 496);
			this->phase_portrait_tab->TabIndex = 2;
			this->phase_portrait_tab->Text = L"Фазовый портрет";
			this->phase_portrait_tab->UseVisualStyleBackColor = true;
			// 
			// phase_portrait_graphcontrol
			// 
			this->phase_portrait_graphcontrol->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->phase_portrait_graphcontrol->Location = System::Drawing::Point(-4, 0);
			this->phase_portrait_graphcontrol->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->phase_portrait_graphcontrol->Name = L"phase_portrait_graphcontrol";
			this->phase_portrait_graphcontrol->ScrollGrace = 0;
			this->phase_portrait_graphcontrol->ScrollMaxX = 0;
			this->phase_portrait_graphcontrol->ScrollMaxY = 0;
			this->phase_portrait_graphcontrol->ScrollMaxY2 = 0;
			this->phase_portrait_graphcontrol->ScrollMinX = 0;
			this->phase_portrait_graphcontrol->ScrollMinY = 0;
			this->phase_portrait_graphcontrol->ScrollMinY2 = 0;
			this->phase_portrait_graphcontrol->Size = System::Drawing::Size(655, 496);
			this->phase_portrait_graphcontrol->TabIndex = 0;
			// 
			// v_x_graph_tab
			// 
			this->v_x_graph_tab->Controls->Add(this->v_x_graph_graphcontrol);
			this->v_x_graph_tab->Location = System::Drawing::Point(4, 22);
			this->v_x_graph_tab->Name = L"v_x_graph_tab";
			this->v_x_graph_tab->Size = System::Drawing::Size(651, 496);
			this->v_x_graph_tab->TabIndex = 3;
			this->v_x_graph_tab->Text = L"График v(t)";
			this->v_x_graph_tab->UseVisualStyleBackColor = true;
			// 
			// v_x_graph_graphcontrol
			// 
			this->v_x_graph_graphcontrol->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->v_x_graph_graphcontrol->Location = System::Drawing::Point(-4, 0);
			this->v_x_graph_graphcontrol->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->v_x_graph_graphcontrol->Name = L"v_x_graph_graphcontrol";
			this->v_x_graph_graphcontrol->ScrollGrace = 0;
			this->v_x_graph_graphcontrol->ScrollMaxX = 0;
			this->v_x_graph_graphcontrol->ScrollMaxY = 0;
			this->v_x_graph_graphcontrol->ScrollMaxY2 = 0;
			this->v_x_graph_graphcontrol->ScrollMinX = 0;
			this->v_x_graph_graphcontrol->ScrollMinY = 0;
			this->v_x_graph_graphcontrol->ScrollMinY2 = 0;
			this->v_x_graph_graphcontrol->Size = System::Drawing::Size(655, 496);
			this->v_x_graph_graphcontrol->TabIndex = 0;
			// 
			// w_x_graph_tab
			// 
			this->w_x_graph_tab->Controls->Add(this->w_x_graph_graphcontrol);
			this->w_x_graph_tab->Location = System::Drawing::Point(4, 22);
			this->w_x_graph_tab->Name = L"w_x_graph_tab";
			this->w_x_graph_tab->Size = System::Drawing::Size(651, 496);
			this->w_x_graph_tab->TabIndex = 4;
			this->w_x_graph_tab->Text = L"График w(t)";
			this->w_x_graph_tab->UseVisualStyleBackColor = true;
			// 
			// w_x_graph_graphcontrol
			// 
			this->w_x_graph_graphcontrol->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->w_x_graph_graphcontrol->Location = System::Drawing::Point(-4, 0);
			this->w_x_graph_graphcontrol->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->w_x_graph_graphcontrol->Name = L"w_x_graph_graphcontrol";
			this->w_x_graph_graphcontrol->ScrollGrace = 0;
			this->w_x_graph_graphcontrol->ScrollMaxX = 0;
			this->w_x_graph_graphcontrol->ScrollMaxY = 0;
			this->w_x_graph_graphcontrol->ScrollMaxY2 = 0;
			this->w_x_graph_graphcontrol->ScrollMinX = 0;
			this->w_x_graph_graphcontrol->ScrollMinY = 0;
			this->w_x_graph_graphcontrol->ScrollMinY2 = 0;
			this->w_x_graph_graphcontrol->Size = System::Drawing::Size(655, 496);
			this->w_x_graph_graphcontrol->TabIndex = 0;
			// 
			// a_coef_label
			// 
			this->a_coef_label->AutoSize = true;
			this->a_coef_label->Location = System::Drawing::Point(29, 53);
			this->a_coef_label->Name = L"a_coef_label";
			this->a_coef_label->Size = System::Drawing::Size(13, 13);
			this->a_coef_label->TabIndex = 25;
			this->a_coef_label->Text = L"a";
			this->a_coef_label->Visible = false;
			// 
			// b_coef_label
			// 
			this->b_coef_label->AutoSize = true;
			this->b_coef_label->Location = System::Drawing::Point(29, 82);
			this->b_coef_label->Name = L"b_coef_label";
			this->b_coef_label->Size = System::Drawing::Size(13, 13);
			this->b_coef_label->TabIndex = 26;
			this->b_coef_label->Text = L"b";
			this->b_coef_label->Visible = false;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(125, 53);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 27;
			this->textBox9->Text = L"1";
			this->textBox9->Visible = false;
			// 
			// x0_textbox0
			// 
			this->x0_textbox0->Location = System::Drawing::Point(125, 79);
			this->x0_textbox0->Name = L"x0_textbox0";
			this->x0_textbox0->Size = System::Drawing::Size(100, 20);
			this->x0_textbox0->TabIndex = 28;
			this->x0_textbox0->Text = L"1";
			this->x0_textbox0->Visible = false;
			// 
			// method_description_picturebox
			// 
			this->method_description_picturebox->Image = Image::FromFile(".\\images\\RK4.jpg");
			this->method_description_picturebox->Location = System::Drawing::Point(0, 0);
			this->method_description_picturebox->Name = L"method_description_picturebox";
			this->method_description_picturebox->Size = System::Drawing::Size(651, 496);
			this->method_description_picturebox->TabIndex = 0;
			this->method_description_picturebox->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 681);
			this->Controls->Add(this->x0_textbox0);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->b_coef_label);
			this->Controls->Add(this->a_coef_label);
			this->Controls->Add(this->tab_frame);
			this->Controls->Add(this->data_frame);
			this->Controls->Add(this->calculate_button);
			this->Controls->Add(this->right_border_accuracy_textbox);
			this->Controls->Add(this->right_border_textbox);
			this->Controls->Add(this->max_number_of_steps_textbox);
			this->Controls->Add(this->right_border_accuracy_label);
			this->Controls->Add(this->right_border_label);
			this->Controls->Add(this->max_number_of_steps_label);
			this->Controls->Add(this->locerr_accuracy_textbox);
			this->Controls->Add(this->is_locerr_required_checkbox);
			this->Controls->Add(this->h0_textbox);
			this->Controls->Add(this->locerr_accuracy_label);
			this->Controls->Add(this->is_locerr_required_label);
			this->Controls->Add(this->h0_label);
			this->Controls->Add(this->method_params_label);
			this->Controls->Add(this->w0_textbox);
			this->Controls->Add(this->u0_textbox);
			this->Controls->Add(this->x0_textbox);
			this->Controls->Add(this->w0_label);
			this->Controls->Add(this->u0_label);
			this->Controls->Add(this->x0_label);
			this->Controls->Add(this->task_params_label);
			this->Controls->Add(this->task_selection_label);
			this->Controls->Add(this->task_selection);
			this->Name = L"MyForm";
			this->Text = L"Лабораторная работа №1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_frame))->EndInit();
			this->tab_frame->ResumeLayout(false);
			this->task_formulation_tab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->task_formulation_picturebox))->EndInit();
			this->method_tab->ResumeLayout(false);
			this->reference_tab->ResumeLayout(false);
			this->reference_tab->PerformLayout();
			this->phase_portrait_tab->ResumeLayout(false);
			this->v_x_graph_tab->ResumeLayout(false);
			this->w_x_graph_tab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->method_description_picturebox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		vector<double> RK4_step(vector<double> (*f)(double, vector<double>), double x, vector<double> v, double h)
		{
			vector<double> pt_from_ki(v.size());
			auto k1 = f(x, v);
			for (int i = 0; i < v.size(); i++)
				pt_from_ki.push_back(v[i] + h * k1[i] / 2);

			auto k2 = f(x + h / 2, pt_from_ki);
			for (int i = 0; i < v.size(); i++)
				pt_from_ki.push_back(v[i] + h * k2[i] / 2);

			auto k3 = f(x + h / 2, pt_from_ki);
			for (int i = 0; i < v.size(); i++)
				pt_from_ki.push_back(v[i] + h * k3[i]);

			auto k4 = f(x + h, pt_from_ki);

			vector<double> next_v;
			for (int i = 0; i < v.size(); i++)
				next_v.push_back(v[i] + h * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6);

			return next_v;
		}

		double get_max_diff_by_abs(vector<double> v_, vector<double> v)
		{
			double max_diff_by_abs = 0;
			for (int i = 0; i < v_.size(); i++)
				if (max_diff_by_abs < abs(v_[i] - v[i]))
					max_diff_by_abs = v_[i] - v[i];
			return max_diff_by_abs;
		}

		void main2()
		{
			locerr_table->Visible = is_locerr_required_checkbox->Checked;
			v2i_table->Visible = is_locerr_required_checkbox->Checked;
			vi_v2i_diff_table->Visible = is_locerr_required_checkbox->Checked;
			wi_table->Visible = true;
			w2i_table->Visible = is_locerr_required_checkbox->Checked;
			wi_w2i_diff_table->Visible = is_locerr_required_checkbox->Checked;
			ui_table->Visible = false;
			ui_vi_abs_diff_table->Visible = false;
			C1_table->Visible = is_locerr_required_checkbox->Checked;
			C2_table->Visible = is_locerr_required_checkbox->Checked;

			tab_frame->Controls->Add(reference_tab);
			tab_frame->Controls->Add(phase_portrait_tab);
			tab_frame->Controls->Add(v_x_graph_tab);
			tab_frame->Controls->Add(w_x_graph_tab);

			GraphPane^ phase_portrait_graph = phase_portrait_graphcontrol->GraphPane;
			GraphPane^ v_x_graph = v_x_graph_graphcontrol->GraphPane;
			GraphPane^ w_x_graph = w_x_graph_graphcontrol->GraphPane;
			phase_portrait_graph->CurveList->Clear();
			v_x_graph->CurveList->Clear();
			w_x_graph->CurveList->Clear();
			// Создадим список точек
			PointPairList^ phase_portrait_pts = gcnew ZedGraph::PointPairList();
			PointPairList^ v_x_pts = gcnew ZedGraph::PointPairList();
			PointPairList^ w_x_pts = gcnew ZedGraph::PointPairList();
			phase_portrait_graph->Title->Text = "График зависимости скороcти от смещения";
			v_x_graph->Title->Text = "График зависимости смещения от времени";
			w_x_graph->Title->Text = "График зависимости скорости от времени";

			phase_portrait_graph->XAxis->Title->Text = "v - смещение";
			phase_portrait_graph->YAxis->Title->Text = "w - скорость";

			v_x_graph->XAxis->Title->Text = "х - время";
			v_x_graph->YAxis->Title->Text = "v - смещение";

			w_x_graph->XAxis->Title->Text = "х - время";
			w_x_graph->YAxis->Title->Text = "w - скорость";

			// очистим таблицу
			data_frame->Rows->Clear();
			bool is_locerr_required = is_locerr_required_checkbox->Checked;
			double epsilon;
			double x = Convert::ToDouble(x0_textbox->Text);
			double u = Convert::ToDouble(u0_textbox->Text);
			double u_ = Convert::ToDouble(w0_textbox->Text);
			a_ = Convert::ToDouble(textBox9->Text);
			b_ = Convert::ToDouble(x0_textbox0->Text);
			double h = Convert::ToDouble(h0_textbox->Text);
			int n = Convert::ToInt32(max_number_of_steps_textbox->Text);
			double x_max = Convert::ToDouble(right_border_textbox->Text);
			double b = Convert::ToDouble(right_border_accuracy_textbox->Text);
			int i = 1;
			int p = 4;
			int C1 = 0;
			int C2 = 0;
			double abs_locerr_max = 0;
			double h_max = h, h_min = h;
			double x_h_max, x_h_min;
			double v_min = u;
			
			data_frame->Rows->Add();
			data_frame->Rows[0]->Cells["i_table"]->Value = 0;
			data_frame->Rows[0]->Cells["x_table"]->Value = x;
			data_frame->Rows[0]->Cells["vi_table"]->Value = u;
			data_frame->Rows[0]->Cells["wi_table"]->Value = u_;
			data_frame->Rows[0]->Cells["hi_table"]->Value = h;
			if (is_locerr_required)
			{
				data_frame->Rows[0]->Cells["locerr_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["v2i_table"]->Value = u;
				data_frame->Rows[0]->Cells["vi_v2i_diff_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["w2i_table"]->Value = u_;
				data_frame->Rows[0]->Cells["wi_w2i_diff_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["C1_table"]->Value = 0;
				data_frame->Rows[0]->Cells["C2_table"]->Value = 0;
				epsilon = Convert::ToDouble(locerr_accuracy_textbox->Text);
			}

			vector<double> v = { u, u_ };

			while (i - 1 < n && x_max - b > x)
			{
				vector<double> next_v = RK4_step(main2_f, x, v, h);
				vector<double> next_v2;
				double S, last_h = h;
				if (is_locerr_required)
				{
					next_v2 = RK4_step(main2_f, x + h / 2, RK4_step(main2_f, x, v, h / 2), h / 2);
					S = get_max_diff_by_abs(next_v2, next_v) / (pow(2, p) - 1);
					if (abs(S) > epsilon)
					{
						h /= 2;
						C1++;
						continue;
					}
					else
					{
						if (epsilon / pow(2, p + 1) > abs(S))
						{
							h *= 2;
							C2++;
						}
					}
				}
				x += last_h;
				v = next_v; // next trajectory point
				data_frame->Rows->Add();
				data_frame->Rows[i]->Cells["i_table"]->Value = i;
				data_frame->Rows[i]->Cells["x_table"]->Value = x;
				data_frame->Rows[i]->Cells["vi_table"]->Value = v[0];
				data_frame->Rows[i]->Cells["wi_table"]->Value = v[1];
				data_frame->Rows[i]->Cells["hi_table"]->Value = h;
				if (is_locerr_required)
				{
					data_frame->Rows[i]->Cells["locerr_table"]->Value = S;
					data_frame->Rows[i]->Cells["v2i_table"]->Value = next_v2[0];
					data_frame->Rows[i]->Cells["vi_v2i_diff_table"]->Value = v[0] - next_v2[0];
					data_frame->Rows[i]->Cells["w2i_table"]->Value = next_v2[1];
					data_frame->Rows[i]->Cells["wi_w2i_diff_table"]->Value = v[1] - next_v2[1];
					data_frame->Rows[i]->Cells["C1_table"]->Value = C1;
					data_frame->Rows[i]->Cells["C2_table"]->Value = C2;
				}
				phase_portrait_pts->Add(v[0], v[1]);
				v_x_pts->Add(x, v[0]);
				w_x_pts->Add(x, v[1]);

				if (abs_locerr_max <= abs(S)) abs_locerr_max = abs(S);
				if (h_max <= h)
				{
					h_max = h;
					x_h_max = x;
				}
				if (h_min >= h)
				{
					h_max = h;
					x_h_max = x;
				}
				if (v_min > v[0]) v_min = v[0];
				i++;
			}

			phase_portrait_graph->AddCurve("w(v)", phase_portrait_pts, Color::Red, SymbolType::None);
			v_x_graph->AddCurve("v(x)", v_x_pts, Color::Red, SymbolType::None);
			w_x_graph->AddCurve("w(x)", w_x_pts, Color::Red, SymbolType::None);
			phase_portrait_graph->XAxis->Scale->Min = v_min;
			v_x_graph->XAxis->Scale->Min = Convert::ToDouble(data_frame->Rows[0]->Cells["x_table"]->Value);
			w_x_graph->XAxis->Scale->Min = Convert::ToDouble(data_frame->Rows[0]->Cells["x_table"]->Value);
			phase_portrait_graphcontrol->AxisChange();
			v_x_graph_graphcontrol->AxisChange();
			w_x_graph_graphcontrol->AxisChange();
			phase_portrait_graphcontrol->Invalidate();
			v_x_graph_graphcontrol->Invalidate();
			w_x_graph_graphcontrol->Invalidate();

			// create reference
			number_of_steps_label->Text = "n = " + (i - 1);
			x_right_border_diff_label->Text = "b-xn = " + (x_max - b - x);
			max_abs_locerr_label->Text = is_locerr_required ? "max|ОЛП| = " + abs_locerr_max : "";
			C1_label->Text = is_locerr_required ? "C1 = " + data_frame->Rows[i - 1]->Cells["C1_table"]->Value : "";
			C2_label->Text = is_locerr_required ? "C2 = " + data_frame->Rows[i - 1]->Cells["C2_table"]->Value : "";
			h_max_label->Text = is_locerr_required ? "max(hi) = " + h_max + " при x = " + x_h_max : "";
			h_min_label->Text = is_locerr_required ? "min(hi) = " + h_min + " при x = " + x_h_min : "";
			max_abs_ui_vi_diff_label->Text = "";

			tab_frame->SelectTab(tab_frame->Controls->IndexOf(phase_portrait_tab));
		}

		void main1()
		{
			locerr_table->Visible = is_locerr_required_checkbox->Checked;
			v2i_table->Visible = is_locerr_required_checkbox->Checked;
			vi_v2i_diff_table->Visible = is_locerr_required_checkbox->Checked;
			wi_table->Visible = false;
			w2i_table->Visible = false;
			wi_w2i_diff_table->Visible = false;
			ui_table->Visible = false;
			ui_vi_abs_diff_table->Visible = false;
			C1_table->Visible = is_locerr_required_checkbox->Checked;
			C2_table->Visible = is_locerr_required_checkbox->Checked;

			tab_frame->Controls->Add(reference_tab);
			tab_frame->Controls->Add(phase_portrait_tab);

			GraphPane^ phase_portrait_graph = phase_portrait_graphcontrol->GraphPane;
			phase_portrait_graph->CurveList->Clear();
			PointPairList^ phase_portrait_pts = gcnew ZedGraph::PointPairList();
			phase_portrait_graph->Title->Text = "График зависимости смещения от времени";
			phase_portrait_graph->XAxis->Title->Text = "х - время";
			phase_portrait_graph->YAxis->Title->Text = "v - смещение";

			data_frame->Rows->Clear();
			bool is_locerr_required = is_locerr_required_checkbox->Checked;
			double epsilon;
			double x = Convert::ToDouble(x0_textbox->Text);
			double u = Convert::ToDouble(u0_textbox->Text);
			double h = Convert::ToDouble(h0_textbox->Text);
			int n = Convert::ToInt32(max_number_of_steps_textbox->Text);
			double x_max = Convert::ToDouble(right_border_textbox->Text);
			double b = Convert::ToDouble(right_border_accuracy_textbox->Text);
			int i = 1;
			int p = 4;
			int C1 = 0;
			int C2 = 0;
			double abs_locerr_max = 0;
			double h_max = h, h_min = h;
			double x_h_max, x_h_min;

			data_frame->Rows->Add();
			data_frame->Rows[0]->Cells["i_table"]->Value = 0;
			data_frame->Rows[0]->Cells["x_table"]->Value = x;
			data_frame->Rows[0]->Cells["vi_table"]->Value = u;
			data_frame->Rows[0]->Cells["hi_table"]->Value = h;
			if (is_locerr_required)
			{
				data_frame->Rows[0]->Cells["locerr_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["v2i_table"]->Value = u;
				data_frame->Rows[0]->Cells["vi_v2i_diff_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["C1_table"]->Value = 0;
				data_frame->Rows[0]->Cells["C2_table"]->Value = 0;
				epsilon = Convert::ToDouble(locerr_accuracy_textbox->Text);
			}

			vector<double> v = { u };

			while (i - 1 < n && x_max - b > x)
			{
				vector<double> next_v = RK4_step(main1_f, x, v, h);
				vector<double> next_v2;
				double S, last_h = h;
				if (is_locerr_required)
				{
					next_v2 = RK4_step(main1_f, x + h / 2, RK4_step(main1_f, x, v, h / 2), h / 2);
					S = (next_v2[0] - next_v[0]) / (pow(2, p) - 1);
					if (abs(S) > epsilon)
					{
						h /= 2;
						C1++;
						continue;
					}
					else
					{
						if (epsilon / pow(2, p + 1) > abs(S))
						{
							h *= 2;
							C2++;
						}
					}
				}
				x += last_h;
				v = next_v; // next trajectory point
				data_frame->Rows->Add();
				data_frame->Rows[i]->Cells["i_table"]->Value = i;
				data_frame->Rows[i]->Cells["x_table"]->Value = x;
				data_frame->Rows[i]->Cells["vi_table"]->Value = v[0];
				data_frame->Rows[i]->Cells["hi_table"]->Value = h;
				if (is_locerr_required)
				{
					data_frame->Rows[i]->Cells["locerr_table"]->Value = S;
					data_frame->Rows[i]->Cells["v2i_table"]->Value = next_v2[0];
					data_frame->Rows[i]->Cells["vi_v2i_diff_table"]->Value = v[0] - next_v2[0];
					data_frame->Rows[i]->Cells["C1_table"]->Value = C1;
					data_frame->Rows[i]->Cells["C2_table"]->Value = C2;
				}
				phase_portrait_pts->Add(x, v[0]);

				if (abs_locerr_max <= abs(S)) abs_locerr_max = abs(S);
				if (h_max <= h)
				{
					h_max = h;
					x_h_max = x;
				}
				if (h_min >= h)
				{
					h_max = h;
					x_h_max = x;
				}
				i++;
			}

			phase_portrait_graph->AddCurve("v(x)", phase_portrait_pts, Color::Red, SymbolType::None);
			phase_portrait_graph->XAxis->Scale->Min = Convert::ToDouble(data_frame->Rows[0]->Cells["x_table"]->Value);
			phase_portrait_graphcontrol->AxisChange();
			phase_portrait_graphcontrol->Invalidate();

			// create reference
			number_of_steps_label->Text = "n = " + (i - 1);
			x_right_border_diff_label->Text = "b-xn = " + (x_max - b - x);
			max_abs_locerr_label->Text = is_locerr_required ? "max|ОЛП| = " + abs_locerr_max : "";
			C1_label->Text = is_locerr_required ? "C1 = " + data_frame->Rows[i - 1]->Cells["C1_table"]->Value : "";
			C2_label->Text = is_locerr_required ? "C2 = " + data_frame->Rows[i - 1]->Cells["C2_table"]->Value : "";
			h_max_label->Text = is_locerr_required ? "max(hi) = " + h_max + " при x = " + x_h_max : "";
			h_min_label->Text = is_locerr_required ? "min(hi) = " + h_min + " при x = " + x_h_min : "";
			max_abs_ui_vi_diff_label->Text = "";

			tab_frame->SelectTab(tab_frame->Controls->IndexOf(phase_portrait_tab));
		}

		void test()
		{
			locerr_table->Visible = is_locerr_required_checkbox->Checked;
			v2i_table->Visible = is_locerr_required_checkbox->Checked;
			vi_v2i_diff_table->Visible = is_locerr_required_checkbox->Checked;
			wi_table->Visible = false;
			w2i_table->Visible = false;
			wi_w2i_diff_table->Visible = false;
			ui_table->Visible = true;
			ui_vi_abs_diff_table->Visible = true;
			C1_table->Visible = is_locerr_required_checkbox->Checked;
			C2_table->Visible = is_locerr_required_checkbox->Checked;

			tab_frame->Controls->Add(reference_tab);
			tab_frame->Controls->Add(phase_portrait_tab);

			GraphPane^ phase_portrait_graph = phase_portrait_graphcontrol->GraphPane;
			phase_portrait_graph->CurveList->Clear();
			PointPairList^ phase_portrait_pts = gcnew ZedGraph::PointPairList();
			phase_portrait_graph->Title->Text = "График зависимости смещения от времени";
			phase_portrait_graph->XAxis->Title->Text = "х - время";
			phase_portrait_graph->YAxis->Title->Text = "v - смещение";
			
			data_frame->Rows->Clear();
			bool is_locerr_required = is_locerr_required_checkbox->Checked;
			double epsilon;
			double x = Convert::ToDouble(x0_textbox->Text);
			double u = Convert::ToDouble(u0_textbox->Text);
			double h = Convert::ToDouble(h0_textbox->Text); 
			int n = Convert::ToInt32(max_number_of_steps_textbox->Text);
			double x_max = Convert::ToDouble(right_border_textbox->Text);
			double b = Convert::ToDouble(right_border_accuracy_textbox->Text);
			int i = 1;
			int p = 4;
			int C1 = 0;
			int C2 = 0;
			double abs_locerr_max = 0;
			double h_max = h, h_min = h;
			double x_h_max, x_h_min;
			double ui_vi_abs_diff_max = 0;

			data_frame->Rows->Add();
			data_frame->Rows[0]->Cells["i_table"]->Value = 0;
			data_frame->Rows[0]->Cells["x_table"]->Value = x;
			data_frame->Rows[0]->Cells["vi_table"]->Value = u;
			data_frame->Rows[0]->Cells["hi_table"]->Value = h;
			data_frame->Rows[0]->Cells["ui_table"]->Value = u;
			data_frame->Rows[0]->Cells["ui_vi_abs_diff_table"]->Value = 0.;
			if (is_locerr_required)
			{
				data_frame->Rows[0]->Cells["locerr_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["v2i_table"]->Value = u;
				data_frame->Rows[0]->Cells["vi_v2i_diff_table"]->Value = 0.;
				data_frame->Rows[0]->Cells["C1_table"]->Value = 0;
				data_frame->Rows[0]->Cells["C2_table"]->Value = 0;
				epsilon = Convert::ToDouble(locerr_accuracy_textbox->Text);
			}

			vector<double> v = { u };
			double C = (u / exp(-5 * x / 2));
			auto sol = get_test_sol(C);

			while (i - 1 < n && x_max - b > x)
			{
				vector<double> next_v = RK4_step(test_f, x, v, h);
				vector<double> next_v2;
				double S, last_h = h;
				if (is_locerr_required)
				{
					next_v2 = RK4_step(test_f, x + h / 2, RK4_step(test_f, x, v, h / 2), h / 2);
					S = (next_v2[0] - next_v[0]) / (pow(2, p) - 1);
					if (abs(S) > epsilon)
					{
						h /= 2;
						C1++;
						continue;
					}
					else
					{
						if (epsilon / pow(2, p + 1) > abs(S))
						{
							h *= 2;
							C2++;
						}
					}
				}
				x += last_h;
				u = sol(x);
				v = next_v; // next trajectory point
				data_frame->Rows->Add();
				data_frame->Rows[i]->Cells["i_table"]->Value = i;
				data_frame->Rows[i]->Cells["x_table"]->Value = x;
				data_frame->Rows[i]->Cells["vi_table"]->Value = v[0];
				data_frame->Rows[i]->Cells["hi_table"]->Value = h;
				data_frame->Rows[i]->Cells["ui_table"]->Value = u;
				data_frame->Rows[i]->Cells["ui_vi_abs_diff_table"]->Value = abs(u - v[0]);
				if (is_locerr_required)
				{
					data_frame->Rows[i]->Cells["locerr_table"]->Value = S;
					data_frame->Rows[i]->Cells["v2i_table"]->Value = next_v2[0];
					data_frame->Rows[i]->Cells["vi_v2i_diff_table"]->Value = v[0] - next_v2[0];
					data_frame->Rows[i]->Cells["C1_table"]->Value = C1;
					data_frame->Rows[i]->Cells["C2_table"]->Value = C2;
				}
				phase_portrait_pts->Add(x, v[0]);

				if (abs_locerr_max <= abs(S)) abs_locerr_max = abs(S);
				if (h_max <= h)
				{
					h_max = h;
					x_h_max = x;
				}
				if (h_min >= h)
				{
					h_max = h;
					x_h_max = x;
				}
				if (ui_vi_abs_diff_max <= abs(u - v[0])) ui_vi_abs_diff_max = abs(u - v[0]);
				i++;
			}

			phase_portrait_graph->AddCurve("v(x)", phase_portrait_pts, Color::Red, SymbolType::None);
			phase_portrait_graph->XAxis->Scale->Min = Convert::ToDouble(data_frame->Rows[0]->Cells["x_table"]->Value);
			phase_portrait_graphcontrol->AxisChange();
			phase_portrait_graphcontrol->Invalidate();

			// create reference
			number_of_steps_label->Text = "n = " + (i-1);
			x_right_border_diff_label->Text = "b-xn = " + (x_max - b - x);
			max_abs_locerr_label->Text = is_locerr_required ? "max|ОЛП| = " + abs_locerr_max : "";
			C1_label->Text = is_locerr_required ? "C1 = " + data_frame->Rows[i - 1]->Cells["C1_table"]->Value : "";
			C2_label->Text = is_locerr_required ? "C2 = " + data_frame->Rows[i - 1]->Cells["C2_table"]->Value : "";
			h_max_label->Text = is_locerr_required ? "max(hi) = " + h_max + " при x = " + x_h_max : "";
			h_min_label->Text = is_locerr_required ? "min(hi) = " + h_min + " при x = " + x_h_min : "";
			max_abs_ui_vi_diff_label->Text = is_locerr_required ? "max|ui - vi| = " + ui_vi_abs_diff_max : "";

			tab_frame->SelectTab(tab_frame->Controls->IndexOf(phase_portrait_tab));
		}

		void remove_unnecessary_tabs()
		{
			tab_frame->Controls->Remove(reference_tab);
			tab_frame->Controls->Remove(phase_portrait_tab);
			tab_frame->Controls->Remove(v_x_graph_tab);
			tab_frame->Controls->Remove(w_x_graph_tab);
		}

	private: System::Void task_selection_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		calculate_button->Visible = true;
		if (task_selection->SelectedIndex == 2)
		{
			w0_label->Visible = true;
			w0_textbox->Visible = true;
			a_coef_label->Visible = true;
			textBox9->Visible = true;
			b_coef_label->Visible = true;
			x0_textbox0->Visible = true;
		}
		else
		{
			w0_label->Visible = false;
			w0_textbox->Visible = false;
			a_coef_label->Visible = false;
			textBox9->Visible = false;
			b_coef_label->Visible = false;
			x0_textbox0->Visible = false;
		}
		switch (task_selection->SelectedIndex)
		{
		case 0: task_formulation_picturebox->Image = Image::FromFile(".\\images\\test.jpg"); break;
		case 1: task_formulation_picturebox->Image = Image::FromFile(".\\images\\main1.jpg"); break;
		case 2: task_formulation_picturebox->Image = Image::FromFile(".\\images\\main2.jpg"); break;
		}
		remove_unnecessary_tabs();
		tab_frame->SelectTab(tab_frame->Controls->IndexOf(task_formulation_tab));
		data_frame->Visible = false;
	}
	private: System::Void is_locerr_required_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		locerr_accuracy_label->Visible = is_locerr_required_checkbox->Checked;
		locerr_accuracy_textbox->Visible = is_locerr_required_checkbox->Checked;
	}
	private: System::Void calculate_button_Click(System::Object^ sender, System::EventArgs^ e) {
		remove_unnecessary_tabs();
		data_frame->Visible = true;
		switch (task_selection->SelectedIndex) {
		case 0: test(); break;
		case 1: main1(); break;
		case 2: main2(); break;
		}
	}
};
}
