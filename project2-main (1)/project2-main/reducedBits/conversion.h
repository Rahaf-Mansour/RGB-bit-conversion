#pragma once

#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include<string>

using namespace std;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned long   DWORD;


#pragma pack(push)
#pragma pack(2)

struct INFO
{
	WORD bfType;
	DWORD BfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
	DWORD biSize;
	int biWidth;
	int biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
};

#pragma pack(pop)

class Image
{
public:

	int height;
	int width;
	int rowsize;    // RGB -> 3 bytes(24 bits)
	BYTE* term;


	Image()   //storage is bottom-up, from left to right
	{
		height = 0;
		width = 0;
	}

	Image(int height, int width)
	{
		this->height = height;
		this->width = width;
		rowsize = (3 * width + 3);
		term = new BYTE[height * rowsize];
	}

	void load(const char* filename)
	{
		INFO h;
		ifstream f;
		f.open(filename, ios::in | ios::binary);
		f.read((char*)&h, sizeof(h));
		width = h.biWidth;
		height = h.biHeight;
		cout << "reading from " << filename << "..." << endl;
		*this = Image(height, width);
		f.read((char*)term, height * rowsize);
		f.close();
	}

	void save(const char* filename)
	{
		INFO h =
		{
			19778,   //0x4d42
			DWORD(rowsize * height),
			0,
			0,
			0,
			40,
			width,
			height,
			1,
			24,
			0,
			DWORD(rowsize * height),
			72,
			72,
			0,
			0
		};

		cout << "writing into " << filename << "..." << endl;
		ofstream f;
		f.open(filename, ios::out | ios::binary);
		f.write((char*)&h, sizeof(h));
		f.write((char*)term, rowsize * height);
		f.close();
	}
};


//Varible 
long INDEX = 0;
int r = 0, g = 0, b = 0,
bit_r, bit_g, bit_b, d_r, d_g, d_b,
p_r, p_g, p_b;
const char* filename;


Image RGB_abc(Image input)
{

	Image output = input;

	for (int Y = 0; Y < input.height; Y++)
	{
		for (int X = 0; X < input.width; X++)
		{
			INDEX = (X * input.height * 3) + (Y * 3);
			b = input.term[INDEX + 0]; //Blue
			g = input.term[INDEX + 1]; //Green
			r = input.term[INDEX + 2]; //Red


			//for r=2 g=2 b=1   r*#2^2#/256*(256/#4#)  => r=r*4/256*64


			d_r = 256 / pow(2, bit_r);
			d_g = 256 / pow(2, bit_g);
			d_b = 256 / pow(2, bit_b);

			p_r = pow(2, bit_r);
			p_g = pow(2, bit_g);
			p_b = pow(2, bit_b);

			r = r * p_r / 256 * d_r;
			g = g * p_g / 256 * d_g;
			b = b * p_b / 256 * d_b;


			input.term[INDEX + 0] = b;
			input.term[INDEX + 1] = g;
			input.term[INDEX + 2] = r;
		}
	}

	return input;

}

#pragma pack(pop)  	//Restore



Image input, output;

namespace reducedBits {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	public ref class conversion : public System::Windows::Forms::Form
	{
	public:
		conversion(void)
		{
			InitializeComponent();
		}

	protected:
		~conversion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(conversion::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(88, 535);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &conversion::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(74, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Bits for";
			this->label1->Click += gcnew System::EventHandler(this, &conversion::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F));
			this->label2->Location = System::Drawing::Point(74, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Bits for";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F));
			this->label3->Location = System::Drawing::Point(74, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 21);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Bits for";
			this->label3->Click += gcnew System::EventHandler(this, &conversion::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->textBox1->Location = System::Drawing::Point(209, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(44, 27);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->textBox3->Location = System::Drawing::Point(209, 129);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(44, 27);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->textBox2->Location = System::Drawing::Point(209, 86);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(44, 27);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Caveat", 24, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(83, 222);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(162, 41);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Input Image:";
			this->label4->Click += gcnew System::EventHandler(this, &conversion::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Caveat", 24, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(366, 222);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(173, 41);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Output Image:";
			this->label5->Click += gcnew System::EventHandler(this, &conversion::label5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 280);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(279, 236);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &conversion::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(309, 280);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(279, 236);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(343, 535);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 34);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Convert";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &conversion::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(135, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 22);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Red";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Green;
			this->label7->Location = System::Drawing::Point(135, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 22);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Green";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Blue;
			this->label8->Location = System::Drawing::Point(135, 128);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(47, 22);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Blue";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(356, 23);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(171, 142);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 17;
			this->pictureBox4->TabStop = false;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold));
			this->button3->Location = System::Drawing::Point(456, 535);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(83, 35);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Clear All";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &conversion::button3_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Caveat", 15, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(73, 608);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(168, 25);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Name: Rahaf Mansour";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Caveat", 15, System::Drawing::FontStyle::Bold));
			this->label10->Location = System::Drawing::Point(351, 608);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(189, 25);
			this->label10->TabIndex = 20;
			this->label10->Text = L"To Prof. Salaheddin Odeh ";
			// 
			// conversion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(600, 656);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"conversion";
			this->Text = L"conversion";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
		
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pictureBox1->ImageLocation = openFileDialog1->FileName;
	}

	System::String^ path = openFileDialog1->FileName;
	System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path);
	const char* filename = static_cast<const char*>(ptr.ToPointer());
	input.load(filename);

}



private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	

	String^ bit_rs = textBox1->Text;
	String^ bit_gs = textBox2->Text;
	String^ bit_bs = textBox3->Text;

	bit_r = Convert::ToInt32(bit_rs);
	bit_g = Convert::ToInt32(bit_gs);
	bit_b = Convert::ToInt32(bit_bs);
	
	output = RGB_abc(input);
	output.save("outimag.png");
	pictureBox2->ImageLocation = "C:/Users/user/Desktop/project2-main (1)/project2-main/reducedBits/outimag.png";

	
}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	pictureBox1->ImageLocation = "";
	pictureBox2->ImageLocation = "";
}
};
}
