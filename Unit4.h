//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TEdit *Edit1;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit2;
	TImage *Image1;
	TImage *Image2;
	TRichEdit *RichEdit1;
	TImage *Image3;
	TOpenPictureDialog *OpenPictureDialog1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TImage *Image5;
	TImage *Image6;
	TButton *Button1;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
