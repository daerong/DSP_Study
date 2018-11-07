
// FourierSeriesView.cpp: CFourierSeriesView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "FourierSeries.h"
#endif

#include "FourierSeriesDoc.h"
#include "FourierSeriesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFourierSeriesView

IMPLEMENT_DYNCREATE(CFourierSeriesView, CView)

BEGIN_MESSAGE_MAP(CFourierSeriesView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FOURIERSERIES, &CFourierSeriesView::OnFourierseries)
	ON_COMMAND(ID_FOURIERCAL, &CFourierSeriesView::OnFouriercal)
END_MESSAGE_MAP()

// CFourierSeriesView 생성/소멸

CFourierSeriesView::CFourierSeriesView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFourierSeriesView::~CFourierSeriesView()
{
}

BOOL CFourierSeriesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFourierSeriesView 그리기

void CFourierSeriesView::OnDraw(CDC* /*pDC*/)
{
	CFourierSeriesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFourierSeriesView 인쇄

BOOL CFourierSeriesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFourierSeriesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFourierSeriesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFourierSeriesView 진단

#ifdef _DEBUG
void CFourierSeriesView::AssertValid() const
{
	CView::AssertValid();
}

void CFourierSeriesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFourierSeriesDoc* CFourierSeriesView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFourierSeriesDoc)));
	return (CFourierSeriesDoc*)m_pDocument;
}
#endif //_DEBUG


// CFourierSeriesView 메시지 처리기


void CFourierSeriesView::OnFourierseries()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CFourierSeriesView::OnFouriercal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
