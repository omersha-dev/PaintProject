// PaintProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PaintProject.h"
#include "PaintProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW

#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaintProjectDlg dialog



CPaintProjectDlg::CPaintProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PAINTPROJECT_DIALOG, pParent), isFill(FALSE), isThin(FALSE)
{
	typeOfShape = PEN;
	currentColor = RGB(0, 0, 0);
	isPressed = false;
	counter = 0;
	maxIndex = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CPaintProjectDlg::~CPaintProjectDlg()
{
	int size = myShape.size();
	for (int i = 0; i < size; i++)
	{
		myShape.erase(myShape.begin());
	}
}
//NEW BUTTON ACTIONS
void CPaintProjectDlg::newScreen()
{
	myShape.clear();
	moves.Delete();
	undoButton.EnableWindow(0);
	redoButton.EnableWindow(0);
	Invalidate();
}

void CPaintProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_CHECK1, isThin);
	DDX_Check(pDX, IDC_CHECK2, isFill);
	DDX_Control(pDX, IDC_BUTTON1, undoButton);
	DDX_Control(pDX, IDC_BUTTON2, redoButton);

}

BEGIN_MESSAGE_MAP(CPaintProjectDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()

	ON_BN_CLICKED(IDC_RADIO1, &CPaintProjectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPaintProjectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPaintProjectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CPaintProjectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CPaintProjectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON1, &CPaintProjectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPaintProjectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPaintProjectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CPaintProjectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CPaintProjectDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_RADIO6, &CPaintProjectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON6, &CPaintProjectDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CPaintProjectDlg message handlers

BOOL CPaintProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	//pen icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO1);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//line icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO2);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//ellipse icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO3);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//rectangle icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO5);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//trinagle icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO4);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//fill area icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RADIO6);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON6), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//thin icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON7), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//fill object icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON8), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//choose color icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON3);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON9), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//undo icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON1);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON10), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	//redo icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON2);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON11), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR);
		pBtn->SetIcon(hIcn);
	}
	////save icon
	//{
	//	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON4);
	//	pBtn->ModifyStyle(0, BS_ICON);
	//	HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON12), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR); // Redo Icon
	//	pBtn->SetIcon(hIcn);
	//}
	////load icon
	//{
	//	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON5);
	//	pBtn->ModifyStyle(0, BS_ICON);
	//	HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON13), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR); // Redo Icon
	//	pBtn->SetIcon(hIcn);
	//}
	//new icon
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON6);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON16), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR); // Redo Icon
		pBtn->SetIcon(hIcn);
	}
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPaintProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPaintProjectDlg::OnPaint()
{
	int currentIndex = myShape.size();
	CPaintDC dc(this);
	for (int i = 0; i < currentIndex; i++)
		myShape[i]->Draw(&dc);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaintProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPaintProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	int currentIndex = myShape.size();
	if (isPressed)
	{
		end = point;
		isPressed = false;
		if (end != start)
		{
			switch (typeOfShape)
			{
			case PEN:
				Invalidate();
				break;
			case LINE:
				myShape.push_back(new myLine(start.x, start.y, end.x, end.y, isThin, currentColor));
				moves.Move(new myLine(start.x, start.y, end.x, end.y, isThin, currentColor));
				Invalidate();
				break;
			case ELLIPSE:
				myShape.push_back(new myEllipse(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				moves.Move(new myEllipse(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				Invalidate();
				break;
			case TRIANGLE:
				myShape.push_back(new myTriangle(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				moves.Move(new myTriangle(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				Invalidate();
				break;
			case RECTANGLE:
				myShape.push_back(new myRectangle(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				moves.Move(new myRectangle(start.x, start.y, end.x, end.y, isFill, isThin, currentColor));
				Invalidate();
				break;
			}
		}
		if (currentIndex < myShape.size())
			redoButton.EnableWindow(0);
	}

	CDialog::OnLButtonUp(nFlags, point);
}

void CPaintProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		int currentIndex = myShape.size();
		CClientDC dc(this);
		CBrush myBrush, *oldBrush;
		//inside the shape	
		if (isFill)
		{
			myBrush.CreateSolidBrush(currentColor);
			oldBrush = dc.SelectObject(&myBrush);
		}
		dc.SetROP2(R2_NOTXORPEN);
		//outside the shape	
		CPen myPen1(PS_SOLID, isThin ? 1 : 5, currentColor);
		CPen *oldPen;
		oldPen = dc.SelectObject(&myPen1);
		switch (typeOfShape)
		{
		case PEN:
			myShape[currentIndex - 1]->Build(point);
			dc.MoveTo(myShape[currentIndex - 1]->lastPoint());
			dc.LineTo(end.x, end.y);
			end = point;
			dc.MoveTo(myShape[currentIndex - 1]->lastPoint());
			dc.LineTo(end.x, end.y);
			undoButton.EnableWindow(1);
			break;
		case LINE:
			dc.MoveTo(start.x, start.y);
			dc.LineTo(end.x, end.y);
			end = point;
			dc.MoveTo(start.x, start.y);
			dc.LineTo(end.x, end.y);
			undoButton.EnableWindow(1);
			break;
		case ELLIPSE:
			dc.Ellipse(start.x, start.y, end.x, end.y);
			end = point;
			dc.Ellipse(start.x, start.y, end.x, end.y);
			undoButton.EnableWindow(1);
			break;
		case TRIANGLE:
			dc.MoveTo(start.x, end.y);
			dc.LineTo(end.x, end.y);
			dc.LineTo((start.x + end.x) / 2, start.y);
			dc.LineTo(start.x, end.y);
			end = point;
			dc.MoveTo(start.x, end.y);
			dc.LineTo(end.x, end.y);
			dc.LineTo((start.x + end.x) / 2, start.y);
			dc.LineTo(start.x, end.y);
			undoButton.EnableWindow(1);
			break;
		case RECTANGLE:
			dc.Rectangle(start.x, start.y, end.x, end.y);
			end = point;
			dc.Rectangle(start.x, start.y, end.x, end.y);
			undoButton.EnableWindow(1);
			break;
		}
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CPaintProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int currentIndex = myShape.size();
	start = point;
	end = point;

	isPressed = true;
	switch (typeOfShape)
	{
	case PEN:
		myShape.push_back(new myPen(start.x, start.y, isThin, currentColor));
		moves.Move(new myPen(start.x, start.y, isThin, currentColor));
		break;

	case COLOR_CHANGE:
	{
		for (int i = 0; i < currentIndex; i++)
			if (myShape[i]->isExist(point))
			{
				myShape[i]->setColor(currentColor);
				Invalidate();
			}
		CClientDC dc(this);
		COLORREF c = currentColor;
	}
	break;
	}
	if (currentIndex < myShape.size())
		redoButton.EnableWindow(0);

	CDialog::OnLButtonDown(nFlags, point);
}



void CPaintProjectDlg::OnBnClickedRadio1()
{
	//PEN
	typeOfShape = PEN;
}


void CPaintProjectDlg::OnBnClickedRadio2()
{
	//LINE
	typeOfShape = LINE;
}


void CPaintProjectDlg::OnBnClickedRadio3()
{
	//ELLIPSE
	typeOfShape = ELLIPSE;
}


void CPaintProjectDlg::OnBnClickedRadio4()
{
	// TRIANGLE
	typeOfShape = TRIANGLE;
}


void CPaintProjectDlg::OnBnClickedRadio5()
{
	// TRIANGLE
	typeOfShape = RECTANGLE;
}


void CPaintProjectDlg::OnBnClickedButton1()
{
	// UNDO
	myShape = moves.Undo();
	redoButton.EnableWindow(1);
	if (myShape.empty())
		undoButton.EnableWindow(0);
	Invalidate();
}


void CPaintProjectDlg::OnBnClickedButton2()
{
	// REDO
	myShape = moves.Redo();
	undoButton.EnableWindow(1);
	Invalidate();
}


void CPaintProjectDlg::OnBnClickedButton3()
{
	//CHOOSE COLOR
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
		currentColor = dlg.GetColor(); // opening a new window with alot colors to choose
}


void CPaintProjectDlg::OnBnClickedCheck1()
{
	//THIN
	UpdateData(true);
}


void CPaintProjectDlg::OnBnClickedCheck2()
{
	// FILL OBJECT NOT JUST THE EDGES
	UpdateData(true);
}


void CPaintProjectDlg::OnBnClickedRadio6()
{
	//FILL AREA AFTER EXIST
	typeOfShape = COLOR_CHANGE;
}


void CPaintProjectDlg::OnBnClickedButton6()
{//NEW BUTTON
	this->newScreen();
}
