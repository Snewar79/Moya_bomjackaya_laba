#pragma once
#include <fstream>
#include "rac_class.h"
typedef double mtype;



namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			x = NULL;
			y = NULL;
			gr = pictureBox1->CreateGraphics();

			lb = -10;
			rb = 10;
			ub = 10;
			db = -10;
			//
			mouse_down = false;

			label7->ForeColor = Color::Red;
			label7->Text = "Incorrect data";
		}


		bool mouse_down;

		int st_x;
		int st_y;
		int en_x;
		int en_y;

		bool good_data = false;
		int point_count;
		cube_polinom<mtype> *polinoms;
		double * x;
		double lb;
		double rb;
		double ub;
		double db;
	private: System::Windows::Forms::Label^  label3;
	public:
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
			 Graphics^ gr;


		void print_pols()
		{
		
		
			gr->Clear(Color::White);





			int w = pictureBox1->Width;
			int h = pictureBox1->Height;

			int k_h = 20 * 2;
			int k_w = 20 * 2;
			double coeff_h = h / double(ub - db);
			double coeff_w = w / double(rb - lb);

			/*for (int i = 1; i <= k_h; i++)
			{
			gr->DrawLine(Pens::Gray, 0, h / k_h * i, w, h / k_h * i);


			//sc_x0 = double(w_x0 - lb) * coeff_w;
			//sc_y = double (w_y0 - lu) * coeff_h;
			double wh = (double(k_h * i) / coeff_h) + ub;
			int x = 3;
			}


			for (int i = 1; i <= k_w; i++)
			{
			gr->DrawLine(Pens::Gray, h / k_w * i, 0, h / k_w * i, h);
			}

			//------------------------
			*/

			for (int i = lb; i < rb; i++)
			{
				double delta = rb - lb;
				int weh = pictureBox1->Width;

				double linex = i - lb;

				linex = (linex / delta) * weh;

				gr->DrawLine(System::Drawing::Pens::Black, linex, 0, linex, pictureBox1->Height);

			}

			//-- FOR NULL ORD

			for (int i = 0; i <= 0; i++)
			{
				double delta = rb - lb;
				int weh = pictureBox1->Width;

				double linex = i - lb;

				linex = (linex / delta) * weh;

				gr->DrawLine(System::Drawing::Pens::DarkOrange, linex, 0, linex, pictureBox1->Height);

			}







			for (int i = db; i < ub; i++)
			{
				double delta = ub - db;
				int weh = pictureBox1->Height;

				double linex = i - db;

				linex = (linex / delta) * weh;

				gr->DrawLine(System::Drawing::Pens::Black, 0, linex, pictureBox1->Height, linex);

			}

			// FOR NULL ABS



			for (int i = 0; i <= 0; i++)
			{
				double delta = ub - db;
				int weh = pictureBox1->Height;

				double linex = i - db;

				linex = (linex / delta) * weh;

				gr->DrawLine(System::Drawing::Pens::DarkOrange, 0, linex, pictureBox1->Height, linex);

			}



			//-------------------------

			for (int i = 0; i < point_count - 1; i++)
			{
				int sc_x0, sc_x1;
				double w_x0, w_x1;




				//System::Drawing::Color c(Color::FromArgb())

				Color c(Color::FromArgb(255, 20, 20));
				Color b(Color::FromArgb(20, 20, 255));
				Pen^ p = gcnew Pen(c);
				//	System::Drawing::Brush b();

				c = Color::FromArgb(rand() % 255, rand() % 255, rand() % 255);

				//Brush^ b = gcnew Brush(c);
				//	System::Drawing::Brush^ = gcnew System::Drawing::Brush(c);



				w_x0 = polinoms->polArr[i].lb;
				w_x1 = polinoms->polArr[i].rb;


				sc_x0 = double(w_x0 - lb) * coeff_w;
				sc_x1 = double(w_x1 - lb) * coeff_w;

				int k = 50;










				double w_y_p = polinoms->polArr[i].calck((double(sc_x0) / double(1)) / coeff_w + lb);
				int sc_y_p;
				sc_y_p = (ub - w_y_p) * coeff_h;

				gr->FillEllipse(gcnew SolidBrush(b), sc_x0 - 3, sc_y_p - 3, 5, 5);

				w_y_p = polinoms->polArr[i].calck((double(sc_x1) / double(1)) / coeff_w + lb);
				sc_y_p;
				sc_y_p = (ub - w_y_p) * coeff_h;
				gr->FillEllipse(gcnew SolidBrush(b), sc_x1 - 3, sc_y_p - 3, 5, 5);




				for (int j = sc_x0 * k; j < sc_x1 * k; j++)
				{
					double w_y = polinoms->polArr[i].calck((double(j) / double(k)) / coeff_w + lb);

					int sc_y;
					sc_y = (ub - w_y) * coeff_h;
					gr->FillEllipse(gcnew SolidBrush(c), int(double(j) / double(k)), sc_y, 2, 2);

				}



				w_y_p = polinoms->polArr[i].calck((double(sc_x0) / double(1)) / coeff_w + lb);
				sc_y_p;
				sc_y_p = (ub - w_y_p) * coeff_h;

				gr->FillEllipse(gcnew SolidBrush(b), sc_x0 - 3, sc_y_p - 3, 5, 5);

				w_y_p = polinoms->polArr[i].calck((double(sc_x1) / double(1)) / coeff_w + lb);
				sc_y_p;
				sc_y_p = (ub - w_y_p) * coeff_h;
				gr->FillEllipse(gcnew SolidBrush(b), sc_x1 - 3, sc_y_p - 3, 5, 5);



			}
		
		
		
		
		
		
		
		
		}

		void calculate_polinoms()
		{

			if (!good_data) return;
			ofstream fout;
			try {

				polinoms = new cube_polinom<mtype>(point_count);
				polinoms->init(x, y, point_count);
				polinoms->iterpolate();
				textBox2->Text = "";
			

				fout.open("Polionoms.txt");
				for (int i = 0; i < point_count - 1; i++)
				{
					String^ MyString = gcnew String((polinoms)->polArr[i].st_pol.c_str());
					textBox2->Text += MyString;
					textBox2->Text += gcnew String("\r\n------------------------------\r\n");
					textBox2->Refresh();
					fout <<  (polinoms)->polArr[i].st_pol.c_str();
					fout << "\r\n";

					polinoms->polArr[i].lb = x[i + 1];
					polinoms->polArr[i].rb = x[i + 2];
				}
				fout.close();
				print_pols();
			}
			catch (...)
			{

				good_data = false;
				fout.close();
				gr->Clear(System::Drawing::Color::White);
				label7->ForeColor = Color::Red;
				label7->Text = "Incorrect data";
				textBox2->Text = "";
			}

		
		
		}


		void parse_text()
		{
		
			ofstream fout;
			ifstream fin;
			try {

				fout.open("tmp.bin");

				for (int i = 0; i < textBox1->Text->Length; i++)
				{
					fout << char(textBox1->Text[i]);
				}

				fout.close();

				fin.open("tmp.bin");

				int t;


				if (!fin.eof())
					fin >> t;
				else
				{
					throw - 1;
				}



				point_count = t;



				x = new double[point_count + 2];

				y = new double[point_count + 2];


				for (int i = 0; i < point_count; i++)
				{
					if (!fin.eof())
						fin >> x[i + 1];
					else
					{
						throw - 1;
					}

					if (i > 0 && x[i + 1] <= x[i])
					{
						throw - 1;
					}



					if (!fin.eof())
						fin >> y[i + 1];
					else
					{
						throw - 1;
					}
				}

				fin.close();

				if (t <= 0 | t != int(t)) throw - 1;


				good_data = true;
				fin.close();
				fout.close();
				gr->Clear(System::Drawing::Color::White);
				label7->ForeColor = Color::Green;
				label7->Text = "Correct data";
			}
			catch (...)
			{


				good_data = false;
				fin.close();
				fout.close();
				gr->Clear(System::Drawing::Color::White);
				label7->ForeColor = Color::Red;
				label7->Text = "Incorrect data";
				textBox2->Text = "";
			}
		}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
			parse_text();
			calculate_polinoms();
		
		}



	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	public:
		double * y;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(646, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 516);
			this->textBox1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(501, 447);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 66);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Calculate polinoms";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 433);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(483, 95);
			this->textBox2->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::pictureBox1_DragEnter);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseHover);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(441, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"X: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(441, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Y: ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(418, 260);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(67, 61);
			this->button4->TabIndex = 8;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(418, 327);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(67, 71);
			this->button5->TabIndex = 9;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(569, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Point count";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(594, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"X1 Y1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(594, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"X2 Y2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(594, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"...";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(557, 216);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Incorrect data";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 540);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"Pol_s";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		parse_text();
	}



private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!good_data) return;


	print_pols();




}



