
// MFCApp_BelovitskiyDoc.h : interface of the CMFCAppBelovitskiyDoc class
//


#pragma once
#include "Town.h"

class CMFCAppBelovitskiyDoc : public CDocument
{
protected: // create from serialization only
	CMFCAppBelovitskiyDoc() noexcept;
	DECLARE_DYNCREATE(CMFCAppBelovitskiyDoc)

// Attributes
public:
	Town town;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCAppBelovitskiyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileEditinfo();
	afx_msg void OnFileEdittown();
};
