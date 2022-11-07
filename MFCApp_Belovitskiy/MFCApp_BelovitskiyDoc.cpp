
// MFCApp_BelovitskiyDoc.cpp : implementation of the CMFCAppBelovitskiyDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp_Belovitskiy.h"
#endif

#include "MFCApp_BelovitskiyDoc.h"
#include "CMyDialog.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCAppBelovitskiyDoc

IMPLEMENT_DYNCREATE(CMFCAppBelovitskiyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCAppBelovitskiyDoc, CDocument)
	ON_COMMAND(ID_FILE_EDITINFO, &CMFCAppBelovitskiyDoc::OnFileEditinfo)
END_MESSAGE_MAP()


// CMFCAppBelovitskiyDoc construction/destruction

CMFCAppBelovitskiyDoc::CMFCAppBelovitskiyDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCAppBelovitskiyDoc::~CMFCAppBelovitskiyDoc()
{
}

BOOL CMFCAppBelovitskiyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	town.clear_town();
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCAppBelovitskiyDoc serialization

void CMFCAppBelovitskiyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		town.save_file(ar);
	}
	else
	{
		// TODO: add loading code here
		town.clear_town();
		town.load_file(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCAppBelovitskiyDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCAppBelovitskiyDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCAppBelovitskiyDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCAppBelovitskiyDoc diagnostics

#ifdef _DEBUG
void CMFCAppBelovitskiyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCAppBelovitskiyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCAppBelovitskiyDoc commands


void CMFCAppBelovitskiyDoc::OnFileEditinfo()
{
	// TODO: Add your command handler code here
	CMyDialog dlg(this);
	dlg.DoModal();
	UpdateAllViews(NULL);
}