private: System::Void pictureBox1_MouseWheel(System::Object^  sender, System::EventArgs^  e) {


}



private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if (!good_data) return;
	double wc, hc;

	wc = double(rb - lb)/pictureBox1->Width;
	hc = double(ub - db) / pictureBox1->Height;
	label1->Text = "X: " + Convert::ToString(lb + e->X * wc) ;
	label2->Text = "Y: " + Convert::ToString(ub - e->Y * hc);


}
private: System::Void pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {



	if (rb - lb < 0.25) return;

	double	xcenter;
	double  ycenter;
	xcenter = (rb + lb) / 2;
	ycenter = (ub + db) / 2;

	ub = ub - (ub - ycenter) * 0.5;
	db = db + (ycenter - db) * 0.5;

	rb = rb - (rb - xcenter) * 0.5;
	lb = lb + (xcenter - lb) * 0.5;

	if (!good_data) return;

	print_pols();

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {


	if (rb - lb > 50) return;

	double	xcenter;
	double  ycenter;
	xcenter = (rb + lb) / 2;
	ycenter = (ub + db) / 2;

	ub = ycenter + (ub - ycenter) * 2;
	db = ycenter - (ycenter - db) * 2;

	rb = xcenter + (rb - xcenter) * 2;
	lb = xcenter - (xcenter - lb) * 2;


	if (!good_data) return;
	print_pols();



}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	mouse_down = true;
	st_x = e->X;
	st_y = e->Y;
	en_x = st_x;
	en_y = st_y;



}
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {




	if (mouse_down)
	{
	



	}
	
}
private: System::Void pictureBox1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {


}
};
}
