
// MFCApp_BelovitskiyView.cpp : implementation of the CMFCAppBelovitskiyView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp_Belovitskiy.h"
#endif

#include "MFCApp_BelovitskiyDoc.h"
#include "MFCApp_BelovitskiyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppBelovitskiyView

IMPLEMENT_DYNCREATE(CMFCAppBelovitskiyView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCAppBelovitskiyView, CScrollView)
END_MESSAGE_MAP()

// CMFCAppBelovitskiyView construction/destruction

CMFCAppBelovitskiyView::CMFCAppBelovitskiyView() noexcept
{
	// TODO: add construction code here

}

CMFCAppBelovitskiyView::~CMFCAppBelovitskiyView()
{
}

BOOL CMFCAppBelovitskiyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CMFCAppBelovitskiyView drawing

void CMFCAppBelovitskiyView::OnDraw(CDC* pDC)
{
	CMFCAppBelovitskiyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	//CPen pen(PS_SOLID, 3, RGB(256, 112, 69));
	//CPen* pOldpen = pDC->SelectObject(&pen);


	CSize sizeTotal = pDoc->town.draw(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);

	//pDC->SelectObject(&pOldpen);
}

void CMFCAppBelovitskiyView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMFCAppBelovitskiyView diagnostics

#ifdef _DEBUG
void CMFCAppBelovitskiyView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCAppBelovitskiyView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCAppBelovitskiyDoc* CMFCAppBelovitskiyView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppBelovitskiyDoc)));
	return (CMFCAppBelovitskiyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppBelovitskiyView message handlers
