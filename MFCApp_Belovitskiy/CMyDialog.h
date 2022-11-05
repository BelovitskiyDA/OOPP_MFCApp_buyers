#pragma once


// CMyDialog dialog
class CMFCAppBelovitskiyDoc;

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)
	CMFCAppBelovitskiyDoc* pDoc;

public:
	CMyDialog(CMFCAppBelovitskiyDoc* ,CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox list;
	CEdit edit_name;
	CEdit edit_surename;
	CEdit edit_address;
	CEdit edit_age;
	CEdit edit_phone;
	CEdit edit_points;
	virtual BOOL OnInitDialog();
};
