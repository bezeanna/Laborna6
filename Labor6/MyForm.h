#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
namespace Labor6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(64, 51);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(437, 150);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(64, 282);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(437, 150);
			this->dataGridView2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(571, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 64);
			this->button1->TabIndex = 2;
			this->button1->Text = L"← найбільший елемент одновимірного масиву";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(571, 328);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(255, 64);
			this->button2->TabIndex = 3;
			this->button2->Text = L"← середнє арифметичне всіх додатних елементів у даному двовимірному масиві.";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 532);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->ColumnCount = 1;
		dataGridView1->Columns[0]->Name = "Value";
		dataGridView2->ColumnCount = 1;
		dataGridView2->Columns[0]->Name = "Value";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int size = 10;
		int* arr = new int[size]; 
		int max = INT_MIN; 
		srand(static_cast<unsigned>(time(0)));
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 201 - 70;
		}
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		dataGridView1->Rows->Clear(); 
		for (int i = 0; i < size; i++) {
			dataGridView1->Rows->Add(arr[i], "");
		}
		String^ message = String::Format("Найбільший елемент масиву: {0}", max);
		MessageBox::Show(message);
		delete[] arr;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = 3;
		int** a = new int* [n];
		for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			for (int j = 0; j < n; j++) {
				a[i][j] = rand() % 200-100;
			}
		}
		dataGridView2->RowCount = n;
		dataGridView2->ColumnCount = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dataGridView2->Rows[i]->Cells[j]->Value = a[i][j];
			}
		}
		int sum = 0;
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > 0) {
					sum += a[i][j];
					k++;
				}
			}
		}
		double serz = 0.0;
		if (k > 0) {
			serz = static_cast<double>(sum) / k;
		}
		MessageBox::Show("Середнє арифметичне додатних елементів: " + serz);
		for (int i = 0; i < n; i++) {
			delete[] a[i];
		}
		delete[] a;
	}
};
}
