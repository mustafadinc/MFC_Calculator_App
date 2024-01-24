
// MyCalcDlg.h: üst bilgi dosyası
//

#pragma once


// CMyCalcDlg iletişim kutusu
class CMyCalcDlg : public CDialogEx
{
// Oluşturma
public:
	CMyCalcDlg(CWnd* pParent = nullptr);	// standart oluşturucu

// İletişim Kutusu Verileri
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYCALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV desteği


// Uygulama
protected:
	HICON m_hIcon;

public:
	float number1, number2 ,number0;
	CString str1, str2; 
	bool flag = true;
	int opera;
	// Oluşturulan ileti eşlemesi işlevleri
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString e_result;
	
	
	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton10();
};

