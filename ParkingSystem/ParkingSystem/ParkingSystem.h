
// ParkingSystem.h : ParkingSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CParkingSystemApp:
// �йش����ʵ�֣������ ParkingSystem.cpp
//

class CParkingSystemApp : public CWinApp
{
public:
	CParkingSystemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CParkingSystemApp theApp;
