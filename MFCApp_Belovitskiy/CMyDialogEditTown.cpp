// CMyDialogEditTown.cpp : implementation file
//

#include "pch.h"
#include "MFCApp_Belovitskiy.h"
#include "CMyDialogEditTown.h"
#include "afxdialogex.h"
#include "MFCApp_BelovitskiyDoc.h"
#include "utils.h"
#include <string>

// CMyDialogEditTown dialog

IMPLEMENT_DYNAMIC(CMyDialogEditTown, CDialogEx)

CMyDialogEditTown::CMyDialogEditTown(CMFCAppBelovitskiyDoc* pDoc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDITTOWN, pParent), pDoc(pDoc)
{

}

CMyDialogEditTown::~CMyDialogEditTown()
{
}

void CMyDialogEditTown::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, edit_name);
	DDX_Control(pDX, IDC_EDIT_COUNTRY, edit_country);
	DDX_Control(pDX, IDC_EDIT_INDEX, edit_index);
	DDX_Control(pDX, IDC_EDIT_UTC, edit_utc);
}


BEGIN_MESSAGE_MAP(CMyDialogEditTown, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDialogEditTown::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDialogEditTown message handlers
BOOL CMyDialogEditTown::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here

	edit_name.SetWindowTextA(str2cstr(pDoc->town.get_name()));
	edit_country.SetWindowTextA(str2cstr(pDoc->town.get_country()));
	edit_index.SetWindowTextA(str2cstr(std::to_string(pDoc->town.get_index())));
	edit_utc.SetWindowTextA(str2cstr(std::to_string(pDoc->town.get_utc())));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyDialogEditTown::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString buf;
	edit_name.GetWindowTextA(buf);
	pDoc->town.set_name(cstr2str(buf));
	edit_country.GetWindowTextA(buf);
	pDoc->town.set_country(cstr2str(buf));
	edit_index.GetWindowTextA(buf);
	pDoc->town.set_index(std::stoi(cstr2str(buf)));
	edit_utc.GetWindowTextA(buf);
	pDoc->town.set_utc(std::stoi(cstr2str(buf)));

	CDialogEx::OnOK();
}
