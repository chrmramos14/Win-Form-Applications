#include "stdafx.h"
#include "OOPClass.h"
#include "afxwin.h"
#include <afxdb.h>
#include <time.h>
#include <cstdlib>
#include <exception>
#include <atltime.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;






namespace Grosspayprogram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	/// <summary>
	/// Summary for WinGrosspay
	/// </summary>
	public ref class WinGrosspay : public System::Windows::Forms::Form
	{
	public:
		WinGrosspay(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WinGrosspay()
		{
			if (components)
			{
				delete components;
			}
		}

	private:


		static CObList * itemlist = new CObList;


		NetPayClass * itempa2;
		NetPayClass  * itempa3;


		
		  static Hashtable^ openWith = gcnew Hashtable();

        static bool databaseopenflag = false;

		 


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtsearch;


	private: System::Windows::Forms::ListBox^  lstData;
	private: System::Windows::Forms::PictureBox^  picitem;


	private: System::Windows::Forms::Button^  cmdsearch2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openDatabaseToolStripMenuItem;

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtsearch = (gcnew System::Windows::Forms::TextBox());
			this->lstData = (gcnew System::Windows::Forms::ListBox());
			this->picitem = (gcnew System::Windows::Forms::PictureBox());
			this->cmdsearch2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDatabaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picitem))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(85, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search Value";
			// 
			// txtsearch
			// 
			this->txtsearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtsearch->Location = System::Drawing::Point(205, 68);
			this->txtsearch->Name = L"txtsearch";
			this->txtsearch->Size = System::Drawing::Size(100, 26);
			this->txtsearch->TabIndex = 1;
			// 
			// lstData
			// 
			this->lstData->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lstData->FormattingEnabled = true;
			this->lstData->ItemHeight = 18;
			this->lstData->Location = System::Drawing::Point(12, 148);
			this->lstData->Name = L"lstData";
			this->lstData->Size = System::Drawing::Size(868, 40);
			this->lstData->TabIndex = 3;
			// 
			// picitem
			// 
			this->picitem->Location = System::Drawing::Point(292, 297);
			this->picitem->Name = L"picitem";
			this->picitem->Size = System::Drawing::Size(100, 50);
			this->picitem->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picitem->TabIndex = 4;
			this->picitem->TabStop = false;
			// 
			// cmdsearch2
			// 
			this->cmdsearch2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cmdsearch2->Location = System::Drawing::Point(343, 74);
			this->cmdsearch2->Name = L"cmdsearch2";
			this->cmdsearch2->Size = System::Drawing::Size(90, 29);
			this->cmdsearch2->TabIndex = 5;
			this->cmdsearch2->Text = L"Search";
			this->cmdsearch2->UseVisualStyleBackColor = true;
			this->cmdsearch2->Click += gcnew System::EventHandler(this, &WinGrosspay::cmdsearch2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(933, 29);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openDatabaseToolStripMenuItem});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 25);
			this->fileToolStripMenuItem->Text = L"File";
		 
			// 
			// openDatabaseToolStripMenuItem
			// 
			this->openDatabaseToolStripMenuItem->Name = L"openDatabaseToolStripMenuItem";
			this->openDatabaseToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->openDatabaseToolStripMenuItem->Text = L"Open Database";
			this->openDatabaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &WinGrosspay::openDatabaseToolStripMenuItem_Click);
			// 
			// WinGrosspay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 594);
			this->Controls->Add(this->cmdsearch2);
			this->Controls->Add(this->picitem);
			this->Controls->Add(this->lstData);
			this->Controls->Add(this->txtsearch);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"WinGrosspay";
			this->Text = L"Hash Table";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picitem))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	 
	
private: System::Void cmdsearch2_Click(System::Object^  sender, System::EventArgs^  e) 
 {
	 String ^ fmtStr1 = "{0,-6}{1, 11}{2, 12}{3, 9}{4,9}{5, 12}{6, 12}{7, 12}";
	String ^ fmtStr2 = "{0, -15}";

	bool found = false;

	 CString search = txtsearch->Text;

	  

	 TCHAR * thesearch;
	         
		thesearch = search.GetBuffer(0);
                String ^   searchhashtable = gcnew String (thesearch);



     int id, hours;
	CString  employee, department,  picture;
	  double  rate, grosspay, federalincometax, netpay;
	 
			 
   
           Bitmap^ image1;
	    String ^   fileToDisplay;


	  if (openWith->ContainsValue( searchhashtable ) )
           {
	     INT_PTR  number= itemlist->GetCount();

	     POSITION pos;

             pos= itemlist->GetTailPosition();
             CObject *b2 =itemlist->GetPrev(pos);
 
             itempa2 = (NetPayClass *)b2;
 
	     bool flag = false;

            for (int st =0; st<number; st++)
            { 	 
                 itempa2->getdata(id, employee, department, hours, rate, grosspay, federalincometax,netpay,picture);
		  TCHAR * sname;
	         
		sname = employee.GetBuffer(0);
                String ^   theemployee = gcnew String (sname);

                sname = department.GetBuffer(0);
                String ^   thedepartment = gcnew String (sname);

		TCHAR *sp = picture.GetBuffer(0);
                  String ^ thpicture= gcnew String (sp);

		  if (search == theemployee  && flag == false)
		  {
			  found = true;
                          flag = true;

		         lstData->Items->Add(String::Format(fmtStr1, id, theemployee, thedepartment, hours, rate, grosspay, federalincometax,netpay ));

		           String ^      kpicture= "C:\\SPU\\Cs370\\Chapter5-Hashing\\HashTableNetPay\\WindowsTextFile_Grosspay\\Grosspayprogram\\";
                         fileToDisplay = kpicture + thpicture;

	                      try
                              {
                               image1 = gcnew Bitmap( fileToDisplay ,true );
         
                               picitem->AutoSize=false;
                              // Set the PictureBox to display the image.
                               picitem->Image = image1;
 
                           }
                           catch ( ArgumentException^ ) 
                           {
                                 MessageBox::Show( "There was an error."
                                  "Check the path to the image file." );
                            }

			             


              }



      if (st < (number-1))
		  {
			 b2 =itemlist->GetPrev(pos);
			itempa2 = (NetPayClass *)b2;
			 
		}

	 

               }
	 


	 	

 

	  
	 
	 }  

     }
