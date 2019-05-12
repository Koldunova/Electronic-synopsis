//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Project1PCH1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image1Click(TObject *Sender)
{
 if (OpenPictureDialog1->Execute()==true) {
	Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	Label3->Caption='1';
	Image2->Visible=true;
 }

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image3Click(TObject *Sender)
{
if (OpenTextFileDialog1->Execute()==true) {
	RichEdit1->Lines->LoadFromFile(OpenTextFileDialog1->FileName);
	Label4->Caption='1';
}

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image6Click(TObject *Sender)
{
 if (Edit1->Text!="" && Edit2->Text!="" && Label3->Caption==1 && Label4->Caption==1) {
	 //сохранение в имг и инф
	 Image2->Picture->SaveToFile(ExtractFilePath(ParamStr(0))+"img\\"+Edit1->Text+".bmp");
	 RichEdit1->Lines->SaveToFile(ExtractFilePath(ParamStr(0))+"informaton\\"+Edit1->Text+".rtf");
	 // загрузка в базу
	 Form2->ADOTable1->Insert();
	 Form2->ADOTable1->FieldByName("name_surname")->AsString=Edit1->Text;
	 Form2->ADOTable1->FieldByName("img")->AsString="img\\"+Edit1->Text+".bmp";
	 Form2->ADOTable1->FieldByName("ddmmyy")->AsString=Edit2->Text;
	 Form2->ADOTable1->FieldByName("information")->AsString="informaton\\"+Edit1->Text+".rtf";

	 //очистка
	 Edit1->Clear();
	 Edit2->Clear();
	 RichEdit1->Clear();
	 Image2->Visible=false;
	 Label3->Caption='0';
	 Label4->Caption='0';
 }
 else
 {
  ShowMessage("Вы что то забыли");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image5Click(TObject *Sender)
{

Form2->ListBox1->Clear();
Form2->Memo1->Lines->LoadFromFile(Form2->Label1->Caption+"informaton\\baza.txt");
String place = Form2->Memo1->Lines->Strings[0];
Form2->ADOConnection1->Connected=true;
Form2->ADOTable1->Active=true;
Form2->ADOTable2->Active=true;
int id;
Form2->ADOTable1->First();
for (int i = 1; i <= Form2->ADOTable1->RecordCount; i++) {
	Form2->ListBox1->Items->Add(Form2->ADOTable1->FieldByName("name_surname")->AsString);
	id = Form2->ADOTable1->FieldByName("id")->AsInteger;

	Form2->ADOTable1->Next();
}
Form2->ListBox1->ItemIndex=0;
Form2->ADOTable1->First();
Form2->ADOTable1->Refresh();
		String surname = Form2->ListBox1->Items->Strings[Form2->ListBox1->ItemIndex];

				while (surname!=Form2->ADOTable1->FieldByName("name_surname")->AsString) {
					Form2->ADOTable1->Next();
				}



		Form2->Image2->Picture->LoadFromFile(Form2->Label1->Caption+Form2->ADOTable1->FieldByName("img")->AsString);
		Form2->RichEdit1->Lines->LoadFromFile(Form2->Label1->Caption+Form2->ADOTable1->FieldByName("information")->AsString);

	Form4->Hide() ;
	Form2->Show();
}

//---------------------------------------------------------------------------


void __fastcall TForm4::FormCreate(TObject *Sender)
{
	Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
Form2->Close();
Form4->Close();
}
//---------------------------------------------------------------------------

