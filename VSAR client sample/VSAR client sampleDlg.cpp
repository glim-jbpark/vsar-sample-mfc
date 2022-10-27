
// VSAR client sampleDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "VSAR client sample.h"
#include "VSAR client sampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CVSARclientsampleDlg ��ȭ ����



CVSARclientsampleDlg::CVSARclientsampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VSARCLIENTSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_isDestroy = false;
	m_isRepeat = false;
	m_thread = nullptr;

	// TODO: 05: repeat thread
	m_thread = new std::thread([this]() {
		while (!m_isDestroy)
		{
			sleep(500);
			while (m_isRepeat)
			{
				m_vsar.signal("repeat signal", GVSAR_ALERT);

				sleep(1000 * _SLEEP_SECONDS);
			}
		}
	});
}

void CVSARclientsampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVSARclientsampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_ERROR, &CVSARclientsampleDlg::OnBnClickedBtnError)
	ON_BN_CLICKED(IDC_BTN_SIGNAL, &CVSARclientsampleDlg::OnBnClickedBtnSignal)
	ON_BN_CLICKED(IDC_BTN_ERROR5, &CVSARclientsampleDlg::OnBnClickedBtnError5)
	ON_BN_CLICKED(IDC_BTN_SIGNAL4, &CVSARclientsampleDlg::OnBnClickedBtnSignal4)
	ON_BN_CLICKED(IDC_BTN_SIGNAL5, &CVSARclientsampleDlg::OnBnClickedBtnSignal5)
	ON_BN_CLICKED(IDC_BTN_START, &CVSARclientsampleDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CVSARclientsampleDlg::OnBnClickedBtnStop)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CVSARclientsampleDlg �޽��� ó����

BOOL CVSARclientsampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CVSARclientsampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CVSARclientsampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CVSARclientsampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CVSARclientsampleDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	/* 
		TODO: 99: exit application

		1. kill thread
		2. stop vsar
	*/

	// 1. kill thread
	m_isDestroy = true;
	m_isRepeat = false;
	m_thread->join();
	if (m_thread != nullptr)
	{
		delete m_thread;
		m_thread = nullptr;
	}

	// 2. stop vsar
	m_vsar.stop();
}

void CVSARclientsampleDlg::OnBnClickedBtnError()
{
	/* 
		TODO: 06: I/O Error
		�ش� �ַ��� Vision system���� üũ�� �� ����
		���� VSAR�� restart signal ����
	*/
	m_vsar.signal("IO Error", GVSAR_RESTART);
}

void CVSARclientsampleDlg::OnBnClickedBtnError5()
{
	/*
		TODO: 10: Memory Error

		access to nullptr
	*/
	unsigned char *buffer = nullptr;
	*buffer = 'a';
}

void CVSARclientsampleDlg::OnBnClickedBtnSignal()
{
	// TODO: 01: Signal "Process"

	m_vsar.signal("process");
}

void CVSARclientsampleDlg::OnBnClickedBtnSignal4()
{
	// TODO: 02: Start repeat

	SetTimer(_VSAR_TIMER, 500, NULL);
	
}

void CVSARclientsampleDlg::OnBnClickedBtnSignal5()
{
	/*
		TODO: 03: Stop repeat
	*/
	
	KillTimer(_VSAR_TIMER);
}


void CVSARclientsampleDlg::OnBnClickedBtnStart()
{

	// TODO: 00: m_vsar start
	m_vsar.start();
}


void CVSARclientsampleDlg::OnBnClickedBtnStop()
{
	// TODO: 11: m_vsar stop
	m_vsar.stop();
}

void CVSARclientsampleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	static unsigned long long index = 0;
	if (nIDEvent == _VSAR_TIMER)
	{
		m_vsar.signal("index " + std::to_string(index++));
	}

	CDialogEx::OnTimer(nIDEvent);
}
