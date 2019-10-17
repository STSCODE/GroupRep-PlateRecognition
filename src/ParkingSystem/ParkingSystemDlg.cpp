
// ParkingSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ParkingSystem.h"
#include "ParkingSystemDlg.h"
#include "afxdialogex.h"
#include "ShowInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace pdflib;
using namespace std;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CParkingSystemDlg �Ի���



CParkingSystemDlg::CParkingSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PARKINGSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParkingSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER_START, m_Data_Start);
	DDX_Control(pDX, IDC_DATETIMEPICKER_END, m_Data_End);
}

BEGIN_MESSAGE_MAP(CParkingSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CParkingSystemDlg::OnBnClickedOutputToPdfBtn)
	ON_BN_CLICKED(IDC_BUTTON2, &CParkingSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_CARNUM, &CParkingSystemDlg::OnBnClickedButtonCarnum)
	ON_BN_CLICKED(IDC_BUTTON_CARMONEY, &CParkingSystemDlg::OnBnClickedButtonCarmoney)
END_MESSAGE_MAP()


// CParkingSystemDlg ��Ϣ�������

BOOL CParkingSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CParkingSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CParkingSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CParkingSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CParkingSystemDlg::OnBnClickedOutputToPdfBtn()
{
	try {
		/*  This is where the data files are. Adjust as necessary. */
		const wstring searchpath = L"../data";

		PDFlib p;
		const wstring imagefile = L"nesrin.jpg";
		int image;

		wostringstream optlist;

		//  This means we must check return values of load_font() etc.
		p.set_option(L"errorpolicy=return");

		// Set the search path for fonts and PDF files
		optlist.str(L"");
		optlist << L"searchpath={{" << searchpath << L"}}";
		p.set_option(optlist.str());

		if (p.begin_document(L"starter_basic.pdf", L"") == -1)
		{
			wcerr << L"Error: " << p.get_errmsg() << endl;
			return;
		}

		p.set_info(L"Creator", L"PDFlib starter sample");
		p.set_info(L"Title", L"starter_basic");

		/* We load the image before the first page, and use it
		* on all pages
		*/
		image = p.load_image(L"auto", imagefile, L"");

		if (image == -1)
		{
			wcerr << L"Error: " << p.get_errmsg() << endl;
			return;
		}

		/*  Page 1 */
		p.begin_page_ext(0, 0, L"width=a4.width height=a4.height");
		/* use NotoSerif-Regular font and unicode encoding for placing the text
		* and demonstrate various options how to pass the unicode text to PDFlib
		*/
		optlist.str(L"");
		optlist.str(L"fontname={NotoSerif-Regular} encoding=unicode embedding fontsize=24");

		/* using plain 7 bit ASCII text */
		p.fit_textline(L"en: Hello!", 50, 700, optlist.str());
		/* using unicode escapes */
		p.fit_textline(L"gr: \u0393\u03B5\u03B9\u03AC!", 50, 650, optlist.str());
		p.fit_textline(L"ru: \u041F\u0440\u0438\u0432\u0435\u0442!", 50, 600, optlist.str());
		/* using PDFlib's character references */
		optlist << optlist.str() << L" charref=true";
		p.fit_textline(L"es: &#xA1;Hola!", 50, 550, optlist.str());


		p.fit_image(image, 0.0, 0.0, L"scale=0.25");

		p.end_page_ext(L"");

		/*  Page 2 */
		p.begin_page_ext(0, 0, L"width=a4.width height=a4.height");

		/*  red rectangle */
		p.setcolor(L"fill", L"rgb", 1.0, 0.0, 0.0, 0.0);
		p.rect(200, 200, 250, 150);
		p.fill();

		/*  blue circle */
		p.setcolor(L"fill", L"rgb", 0.0, 0.0, 1.0, 0.0);
		p.arc(400, 600, 100, 0, 360);
		p.fill();

		/*  thick gray line */
		p.setcolor(L"stroke", L"gray", 0.5, 0.0, 0.0, 0.0);
		p.setlinewidth(10);
		p.moveto(100, 500);
		p.lineto(300, 700);
		p.stroke();

		/*  Using the same image handle means the data will be copied
		to the PDF only once, which saves space.
		*/
		p.fit_image(image, 150.0, 25.0, L"scale=0.25");
		p.end_page_ext(L"");

		/*  Page 3 */
		p.begin_page_ext(0, 0, L"width=a4.width height=a4.height");

		/*  Fit the image to a box of predefined size (without distortion) */
		optlist.str(L"boxsize={400 400} position={center} fitmethod=meet");

		p.fit_image(image, 100, 200, optlist.str());

		p.end_page_ext(L"");

		p.close_image(image);
		p.end_document(L"");


		MessageBox(L"�ɹ�", L"�ɹ��������ݵ�pdf�ļ�", NULL);
	}
	catch (PDFlib::Exception &ex)
	{
		//wcerr << L"PDFlib exception occurred:" << endl
		//	<< L"[" << ex.get_errnum() << L"] " << ex.get_apiname()
		//	<< L": " << ex.get_errmsg() << endl;
		return;
	}
	catch (exception &e)
	{
		//cerr << "C++ exception occurred: " << e.what() << endl;
		return;
	}
	catch (...)
	{
		//cerr << "Generic C++ exception occurred!" << endl;
		return;
	}
}




//��ѯͣ������
void CParkingSystemDlg::OnBnClickedButtonCarnum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���ͣ������ʱ��
	CTime m_DateStart;
	m_Data_Start.GetTime(m_DateStart);
	int year = m_DateStart.GetYear();
	int month = m_DateStart.GetMonth();
	int day = m_DateStart.GetDay();

	CTime m_DateEnd;
	m_Data_End.GetTime(m_DateEnd);
	int year2 = m_DateEnd.GetYear();
	int month2 = m_DateEnd.GetMonth();
	int day2 = m_DateEnd.GetDay();

	char* result = 0;

	CarNumQuery(year, month, day, year2, month2, day2, result);

	int num = MultiByteToWideChar(0, 0, result, -1, NULL, 0);
	wchar_t *wide = new wchar_t[num];
	MultiByteToWideChar(0, 0, result, -1, wide, num);

	GetDlgItem(IDC_EDIT_CARNUM)->SetWindowText(wide);
	UpdateData(FALSE);
}

//��ѯͣ������
void CParkingSystemDlg::OnBnClickedButtonCarmoney()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CTime m_DateStart;
	m_Data_Start.GetTime(m_DateStart);
	int year = m_DateStart.GetYear();
	int month = m_DateStart.GetMonth();
	int day = m_DateStart.GetDay();

	CTime m_DateEnd;
	m_Data_End.GetTime(m_DateEnd);
	int year2 = m_DateEnd.GetYear();
	int month2 = m_DateEnd.GetMonth();
	int day2 = m_DateEnd.GetDay();

	char* result = 0;

	CarMoneyQuery(year, month, day, year2, month2, day2, result);

	int num = MultiByteToWideChar(0, 0, result, -1, NULL, 0);
	wchar_t *wide = new wchar_t[num];
	MultiByteToWideChar(0, 0, result, -1, wide, num);

	GetDlgItem(IDC_EDIT_CARMONEY)->SetWindowText(wide);
	UpdateData(FALSE);
}


void CParkingSystemDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CShowInfo  *pDlg = new CShowInfo;
	pDlg->Create(IDD_Show_Dio, this);
	pDlg->ShowWindow(SW_SHOW);
}
