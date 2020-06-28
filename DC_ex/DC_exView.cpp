
// DC_exView.cpp : CDC_exView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DC_ex.h"
#endif

#include "DC_exDoc.h"
#include "DC_exView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDC_exView

IMPLEMENT_DYNCREATE(CDC_exView, CView)

BEGIN_MESSAGE_MAP(CDC_exView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDC_exView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDC_exView ����/����

CDC_exView::CDC_exView()
{
	// TODO: �ڴ˴���ӹ������

}

CDC_exView::~CDC_exView()
{
}

BOOL CDC_exView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDC_exView ����

void CDC_exView::OnDraw(CDC* pDC)
{
	CDC_exDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int y = 50;
	for(int nIndex = 0; nIndex <pDoc->GetAllRecNum(); nIndex++) 
	{
		pDoc->GetStudentAt(nIndex)->Display(y ,pDC); 
		y += 16;
	}
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDC_exView ��ӡ


void CDC_exView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDC_exView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDC_exView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDC_exView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CDC_exView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDC_exView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDC_exView ���

#ifdef _DEBUG
void CDC_exView::AssertValid() const
{
	CView::AssertValid();
}

void CDC_exView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDC_exDoc* CDC_exView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDC_exDoc)));
	return (CDC_exDoc*)m_pDocument;
}
#endif //_DEBUG


// CDC_exView ��Ϣ�������
