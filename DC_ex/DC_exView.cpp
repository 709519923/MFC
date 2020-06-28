
// DC_exView.cpp : CDC_exView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDC_exView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDC_exView 构造/析构

CDC_exView::CDC_exView()
{
	// TODO: 在此处添加构造代码

}

CDC_exView::~CDC_exView()
{
}

BOOL CDC_exView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDC_exView 绘制

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

	// TODO: 在此处为本机数据添加绘制代码
}


// CDC_exView 打印


void CDC_exView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDC_exView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDC_exView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDC_exView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CDC_exView 诊断

#ifdef _DEBUG
void CDC_exView::AssertValid() const
{
	CView::AssertValid();
}

void CDC_exView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDC_exDoc* CDC_exView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDC_exDoc)));
	return (CDC_exDoc*)m_pDocument;
}
#endif //_DEBUG


// CDC_exView 消息处理程序
