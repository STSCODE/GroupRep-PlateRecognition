
// ParkingSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


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

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CParkingSystemApp theApp;