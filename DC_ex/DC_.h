#pragma once
#include "afxcmn.h"


// DC_ �Ի���

class DC_ : public CDialog
{
	DECLARE_DYNAMIC(DC_)

public:
	DC_(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DC_();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CSpinButtonCtrl m_spin1;
	double m_fScore1;
	CString m_project1;
	afx_msg void OnBnClickedButton1();
	CString m_strName;
	CString m_strID;
	float m_fScore2;
	float m_fScore3;
	float m_fScore4;
	CString m_project2;
	CString m_project3;
	CString m_project4;
	CSpinButtonCtrl m_spin2;
	CSpinButtonCtrl m_spin3;
	CSpinButtonCtrl m_spin4;
//	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
};
