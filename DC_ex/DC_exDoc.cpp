
// DC_exDoc.cpp : CDC_exDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DC_ex.h"
#endif
#include "DC_.h"
#include "DC_exDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDC_exDoc

IMPLEMENT_DYNCREATE(CDC_exDoc, CDocument)

BEGIN_MESSAGE_MAP(CDC_exDoc, CDocument)
	ON_COMMAND(ID_TEST_1, &CDC_exDoc::OnTest1)
END_MESSAGE_MAP()


// CDC_exDoc ����/����

CDC_exDoc::CDC_exDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDC_exDoc::~CDC_exDoc()
{
	int nIndex = GetAllRecNum(); 
		while(nIndex--) 
			delete m_stuObArray.GetAt(nIndex);	
	m_stuObArray.RemoveAll();
}

BOOL CDC_exDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDC_exDoc ���л�

void CDC_exDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		m_stuObArray.Serialize(ar);
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		m_stuObArray.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CDC_exDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CDC_exDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CDC_exDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDC_exDoc ���

#ifdef _DEBUG
void CDC_exDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDC_exDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDC_exDoc ����

//������������������������������������������������������������������������������������
//CStudent���캯��ʵ��
CStudent::CStudent(CString name,CString id,\
					CString p1,float f1,\
					CString p2,float f2, \
					CString p3,float f3,\
					CString p4,float f4)
{
	strName = name; 
	strNo = id; 
    project1 = p1;
	project2 = p2;
	project3 = p3;
	project4 = p4;
	fScore1 = f1;
	fScore2 = f2;
	fScore3 = f3;
	fScore4 = f4;
}

void CStudent::Display(int y, CDC *pDC)
{
	CString str; 
	CRect rc(10, 10, 800, 500);
	pDC->Rectangle(rc);
	str.Format("%s %s %f",strName,strNo);
			str.Format(_T("\n\n\n\n\n\n ������%s\t ѧ�ţ�%s\t\n ��Ŀһ��%s\t ������%4.1f\t\n ��Ŀ����%s\t ������%4.1f\t\n ��Ŀ����%s\t ������%4.1f\t\n ��Ŀ�ģ�%s\t ������%4.1f\t"),\
			strName,strNo,project1,fScore1,\
						  project2,fScore2,\
						  project3,fScore3,\
						  project4,fScore4);
//	pDC->TextOut(50,y,str);
CFont font,*pOldFont;
font.CreateFont(
    25,                       // nHeight
    0,                        // nWidth
    0,                        // nEscapement
    0,                        // nOrientation
    FW_NORMAL,                // nWeight
    FALSE,                    // bItalic
    FALSE,                    // bUnderline
    0,                        // cStrikeOut
    ANSI_CHARSET,             // nCharSet
    OUT_DEFAULT_PRECIS,       // nOutPrecision
    CLIP_DEFAULT_PRECIS,      // nClipPrecision
    DEFAULT_QUALITY,          // nQuality
    DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
    _T("΢���ź�"));
pOldFont=pDC->SelectObject(&font);
	pDC->DrawText(str, rc ,DT_EXPANDTABS|DT_CENTER|DT_WORDBREAK|DT_VCENTER);
pDC->SelectObject(pOldFont);
}

IMPLEMENT_SERIAL(CStudent,CObject,1); //���л�ʵ��

void CStudent::Serialize(CArchive&ar) 
{
	if(ar.IsStoring())
		ar<<strName<<strNo<<project1<<fScore1<<project2<<fScore2<<project3<<fScore3<<project4<<fScore4; 
	else
		ar>>strName>>strNo>>project1>>fScore1>>project2>>fScore2>>project3>>fScore3>>project4>>fScore4;
}

void CDC_exDoc::OnTest1()
{
	// TODO: �ڴ���������������
	DC_ dlg;

	if(IDOK == dlg.DoModal()) 
	{ // ��Ӽ�¼
		CStudent*pStudent=new CStudent(dlg.m_strName,dlg.m_strID,\
										dlg.m_project1,dlg.m_fScore1,
										dlg.m_project2,dlg.m_fScore2,
										dlg.m_project3,dlg.m_fScore3,
										dlg.m_project4,dlg.m_fScore4); 
		m_stuObArray.Add(pStudent); 
		SetModifiedFlag();		//�����ĵ����ı�־
		UpdateAllViews(NULL);  //������ͼ
	}
}

//
//// DLDoc.h : interface of the CDLDoc class 
//#if !defined(AFX_DLDOC_H__1F2F8B6F_F56D_484E_B70C_6B251931171F__INCLUDED_) 
//#define		 AFX_DLDOC_H__1F2F8B6F_F56D_484E_B70C_6B251931171F__INCLUDED_
//#endif
//#if _MSC_VER > 1000 
//#pragma once
//#endif // _MSC_VER > 1000 
//class CStudent: public CObject 
//{
//	CString strName; //���� CStringstrNo;
//	float fScore1;
//	DECLARE_SERIAL(CStudent) //���л�����
//public: 
//	CStudent(){};
//	CStudent(CString name,CString id,float f1); 
//	void Serialize(CArchive&ar); 
//	void Display(int y,CDC *pDC); 
//};
//class CDLDoc : public CDocument {
//protected: // create from serialization only 
//	CDLDoc();
//	DECLARE_DYNCREATE(CDLDoc) // Attributes 
//public:
//	CObArray m_stuObArray;
//// Operations 
//public:
//// Overrides
//	// ClassWizard generated virtual function overrides
//	//{{AFX_VIRTUAL(CDLDoc) 
//public:
//	virtual BOOL OnNewDocument(); 
//	virtual void Serialize(CArchive&ar); //
//	//}}AFX_VIRTUAL
//
//// Implementation public:
//virtual ~CDLDoc();
//CStudent *CDLDoc::GetStudentAt(int nIndex) 
//{
//	if((nIndex<0)|| nIndex>m_stuObArray.GetUpperBound()) 
//		return 0; //���紦��
//	return(CStudent *)m_stuObArray.GetAt(nIndex); }
//int CDLDoc::GetAllRecNum() 
//{
//	return m_stuObArray.GetSize(); 
//}
//
//#ifdef _DEBUG 
//virtual void AssertValid() const; 
//virtual void Dump(CDumpContext& dc) const; 
//#endif
//
//protected:
//// Generated message map functions 
//
//protected:
////{{AFX_MSG(CDLDoc) 
//	afx_msg void OnSturecAdd(); //}}AFX_MSG
//	DECLARE_MESSAGE_MAP() 
//};
////{{AFX_INSERT_LOCATION}} 
//// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
//
//// !defined(AFX_DLDOC_H__1F2F8B6F_F56D_484E_B70C_6B251931171F_ _INCLUDED_)
////#endif

CStudent *CDC_exDoc::GetStudentAt(int nIndex) 
{
	if((nIndex<0)|| nIndex>m_stuObArray.GetUpperBound()) 
		return 0; //���紦��
	return(CStudent *)m_stuObArray.GetAt(nIndex); }
int CDC_exDoc::GetAllRecNum() 
{
	return m_stuObArray.GetSize(); 
}