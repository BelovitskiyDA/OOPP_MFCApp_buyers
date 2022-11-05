// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCApp_Belovitskiy.h"
#include "CMyDialog.h"
#include "afxdialogex.h"
#include "MFCApp_BelovitskiyDoc.h"


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
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyDialog message handlers


BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	pDoc->town.printList(list);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
