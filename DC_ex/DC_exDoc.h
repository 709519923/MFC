
// DC_exDoc.h : CDC_exDoc 类的接口
//

#pragma once

//——————————————————加入代码
class CStudent: public CObject 
{
	CString strName; //名字 
	CString strNo;  //学号
	float fScore1,fScore2,fScore3,fScore4;    //分数
	CString project1,project2,project3,project4;  //科目
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
//——————————————————加入代码

class CDC_exDoc : public CDocument
{
//——————————————————加入代码
public:
CObArray m_stuObArray;
CStudent *GetStudentAt(int nIndex);
int GetAllRecNum(void);
//——————————————————加入代码
protected: // 仅从序列化创建
	CDC_exDoc();
	DECLARE_DYNCREATE(CDC_exDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDC_exDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTest1();
};
