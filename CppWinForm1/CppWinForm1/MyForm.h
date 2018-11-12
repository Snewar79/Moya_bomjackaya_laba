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
//			gr = pictureBox1->CreateGraphics();

			lb = -10;
			rb = 10;
			ub = 10;
			db = -10;
			//
		}

		int point_count;
		cube_polinom<mtype> *polinoms;
		double * x;
		int lb;
		int rb;
		int ub;
		int db;
		Graphics^ gr;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;




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
	private: System::Windows::Forms::Button^  button1;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 231);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"BT1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 278);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"BT2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 307);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(483, 95);
			this->textBox2->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 417);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		ofstream fout("tmp.bin");
		
		for (int i = 0; i < textBox1->Text->Length; i++)
		{
			fout << char(textBox1->Text[i]);
		}

		fout.close();

		ifstream fin("tmp.bin");

		int t;

		fin >> t;



		point_count = t;

		x = new double[point_count + 2];
		y = new double[point_count + 2];


		for (int i = 0; i < point_count; i++)
		{
			fin >> x[i + 1]; fin >> y[i + 1];
		}

		fin.close();

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		polinoms = new cube_polinom<mtype>(point_count);
		polinoms->init(x, y, point_count);
		polinoms->iterpolate();
		textBox2->Text = "";
		for (int i = 0; i < point_count - 1; i++)
		{
			String^ MyString = gcnew String((polinoms)->polArr[i].st_pol.c_str());
			textBox2->Text += MyString;
			textBox2->Text += gcnew String("\r\n");
			textBox2 -> Refresh();
			polinoms->polArr[i].lb = x[i + 1];
			polinoms->polArr[i].rb = x[i + 2];
		}
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {


/*
	gr->Clear(Color::White);





	//int w = pictureBox1->Width;
	//int h = pictureBox1->Height;

	int k_h = 20 * 2;
	int k_w = 20 * 2;
//	double coeff_h = h / double(ub - db);
//	double coeff_w = w / double(rb - lb);

	for (int i = 1; i <= k_h; i++)
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



	for (int i = 0; i < point_count - 1; i++)
	{
		int sc_x0, sc_x1;
		double w_x0, w_x1;
		

	

		//System::Drawing::Color c(Color::FromArgb())

		Color c(Color::FromArgb(255, 20, 20));
		Color b(Color::FromArgb(20, 20, 255));
		Pen^ p = gcnew Pen(c);
	//	System::Drawing::Brush b();

		

		//Brush^ b = gcnew Brush(c);
	//	System::Drawing::Brush^ = gcnew System::Drawing::Brush(c);
		


		w_x0 = polinoms->polArr[i].lb;
		w_x1 = polinoms->polArr[i].rb;

		
//		sc_x0 = double(w_x0 - lb) * coeff_w;
//		sc_x1 = double(w_x1 - lb) * coeff_w;
		
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
			double w_y = polinoms->polArr[i].calck((double(j)/double(k))/coeff_w + lb);
			
			int sc_y;
			sc_y = (ub - w_y) * coeff_h;
			gr->FillEllipse(gcnew SolidBrush(c) , int(double(j)/double(k)), sc_y, 2, 2);

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



	*/
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	/*

	double wc, hc;

	wc = double(rb - lb)/pictureBox1->Width;
	hc = double(ub - db) / pictureBox1->Height;
	label1->Text = "X: " + Convert::ToString(lb + e->X * wc) ;
	label2->Text = "Y: " + Convert::ToString(ub - e->Y * hc);
	*/

}
};
}
