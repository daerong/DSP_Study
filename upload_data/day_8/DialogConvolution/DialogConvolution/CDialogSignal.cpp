// CDialogSignal.cpp: 구현 파일
//

#include "stdafx.h"
#include "DialogConvolution.h"
#include "CDialogSignal.h"
#include "afxdialogex.h"


// CDialogSignal 대화 상자

IMPLEMENT_DYNAMIC(CDialogSignal, CDialog)

CDialogSignal::CDialogSignal(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SIGSET, pParent)
{

}

CDialogSignal::~CDialogSignal()
{
}

void CDialogSignal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogSignal, CDialog)
END_MESSAGE_MAP()


// CDialogSignal 메시지 처리기
