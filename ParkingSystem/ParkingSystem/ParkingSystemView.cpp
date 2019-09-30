
// ParkingSystemView.cpp : CParkingSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ParkingSystem.h"
#endif

#include "ParkingSystemDoc.h"
#include "ParkingSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CParkingSystemView

IMPLEMENT_DYNCREATE(CParkingSystemView, CView)

BEGIN_MESSAGE_MAP(CParkingSystemView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CParkingSystemView ����/����

CParkingSystemView::CParkingSystemView()
{
	// TODO: �ڴ˴���ӹ������

}

CParkingSystemView::~CParkingSystemView()
{
}

BOOL CParkingSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CParkingSystemView ����

void CParkingSystemView::OnDraw(CDC* /*pDC*/)
{
	CParkingSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CParkingSystemView ��ӡ

BOOL CParkingSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CParkingSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CParkingSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CParkingSystemView ���

#ifdef _DEBUG
void CParkingSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CParkingSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParkingSystemDoc* CParkingSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParkingSystemDoc)));
	return (CParkingSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CParkingSystemView ��Ϣ�������
