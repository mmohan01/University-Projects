// MMCourseworkDlg.cpp : implementation file
//Michael Mohan 40020843

#include "stdafx.h"
#include <cmath>
#include <string.h>
#include "MMCoursework.h"
#include "MMCourseworkDlg.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
double CipherCode;
CString CipherCodeText;
double ran2(int &idnum);

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMMCourseworkDlg dialog




CMMCourseworkDlg::CMMCourseworkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMMCourseworkDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMMCourseworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMMCourseworkDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMMCourseworkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMMCourseworkDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMMCourseworkDlg message handlers

BOOL CMMCourseworkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMMCourseworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMMCourseworkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMMCourseworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//The event handler for this button encrypts the plaintext in the text box IDC_EDIT1 and puts the ciphertext in IDC_EDIT2
//This uses the XOR encryption technique which XOR's each character of the plaintext with a ciphercode
//(created using the ran2 function). The encryption key is output to IDC_EDIT3
//the ciphercode and ciphercode text are declared globally so that the text can be recovered when the decryption event handler is called
void CMMCourseworkDlg::OnBnClickedButton1()
{
	//handler pointers is created to access the contents of the edit boxes
	//CString variables are created to store the values for these text boxes
	CWnd* CipherTextDialog = GetDlgItem(IDC_EDIT1);
	CWnd* PlainTextDialog = GetDlgItem(IDC_EDIT2);
	CWnd* CipherCodeDialog = GetDlgItem(IDC_EDIT3);
	CString PlainText;
	CString CipherText;

	//the ran2 function is called to produce a random number 
	//This is converted into a string and becomes the encryption key
	int seed = 0;
	//CipherCode = ran2(seed); only seems to give the number -3.1 no matter what
	CipherCode = rand() % 1000;
	CipherCodeText.Format("%1.0f", CipherCode);
	PlainTextDialog->GetWindowText(PlainText);

	//if no text has been entered then the user is prompted to enter some text
	if (PlainText == "")
	{
		PlainText = "You must enter some text before it can be encrypted!";
		PlainTextDialog->SetWindowText(PlainText);
	}
	//if text has been entered, the encryption is performed
	else
	{
		//the ciphertext is made equal to the plaintext so the length of the text can be known
		//variables are declared to use as counters in a for loop
		CipherText = PlainText;
		int i, j;

		//the encrytion itself takes place in this for loop
		//the characters of the plaintext are looped through and XOR'd with the characters of the encryption key
		//the result of this this placed as the ciphertext
		for (i = 0, j = 0; i < strlen(CipherText); i++, j++)
		{
			//the XOR operation is performed
			//CipherText[i] = PlainText[i] ^ CipherCodeText[i - reset]; produces an error for some reason
			CipherText.SetAt(i, PlainText.GetAt(i) ^ CipherCodeText.GetAt(j)); 

			//if the ciphercode has reached the last character, the ciphercode is reset to the first character
			if (j == strlen(CipherCodeText) - 1)
				j = 0;
		}

		//the plaintext is changed to display the word "Encrypted"
		PlainText = "Encrypted";
		PlainTextDialog->SetWindowText(PlainText);
		
		//the ciphertext and ciphercode is output onto their respective text boxes	
		CipherTextDialog->SetWindowText(CipherText);
		CipherCodeDialog->SetWindowText(CipherCodeText);
	}
	
}

//The event handler for this button decryptd the ciphertext in the text box IDC_EDIT2 and puts the plaintext in IDC_EDIT1
//This uses the XOR encryption technique which XOR's each character of the ciphertext with a ciphercode to recover the plaintext
void CMMCourseworkDlg::OnBnClickedButton2()
{
	//handler pointers is created to access the contents of the edit boxes
	//CString variables are created to store the values for these text boxes
	CWnd* CipherTextDialog = GetDlgItem(IDC_EDIT1);
	CWnd* PlainTextDialog = GetDlgItem(IDC_EDIT2);
	CWnd* CipherCodeDialog = GetDlgItem(IDC_EDIT3);
	CString PlainText;
	CString CipherText;
	CipherTextDialog->GetWindowText(CipherText);
	
	//if no ciphercode has been entered then the user is prompted to enter one
	if (CipherCodeText == "")
	{
		CipherCodeText = "You must enter the encryption key to decrypt the ciphertext";
		CipherCodeDialog->SetWindowText(CipherCodeText);
	}
	//code to stop the program failing if the decrypt button is hit more than once
	//The code wouldn't compile although it seemed ok to me
	/*else if ((strcmp(CipherText, "Decrypted") = 0)||(strcmp (CipherText, "This string has already been decrypted") = 0))
	{
		CipherText = "This string has already been decrypted";
		CipherTextDialog->SetWindowText(CipherText);
	}*/
	//if the ciphercode has been entered, the decryption is performed
	else
	{
		//the plaintext is made equal to the ciphertext so the length of the text can be known
		//variables are declared to use as counters in a for loop
		PlainText = CipherText;
		int i, j;

		//the decrytion itself takes place in this for loop
		//the characters of the ciphertext are looped through and XOR'd with the characters of the encryption key
		//the result is the original plaintext and this is placed in the plaintext variable
		for (i = 0, j = 0; i < strlen(PlainText); i++, j++)
		{
			//The XOR operation is performed
			PlainText.SetAt(i, CipherText.GetAt(i) ^ CipherCodeText.GetAt(j)); 

			//if the ciphercode has reached the last character, the ciphercode is reset to the first character
			if (j == strlen(CipherCodeText) - 1)
				j = 0;
		}

		//the ciphertext is changed to display the word "decrypted"
		CipherText = "Decrypted";
		CipherTextDialog->SetWindowText(CipherText);

		//the decrypted plaintext is output onto its respective text box
		PlainTextDialog->SetWindowText(PlainText);
	}

	
}

double ran2(int &idnum)
{
	const int IM1 = 2147483563, IM2 = 2147483399;
	const int IA1 = 40014, IA2 = 40692, IQ1 = 53668, IQ2 = 52774;
	const int IR1 = 12211, IR2 = 3791, NTAB = 32, IMM1 = IM1 - 1;
	const int NDIV = 1 + IMM1/NTAB;
	const double EPS = exp(3.0) - 16, RNMX = 1.0 - EPS, AM = 1.0/(double)(IM1);
	static int idnum2 = 123456789, iy = 0;
	static int iv[NTAB];
	int j, k;
	double temp;

	if (idnum <= 0)
	{
		idnum = (idnum == 0 ? 1 : -idnum);
		idnum2 = idnum;

		for (j = NTAB + 7; j >= 0; j--)
		{
			k = idnum/IQ1;
			idnum = IA1 * (idnum - k * IQ1) - k * IR1;
			if (idnum < 0) idnum += IM1;
			if (j < NTAB) iv[j] = idnum;
		}

		iy = iv[0];
	}

	k = idnum/IQ1;
	idnum = IA1 * (idnum - k * IQ1) - k * IR1;
	if (idnum<0) idnum += IM1;
	k = idnum2/IQ2;
	idnum2 = IA2 * (idnum2 - k * IQ2) - k * IR2;
	if (idnum2 < 0) idnum2 += IM2;
	j = iy / NDIV;
	iy = iv[j] - idnum2;
	iv[j] = idnum;
	if (iy < 1) iy += IMM1;
	if ((temp = AM * iy) > RNMX) return RNMX;
	else return temp;
}