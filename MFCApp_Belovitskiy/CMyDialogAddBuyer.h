#pragma once


// CMyDialogAddBuyer dialog
class CMFCAppBelovitskiyDoc;

class CMyDialogAddBuyer : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialogAddBuyer)
	CMFCAppBelovitskiyDoc* pDoc;

public:
	CMyDialogAddBuyer(CMFCAppBelovitskiyDoc*, CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialogAddBuyer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_BUYER };
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
	CButton flag_vip_buyer;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckVipBuyer();
};
