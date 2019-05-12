//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
Memo1->Lines->LoadFromFile("informaton\\baza.txt");
String place = Memo1->Lines->Strings[0];
ADOConnection1->Connected=true;
ADOTable1->Active=true;

ADOTable2->Active=true;
int id;
for (int i = 1; i <= ADOTable1->RecordCount; i++) {
	ListBox1->Items->Add(ADOTable1->FieldByName("name_surname")->AsString);
	id = ADOTable1->FieldByName("id")->AsInteger;


	ADOTable2->First();
	ADOTable1->Next();
}

ListBox1->ItemIndex=0;
ADOTable1->First();

		String surname = ListBox1->Items->Strings[ListBox1->ItemIndex];
				while (surname!=ADOTable1->FieldByName("name_surname")->AsString) {
					ADOTable1->Next();
				}
		Image2->Picture->LoadFromFile(ExtractFilePath(ParamStr(0))+ADOTable1->FieldByName("img")->AsString);
		RichEdit1->Lines->LoadFromFile(ExtractFilePath(ParamStr(0))+ADOTable1->FieldByName("information")->AsString);
Label1->Caption=ExtractFilePath(ParamStr(0));
Label3->Caption=ExtractFilePath( ParamStr(0))+ADOTable1->FieldByName("information")->AsString;

		}
//---------------------------------------------------------------------------



void __fastcall TForm2::ListBox1Click(TObject *Sender)
{


	if (ListBox1->ItemIndex!=-1 ) {
		ADOTable1->First();
		String surname = ListBox1->Items->Strings[ListBox1->ItemIndex];
		String surname2="";
		int k=0;

				while (surname!=ADOTable1->FieldByName("name_surname")->AsString) {
					ADOTable1->Next();
				}
			Image2->Picture->LoadFromFile(Label1->Caption+ADOTable1->FieldByName("img")->AsString);
			RichEdit1->Lines->LoadFromFile(Label1->Caption+ADOTable1->FieldByName("information")->AsString);
			Label3->Caption= Label1->Caption+ADOTable1->FieldByName("information")->AsString;
		  //	DBText2->Visible=false;

			{     /*

				ADOTable2->First();
				for (int j = 1; j <= 6; j++) {
					//дундук! строки начинай нумеровать с 1!!! Запомни и узнай почему так
					if (surname[j]==' ') {
						k=1;
					}
				}
					if (k==1)
					{
						for (int i = 7; i <= surname.Length(); i++) {
							surname2 +=surname[i];
						}
					}
				while (surname2!=ADOTable2->FieldByName("namee")->AsString)
				{
					ADOTable2->Next();
				}
				 Image2->Picture->LoadFromFile(ADOTable2->FieldByName("img1")->AsString);
				 DBText1->Caption=ADOTable2->FieldByName("namee")->AsString;
				 DBText2->Visible=false;
				 RichEdit1->Lines->LoadFromFile(ADOTable2->FieldByName("information")->AsString);
			*/
			};

	}

}




//---------------------------------------------------------------------------



