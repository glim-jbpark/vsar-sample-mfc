
// VSAR client sampleDlg.h : ��� ����
//

#pragma once
#include "gVSAR.h"
#include <thread>

#define _SLEEP_SECONDS		1
#define _VSAR_TIMER			1

#pragma comment(lib, "C:\\VSAR\\lib\\gLogger.lib")
#pragma comment(lib, "C:\\VSAR\\lib\\gThreadpool.lib")
#pragma comment(lib, "C:\\VSAR\\lib\\gVSAR.lib")

// CVSARclientsampleDlg ��ȭ ����
class CVSARclientsampleDlg : public CDialogEx
{
private:
	gVSAR m_vsar;

	bool m_isRepeat;
	bool m_isDestroy;
	std::thread *m_thread;

// �����Դϴ�.
public:
	CVSARclientsampleDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VSARCLIENTSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnError();
	afx_msg void OnBnClickedBtnSignal();
	afx_msg void OnBnClickedBtnError5();
	afx_msg void OnBnClickedBtnSignal4();
	afx_msg void OnBnClickedBtnSignal5();
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
