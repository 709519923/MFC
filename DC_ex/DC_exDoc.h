
// DC_exDoc.h : CDC_exDoc ��Ľӿ�
//

#pragma once

//�������������������������������������������
class CStudent: public CObject 
{
	CString strName; //���� 
	CString strNo;  //ѧ��
	float fScore1,fScore2,fScore3,fScore4;    //����
	CString project1,project2,project3,project4;  //��Ŀ
	DECLARE_SERIAL( CStudent )
public: 
	CStudent(){};
	CStudent(		CString name,CString id,\
					CString project1,float f1,\
					CString project2,float f2, \
					CString project3,float f3,\
					CString project4,float f4);
	void Serialize(CArchive&ar);
	void Display(int y,CDC *pDC);	
};
//�������������������������������������������

class CDC_exDoc : public CDocument
{
//�������������������������������������������
public:
CObArray m_stuObArray;
CStudent *GetStudentAt(int nIndex);
int GetAllRecNum(void);
//�������������������������������������������
protected: // �������л�����
	CDC_exDoc();
	DECLARE_DYNCREATE(CDC_exDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDC_exDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTest1();
};
