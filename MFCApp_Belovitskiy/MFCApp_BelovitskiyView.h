
// MFCApp_BelovitskiyView.h : interface of the CMFCAppBelovitskiyView class
//

#pragma once


class CMFCAppBelovitskiyView : public CScrollView
{
protected: // create from serialization only
	CMFCAppBelovitskiyView() noexcept;
	DECLARE_DYNCREATE(CMFCAppBelovitskiyView)

// Attributes
public:
	CMFCAppBelovitskiyDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMFCAppBelovitskiyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApp_BelovitskiyView.cpp
inline CMFCAppBelovitskiyDoc* CMFCAppBelovitskiyView::GetDocument() const
   { return reinterpret_cast<CMFCAppBelovitskiyDoc*>(m_pDocument); }
#endif

