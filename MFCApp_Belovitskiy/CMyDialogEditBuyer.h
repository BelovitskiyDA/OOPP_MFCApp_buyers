#pragma once


// CMyDialogEditBuyer dialog
class CMFCAppBelovitskiyDoc;

class CMyDialogEditBuyer : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialogEditBuyer)
	CMFCAppBelovitskiyDoc* pDoc;
	int n;
public:
	CMyDialogEditBuyer(CMFCAppBelovitskiyDoc*, int,CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialogEditBuyer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDIT_BUYER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CEdit edit_name;
	CEdit edit_surename;
	CEdit edit_address;
	CEdit edit_age;
	CEdit edit_phone;
	CEdit edit_points;
	CStatic statictext_points;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
