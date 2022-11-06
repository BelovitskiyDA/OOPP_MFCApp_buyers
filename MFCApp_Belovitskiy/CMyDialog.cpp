// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCApp_Belovitskiy.h"
#include "CMyDialog.h"
#include "afxdialogex.h"
#include "MFCApp_BelovitskiyDoc.h"
#include "utils.h"
#include "VipBuyer.h"
#include <stdio.h>


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CMFCAppBelovitskiyDoc* pDoc,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent), pDoc(pDoc)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Control(pDX, IDC_EDIT_NAME, edit_name);
	DDX_Control(pDX, IDC_EDIT_SURENAME, edit_surename);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_EDIT_AGE, edit_age);
	DDX_Control(pDX, IDC_EDIT_PHONE, edit_phone);
	DDX_Control(pDX, IDC_EDIT_POINTS, edit_points);
	DDX_Control(pDX, IDC_STATIC_POINTS, statictext_points);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyDialog::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMyDialog::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// CMyDialog message handlers


BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	pDoc->town.printList(list);
	OnLbnSelchangeList1();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CMyDialog::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	int n = list.GetCurSel();
	if (n < 0)
		return;
	DoChange(n);
}

void CMyDialog::DoChange(int n)
{
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
	
	UpdateData(FALSE);

}

void CMyDialog::OnBnClickedButtonDelete()
{
	// TODO: Add your control notification handler code here
	int nmax = list.GetCount();
	int n = list.GetCurSel();
	if (n < 0)
		return;

	pDoc->town.delete_buyer(n);

	list.DeleteString(n);
	if (nmax != 1 && nmax == n)
	{
		list.SetCurSel(n-1);
	}
	else if (nmax != 1 && nmax != n)
	{
		list.SetCurSel(n);
	}
	
	
	OnLbnSelchangeList1();
}
