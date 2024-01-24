
// MyCalcDlg.cpp: uygulama dosyası
//

#include "pch.h"
#include "framework.h"
#include "MyCalc.h"
#include "MyCalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Uygulamanın Hakkında bölümü için kullanılan CAboutDlg iletişim kutusu

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// İletişim Kutusu Verileri
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV desteği

// Uygulama
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyCalcDlg iletişim kutusu



CMyCalcDlg::CMyCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYCALC_DIALOG, pParent)
	, e_result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	number1 = number2 = number0 =0;
	str1 = _T("");
	str2 = _T("");
	opera = 0;
}

void CMyCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E1, e_result);
}

BEGIN_MESSAGE_MAP(CMyCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_EDIT1, &CMyCalcDlg::OnEnChangeEdit1)
	
	ON_BN_CLICKED(IDC_B1, &CMyCalcDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CMyCalcDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CMyCalcDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CMyCalcDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CMyCalcDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CMyCalcDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CMyCalcDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CMyCalcDlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CMyCalcDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_BUTTON11, &CMyCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMyCalcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CMyCalcDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMyCalcDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON14, &CMyCalcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CMyCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CMyCalcDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyCalcDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMyCalcDlg ileti işleyicileri

BOOL CMyCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Sistem menüsüne "Hakkında..." menü öğesini ekleyin.

	// IDM_ABOUTBOX, sistem komutu aralığında olmalıdır.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Bu iletişim kutusu için simgeyi ayarlayın. Uygulamanın ana penceresi,
	//  iletişim kutusu olmadığında çerçeve bunu otomatik olarak yapar
	SetIcon(m_hIcon, TRUE);			// Büyük simge ayarla
	SetIcon(m_hIcon, FALSE);		// Küçük simge ayarla

	// TODO: Buraya ek başlatma işlemlerini ekleyin

	return TRUE;  // Odağı bir denetime ayarlamadığınız sürece TRUE döndürün
}

void CMyCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// İletişim kutunuza bir simge durumuna küçültme düğmesi eklerseniz, simgeyi çizmek için
//  aşağıdaki kod gerekir. Belge/görünüm modelini kullanan MFC uygulamaları için bu,
//  çerçeve tarafından sizin için otomatik olarak yapılır.

void CMyCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // boyama için cihaz bağlamı

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Simgeyi istemci dikdörtgeni içinde ortalayın
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Simgeyi çizin
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Sistem, kullanıcı simge durumuna küçültülmüş pencereyi sürüklerken görüntülenecek imleci
//  elde etmek için bu işlevi çağırır.
HCURSOR CMyCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}








void CMyCalcDlg::OnBnClickedB1()
{
	// TODO:Kontrol bildirimi işleyicinizin kodunu buraya ekleyin
	if (flag == true)
	{
		str1 += _T("1");
		e_result = str1;
		

	}
	else
	{
		str2 += _T("1");
		e_result = str2;
		
	}
	UpdateData(FALSE);
	
}


void CMyCalcDlg::OnBnClickedB2()
{
	if (flag == true)
	{
		str1 += _T("2");
		e_result = str1;
		
	}
	else {
		str2 += _T("2");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB3()
{
	if (flag == true)
	{
		str1 += _T("3");
		e_result = str1;
		
	}
	else {
		str2 += _T("3");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB4()
{
	if (flag == true)
	{
		str1 += _T("4");
		e_result = str1;
		
	}
	else {
		str2 += _T("4");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB5()
{
	if (flag == true)
	{
		str1 += _T("5");
		e_result = str1;
		
	}
	else {
		str2 += _T("5");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB6()
{
	if (flag == true)
	{
		str1 += _T("6");
		e_result = str1;
		
	}
	else {
		str2 += _T("6");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB7()
{
	if (flag == true)
	{
		str1 += _T("7");
		e_result = str1;
		
	}
	else {
		str2 += _T("7");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB8()
{
	if (flag == true)
	{
		str1 += _T("8");
		e_result = str1;
		
	}
	else {
		str2 += _T("8");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedB9()
{
	if (flag == true)
	{
		str1 += _T("9");
		e_result = str1;
		
	}
	else {
		str2 += _T("9");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedButton11() //0
{
	if (flag == true)
	{
		str1 += _T("0");
		e_result = str1;
		
	}
	else {
		str2 += _T("0");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedButton12()
{
	if (flag == true)
	{
		str1 += _T(".");
		e_result = str1;
		
	}
	else {
		str2 += _T(".");
		e_result = str2;
		
	}
	UpdateData(FALSE);
}


void CMyCalcDlg::OnBnClickedButton15() //+
{
	if (e_result != _T(""))
	{
		number1 = _ttof(e_result);
		flag = !flag;
		e_result = _T("");
		opera = 1;
		UpdateData(FALSE);
	}
	

}


void CMyCalcDlg::OnBnClickedButton16() // -
{
	if (e_result != _T(""))
	{
		number1 = _ttof(e_result);
		flag = !flag;
		e_result = _T("");
		opera = 2;
		
	}
}


void CMyCalcDlg::OnBnClickedButton14() // *
{
	if (e_result != _T(""))
	{
		number1 = _ttof(e_result);
		flag = !flag;
		e_result = _T("");
		opera = 3;
		
	}
}




void CMyCalcDlg::OnBnClickedButton13() // /
{
	if (e_result != _T(""))
	{
		number1 = _ttof(e_result);
		flag = !flag;
		e_result = _T("");
		opera = 4;
	
	}
}


void CMyCalcDlg::OnBnClickedButton17() // =
{
	if (e_result != _T(""))
	{
		number2 = _ttof(e_result);
		flag = !flag;
		e_result = _T("");
		
	}

	if (opera == 1)
	{
		number0 = number1 + number2;
	}
	if (opera == 2)
	{
		number0 = number1 - number2;
	}
	if (opera == 3)
	{
		number0 = number1 * number2;
	}
	if (opera == 4)
	{
		number0 = number1 / number2;
	}
	e_result.Format(_T("%.3f"), number0);
	UpdateData(FALSE);
	str1 = _T("");
	str2 = _T("");
}


void CMyCalcDlg::OnBnClickedButton10()
{
	if (flag == true)
	{
		str1 = _T("");
		e_result = str1;

	}
	else {
		str2 = _T("");
		e_result = str2;

	}


	UpdateData(FALSE);
}
