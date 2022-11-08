#pragma once


// CMyDialogEditTown dialog
class CMFCAppBelovitskiyDoc;

class CMyDialogEditTown : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialogEditTown)
	CMFCAppBelovitskiyDoc* pDoc;
public:
	CMyDialogEditTown(CMFCAppBelovitskiyDoc* pDoc, CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialogEditTown();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDITTOWN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_name;
	CEdit edit_country;
	CEdit edit_index;
	CEdit edit_utc;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
