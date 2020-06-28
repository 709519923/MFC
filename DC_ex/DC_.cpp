// DC_.cpp : 实现文件
//

#include "stdafx.h"
#include "DC_ex.h"
#include "DC_.h"
#include "afxdialogex.h"


// DC_ 对话框

IMPLEMENT_DYNAMIC(DC_, CDialog)

DC_::DC_(CWnd* pParent /*=NULL*/)
	: CDialog(DC_::IDD, pParent)
	, m_fScore1(0)
	, m_project1(_T(""))
	, m_strName(_T(""))
	, m_strID(_T(""))
{
	m_fScore1 = 0.0f;
	m_fScore2 = 0.0f;
	m_fScore3 = 0.0f;
	m_fScore4 = 0.0f;
	m_project2 = _T("");
	m_project3 = _T("");
	m_project4 = _T("");
}

DC_::~DC_()
{
}

void DC_::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Text(pDX, IDC_EDIT_G1, m_fScore1);
	DDV_MinMaxFloat(pDX, m_fScore1, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT_P1, m_project1);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_G2, m_fScore2);
	DDV_MinMaxFloat(pDX, m_fScore2, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT_G3, m_fScore3);
	DDV_MinMaxFloat(pDX, m_fScore3, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT_G4, m_fScore4);
	DDV_MinMaxFloat(pDX, m_fScore4, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT_P2, m_project2);
	DDV_MaxChars(pDX, m_project2, 20);
	DDX_Text(pDX, IDC_EDIT_P3, m_project3);
	DDV_MaxChars(pDX, m_project3, 20);
	DDX_Text(pDX, IDC_EDIT_P4, m_project4);
	DDV_MaxChars(pDX, m_project4, 20);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_SPIN3, m_spin3);
	DDX_Control(pDX, IDC_SPIN4, m_spin4);
}


BEGIN_MESSAGE_MAP(DC_, CDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &DC_::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &DC_::OnDeltaposSpin2)
END_MESSAGE_MAP()


// DC_ 消息处理程序


BOOL DC_::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_spin1.SetRange(0,100);
	m_spin2.SetRange(0,100);
	m_spin3.SetRange(0,100);
	m_spin4.SetRange(0,100);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}








//void DC_::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	m_fScore1 = m_fScore1+(float)pNMUpDown->iDelta * 2.0f;
//	if(m_fScore1<0.0)
//		m_fScore1 = 0.0f;
//	if(m_fScore1>100.0)
//		m_fScore1 = 100.0f;
//	UpdateData(FALSE);   //变量保存在控件中
//	*pResult = 0;
//
//}


void DC_::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_fScore1 = (double)m_fScore1+(float)pNMUpDown->iDelta * 0.5;
	if(m_fScore1<0.0)
		m_fScore1 = 0.0f;
	if(m_fScore1>100.0)
		m_fScore1 = 100.0f;
	UpdateData(FALSE);   //变量保存在控件中
	*pResult = 0;
}


void DC_::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_fScore2 = m_fScore2+(float)pNMUpDown->iDelta * 0.5;
	if(m_fScore2<0.0)
		m_fScore2 = 0.0f;
	if(m_fScore2>100.0)
		m_fScore2 = 100.0f;
	UpdateData(FALSE);   //变量保存在控件中
	*pResult = 0;
}
