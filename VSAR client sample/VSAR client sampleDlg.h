
// VSAR client sampleDlg.h : 헤더 파일
//

#pragma once
#include "gVSAR.h"
#include <thread>

#define _SLEEP_SECONDS		1
#define _VSAR_TIMER			1

#pragma comment(lib, "C:\\VSAR\\lib\\gLogger.lib")
#pragma comment(lib, "C:\\VSAR\\lib\\gThreadpool.lib")
#pragma comment(lib, "C:\\VSAR\\lib\\gVSAR.lib")

// CVSARclientsampleDlg 대화 상자
class CVSARclientsampleDlg : public CDialogEx
{
private:
	gVSAR m_vsar;

	bool m_isRepeat;
	bool m_isDestroy;
	std::thread *m_thread;

// 생성입니다.
public:
	CVSARclientsampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VSARCLIENTSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
