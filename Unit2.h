//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TDBText *DBText1;
	TADOTable *ADOTable2;
	TADOTable *ADOTable1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TRichEdit *RichEdit1;
	TListBox *ListBox1;
	TPanel *Panel1;
	TDBText *DBText2;
	TImage *Image3;
	TImage *Image4;
	TEdit *Edit1;
	TTimer *Timer1;
	TLabel *Label2;
	TImage *Image2;
	TOpenDialog *OpenDialog1;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TLabel *Label1;
	TMemo *Memo1;
	TLabel *Label3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Panel5Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
