
// DC_exView.h : CDC_exView 类的接口
//

#pragma once


class CDC_exView : public CView
{
protected: // 仅从序列化创建
	CDC_exView();
	DECLARE_DYNCREATE(CDC_exView)

// 特性
public:
	CDC_exDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDC_exView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DC_exView.cpp 中的调试版本
inline CDC_exDoc* CDC_exView::GetDocument() const
   { return reinterpret_cast<CDC_exDoc*>(m_pDocument); }
#endif

