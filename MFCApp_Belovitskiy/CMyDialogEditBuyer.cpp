// CMyDialogEditBuyer.cpp : implementation file
//

#include "pch.h"
#include "MFCApp_Belovitskiy.h"
#include "CMyDialogEditBuyer.h"
#include "afxdialogex.h"
#include "MFCApp_BelovitskiyDoc.h"
#include "utils.h"
#include "VipBuyer.h"
#include <string>


// CMyDialogEditBuyer dialog

IMPLEMENT_DYNAMIC(CMyDialogEditBuyer, CDialogEx)

CMyDialogEditBuyer::CMyDialogEditBuyer(CMFCAppBelovitskiyDoc* pDoc, int n,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDIT_BUYER, pParent), pDoc(pDoc), n(n)
{

}

CMyDialogEditBuyer::~CMyDialogEditBuyer()
{
}

void CMyDialogEditBuyer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, edit_name);
	DDX_Control(pDX, IDC_EDIT_SURENAME, edit_surename);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_EDIT_AGE, edit_age);
	DDX_Control(pDX, IDC_EDIT_PHONE, edit_phone);
	DDX_Control(pDX, IDC_EDIT_POINTS, edit_points);
	DDX_Control(pDX, IDC_STATIC_POINTS, statictext_points);
}


BEGIN_MESSAGE_MAP(CMyDialogEditBuyer, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDialogEditBuyer::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDialogEditBuyer message handlers
BOOL CMyDialogEditBuyer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here

	auto p = pDoc->town.get_n(n);
	edit_name.SetWindowTextA(str2cstr(p->get_name()));
	edit_surename.SetWindowTextA(str2cstr(p->get_surname()));
	edit_address.SetWindowTextA(str2cstr(p->get_address()));
	edit_age.SetWindowTextA(str2cstr(std::to_string(p->get_age())));
	edit_phone.SetWindowTextA(str2cstr(std::to_string(p->get_phone_number())));
	auto pp = dynamic_cast<VipBuyer*>(p.get());
	if (pp)
	{
		edit_points.ShowWindow(SW_SHOW);
		statictext_points.ShowWindow(SW_SHOW);
		edit_points.SetWindowTextA(str2cstr(std::to_string(pp->get_points())));
	}
	else
	{
		edit_points.ShowWindow(SW_HIDE);
		statictext_points.ShowWindow(SW_HIDE);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyDialogEditBuyer::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	auto p = pDoc->town.get_n(n);
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

	auto pp = dynamic_cast<VipBuyer*>(p.get());
	if (pp)
	{
		edit_points.GetWindowTextA(buf);
		pp->set_points(std::stoi(cstr2str(buf)));
	}
	
	CDialogEx::OnOK();
}
