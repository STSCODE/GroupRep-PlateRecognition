
// ParkingSystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxdtctl.h"
#include"DataBase.h"
#include "afxwin.h"

// CParkingSystemDlg �Ի���
class CParkingSystemDlg : public CDialogEx
{
// ����
public:
	CParkingSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARKINGSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOutputToPdfBtn();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonCarnum();
	afx_msg void OnBnClickedButtonCarmoney();
	CDateTimeCtrl m_Data_Start;
	CDateTimeCtrl m_Data_End;
	
};