void __fastcall TForm2::Image3Click(TObject *Sender)
{
	Form4->Show();
	Form2->Hide();

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Panel5Click(TObject *Sender)
{
 //   Panel2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image4Click(TObject *Sender)
{
    Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
String z;
int h =0;
if (Edit1->Text.Length()>0) {
ADOTable1->Filtered=false;
RichEdit1->Visible=true;
Image2->Visible=true;
z=Edit1->Text;
ADOTable1->Filter = "name_surname LIKE '" + z +'%' +"'";
ADOTable1->Filtered=true;
if (ADOTable1->RecordCount>0) {
Image2->Picture->LoadFromFile(ADOTable1->FieldByName("img")->AsString);
RichEdit1->Lines->LoadFromFile(ADOTable1->FieldByName("information")->AsString);

}else{RichEdit1->Visible=false;
Image2->Visible=false;}

}else
{ADOTable1->Filtered=false;
Image2->Visible=true;
RichEdit1->Visible=true;
ADOTable1->First();
Image2->Picture->LoadFromFile(ADOTable1->FieldByName("img")->AsString);
RichEdit1->Lines->LoadFromFile(ADOTable1->FieldByName("information")->AsString);}

ListBox1->Clear();
int id;
ADOTable1->First();


for (int i = 1; i <= ADOTable1->RecordCount; i++) {
	ListBox1->Items->Add(ADOTable1->FieldByName("name_surname")->AsString);
	id = ADOTable1->FieldByName("id")->AsInteger;

	for (int f = 1; f <=ADOTable2->RecordCount; f++) {
		if (id==ADOTable2->FieldByName("id_authors")->AsInteger) {
			ListBox1->Items->Add("      " + ADOTable2->FieldByName("namee")->AsString );
			ADOTable2->Next();
		}
		else {
			 ADOTable2->Next();};
	}

	ADOTable2->First();
	ADOTable1->Next();

}
if (ListBox1->ItemIndex!=-1) {

ListBox1->ItemIndex=0;
ADOTable1->First();
		String surname = ListBox1->Items->Strings[ListBox1->ItemIndex];
			if (surname[1] != ' ' & surname[2] != ' ') {
				while (surname!=ADOTable1->FieldByName("name_surname")->AsString) {
					ADOTable1->Next();
				}

			}

		Image2->Picture->LoadFromFile(ADOTable1->FieldByName("img")->AsString);
		RichEdit1->Lines->LoadFromFile(ADOTable1->FieldByName("information")->AsString);

 }

 }
//---------------------------------------------------------------------------


void __fastcall TForm2::Image2Click(TObject *Sender)
{
DoubleBuffered=true;//мерцание
Timer1->Enabled=true;
if (Image2->Height==435) {
Label2->Caption=1;
}
if (Image2->Height==145) {
Label2->Caption=2;
RichEdit1->Visible=false;

}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
if (Label2->Caption==1)
  {	Image2->Height-=5;
	Image2->Width-=5;
	if (Image2->Height==145) {
	Timer1->Enabled=false;
	}
}

if (Label2->Caption==2)
  {	Image2->Height+=5;
	Image2->Width+=5;
	if (Image2->Height==435) {
	Timer1->Enabled=false;
	}
	 }
if (Image2->Height==145) {RichEdit1->Visible=true;}


}

//---------------------------------------------------------------------------





void __fastcall TForm2::Image6Click(TObject *Sender)
{
String place;
if (OpenDialog1->Execute()==true) {
	place=OpenDialog1->FileName;
	Memo1->Lines->Add(place);
	Memo1->Lines->SaveToFile("informaton\\baza.txt");
	Memo1->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image5Click(TObject *Sender)
{
    //Panel2->Visible=false;
	Form4->Show();
	Form2->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image10Click(TObject *Sender)
{
String place;
if (OpenDialog1->Execute()==true) {
	place=OpenDialog1->FileName;
	Memo1->Lines->Add(place);
	Memo1->Lines->SaveToFile("informaton\\baza.txt");
	Memo1->Clear();
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Image9Click(TObject *Sender)
{
int ans= MessageBoxA(NULL,"Вы уверены, что хотите это удалить?","Внимание",MB_YESNO);
if (ans==6) {
	ADOTable1->Delete();
	MessageBoxA(NULL,"Удалено","Внимание",MB_OK);
ListBox1->Clear();
        ADOTable1->First();
Memo1->Lines->LoadFromFile("informaton\\baza.txt");
String place = Memo1->Lines->Strings[0];
ADOConnection1->Connected=true;
ADOTable1->Active=true;

ADOTable2->Active=true;
int id;
for (int i = 1; i <= ADOTable1->RecordCount; i++) {
	ListBox1->Items->Add(ADOTable1->FieldByName("name_surname")->AsString);
	id = ADOTable1->FieldByName("id")->AsInteger;


	ADOTable2->First();
	ADOTable1->Next();
}

ListBox1->ItemIndex=0;
ADOTable1->First();

		String surname = ListBox1->Items->Strings[ListBox1->ItemIndex];
				while (surname!=ADOTable1->FieldByName("name_surname")->AsString) {
					ADOTable1->Next();
				}
		Image2->Picture->LoadFromFile(ExtractFilePath(ParamStr(0))+ADOTable1->FieldByName("img")->AsString);
		RichEdit1->Lines->LoadFromFile(ExtractFilePath(ParamStr(0))+ADOTable1->FieldByName("information")->AsString);

		}
else
{

}

}



//---------------------------------------------------------------------------

void __fastcall TForm2::Image8Click(TObject *Sender)
{
	Image7->Visible=true;
	Image8->Visible=false;
	RichEdit1->Color=clActiveCaption;
	RichEdit1->ReadOnly=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image7Click(TObject *Sender)
{
	RichEdit1->ReadOnly=true;
	RichEdit1->Lines->SaveToFile(Label3->Caption);
	RichEdit1->Color=clMoneyGreen;
	Image8->Visible=true;
	Image7->Visible=false;
}
//---------------------------------------------------------------------------

