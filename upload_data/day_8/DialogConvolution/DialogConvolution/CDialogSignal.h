#pragma once


// CDialogSignal 대화 상자

class CDialogSignal : public CDialog
{
	DECLARE_DYNAMIC(CDialogSignal)

public:
	CDialogSignal(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialogSignal();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGSET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
