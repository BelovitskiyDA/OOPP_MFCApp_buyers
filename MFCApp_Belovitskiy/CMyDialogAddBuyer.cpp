// CMyDialogAddBuyer.cpp : implementation file
//

#include "pch.h"
#include "MFCApp_Belovitskiy.h"
#include "CMyDialogAddBuyer.h"
#include "afxdialogex.h"
#include "MFCApp_BelovitskiyDoc.h"
#include "utils.h"
#include "VipBuyer.h"
#include <string>

// CMyDialogAddBuyer dialog

IMPLEMENT_DYNAMIC(CMyDialogAddBuyer, CDialogEx)

CMyDialogAddBuyer::CMyDialogAddBuyer(CMFCAppBelovitskiyDoc* pDoc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_BUYER, pParent), pDoc(pDoc)
{

}

CMyDialogAddBuyer::~CMyDialogAddBuyer()
{
}

void CMyDialogAddBuyer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, edit_name);
	DDX_Control(pDX, IDC_EDIT_SURENAME, edit_surename);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_EDIT_AGE, edit_age);
	DDX_Control(pDX, IDC_EDIT_PHONE, edit_phone);
	DDX_Control(pDX, IDC_EDIT_POINTS, edit_points);
	DDX_Control(pDX, IDC_STATIC_POINTS, statictext_points);
	DDX_Control(pDX, IDC_CHECK_VIPBUYER, flag_vip_buyer);
}


BEGIN_MESSAGE_MAP(CMyDialogAddBuyer, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_VIPBUYER, &CMyDialogAddBuyer::OnBnClickedCheckVipBuyer)
	ON_BN_CLICKED(IDOK, &CMyDialogAddBuyer::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDialogAddBuyer message handlers
BOOL CMyDialogAddBuyer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	edit_points.ShowWindow(SW_HIDE);
	statictext_points.ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyDialogAddBuyer::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int state = flag_vip_buyer.GetCheck();
	if (state == BST_CHECKED)
	{
		auto p = std::make_shared<VipBuyer>();
		CString buf;
		edit_name.GetWindowTextA(buf);
		p->set_name(cstr2str(buf));
		edit_surename.GetWindowTextA(buf);
		p->set_surname(cstr2str(buf));
		edit_address.GetWindowTextA(buf);
		p->set_address(cstr2str(buf));
		edit_age.GetWindowTextA(buf);
		p->set_age(std::stoi(cstr2str(buf)));
		edit_phone.GetWindowTextA(buf);
		p->set_phone_number(std::stoll(cstr2str(buf)));
		edit_points.GetWindowTextA(buf);
		p->set_points(std::stoi(cstr2str(buf)));
		pDoc->town.add_vip_buyer(p);
	}
	else
	{
		auto p = std::make_shared<Buyer>();
		CString buf;
		edit_name.GetWindowTextA(buf);
		p->set_name(cstr2str(buf));
		edit_surename.GetWindowTextA(buf);
		p->set_surname(cstr2str(buf));
		edit_address.GetWindowTextA(buf);
		p->set_address(cstr2str(buf));
		edit_age.GetWindowTextA(buf);
		p->set_age(std::stoi(cstr2str(buf)));
		edit_phone.GetWindowTextA(buf);
		p->set_phone_number(std::stoll(cstr2str(buf)));
		pDoc->town.add_buyer(p);
	}

	CDialogEx::OnOK();
}

void CMyDialogAddBuyer::OnBnClickedCheckVipBuyer()
{
	// TODO: Add your control notification handler code here
	
	int state = flag_vip_buyer.GetCheck();
	if (state == BST_CHECKED)
	{
		flag_vip_buyer.SetCheck(BST_UNCHECKED);
		edit_points.ShowWindow(SW_HIDE);
		statictext_points.ShowWindow(SW_HIDE);
	}
	else
	{
		flag_vip_buyer.SetCheck(BST_CHECKED);
		edit_points.ShowWindow(SW_SHOW);
		statictext_points.ShowWindow(SW_SHOW);
	}
		
	
}