private: System::Void openDatabaseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  using namespace System::IO;
    

Bitmap^ image1;
	String ^  kpicture= "C:\\SPU\\Cs370\\Chapter5-Hashing\\HashTableNetPay\\WindowsTextFile_Grosspay\\Grosspayprogram\\equation5.jpg";
		 try
                          {
                               image1 = gcnew Bitmap( kpicture ,true );
         
                               picitem->AutoSize=false;
                              // Set the PictureBox to display the image.
                               picitem->Image = image1;
 
                           }
                           catch ( ArgumentException^ ) 
                           {
                                 MessageBox::Show( "There was an error."
                                  "Check the path to the image file." );
                            }
                         
      
     //////////////////////////////hash table
			int hashcodearray[100]= {0};
	int x=0;
	 int keyid=0;
			srand( (unsigned)time( NULL ) );
            int rannum ;
//////////////////////////////////////////////////////////////


       CString Connection;
	CDatabase database;
 
	CString username;
       CString password;
 
       username = "LAPTOP-B3MQBP0H\\UFOSQLEXPRESS\\mmitchell";
    
       Connection =_T("Driver={SQL Server Native Client 11.0};Server=LAPTOP-B3MQBP0H\\UFOSQLEXPRESS;AttachDbFilename=C:\\LectureNotes\\CS370\\SearchNotes\\BinarySearch\\NetPayDB\\Netpay.mdf;Trusted_Connection=Yes;Uid=")+username+_T(";Pwd=")+password+_T(";");

       database.OpenEx(Connection,CDatabase::useCursorLib);

       CString thestring;

	CString query ="SELECT ID, Employee, Department, Hours, Rate, Grosspay, Fedincometax, Netpay, Pictures FROM Salary";

       CRecordset recordset(&database);
	CString temp,record;
	recordset.Open(CRecordset::forwardOnly,query,CRecordset::readOnly);

	//CStringList original;

	CString  sid, employee, department, shours, srate, sgrosspay, sfederalincometax, snetpay, pictures ;
 
	 int id, hours;
	 double rate, grosspay, federalincometax, netpay=0;

       double totalnetpay=0;

	int count=0;


	 
	
	while(!recordset.IsEOF())
	{ 
		 record=_T("");
		 register int len=recordset.GetODBCFieldCount();
		  
		 recordset.GetFieldValue("ID", sid); 		
              recordset.GetFieldValue("Employee", employee); 
	       recordset.GetFieldValue("Department", department); 
	       recordset.GetFieldValue("Hours", shours); 
	       recordset.GetFieldValue("Rate", srate); 

		     recordset.GetFieldValue("Grosspay", sgrosspay); 
	       recordset.GetFieldValue("Fedincometax", sfederalincometax); 

		     recordset.GetFieldValue("Netpay", snetpay); 
	      
              recordset.GetFieldValue("Pictures", pictures); 
	 
    
          id= atoi(sid);
		
		 hours = atoi(shours);
		 rate = atof(srate);

 	        grosspay=atof(sgrosspay);		
            	 
			 federalincometax=atof(sfederalincometax);
			  netpay=atof(snetpay);

			    TCHAR * sname;
	         

               sname = employee.GetBuffer(0);
                 String ^ semployee = gcnew String (sname); 

				  sname =department.GetBuffer(0);
                 String ^ key = gcnew String (sname); 

            itemlist->AddHead(itempa2 = new NetPayClass(id, employee, department, hours, rate, grosspay, federalincometax, netpay, pictures));    
			 
	      netpay = itempa2->getcomputedvalue();

        		 //*****************************Add data to Hash Table *****************************


		  try
             {
			     //add to hash table
			     openWith->Add(key,semployee);			 
				   hashcodearray[x] = key->GetHashCode();
			  }
         catch(...)
             {
		   
				   // if hashcode exist get a random number and add it to the hashcode
		           hashcodearray[x] = key->GetHashCode();
			  
			 rannum =x +  rand () %  hashcodearray[x];
		     openWith->Add( (hashcodearray[x] +rannum) ,semployee);
			 
			 
        }
		 

		x= x+1;
		//*********************************************************************************
        	recordset.MoveNext(); 
	
       }

	itempa2->sort(itemlist);

	 

	



  

		 }
 
};
}
