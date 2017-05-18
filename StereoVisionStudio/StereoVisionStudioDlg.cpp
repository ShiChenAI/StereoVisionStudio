
// StereoVisionStudioDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StereoVisionStudio.h"
#include "StereoVisionStudioDlg.h"
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


// CStereoVisionStudioDlg dialog



CStereoVisionStudioDlg::CStereoVisionStudioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STEREOVISIONSTUDIO_DIALOG, pParent)
	, m_editNx(0)
	, m_editNy(0)
	, m_editPrjName(_T(""))
	, m_editSapCount(0)
	, m_editSquareSize(0)
	, m_radMethod(0)
	, m_chcShowCal(FALSE)
	, m_chcShowCorner(FALSE)
	, m_editBlockSize(0)
	, m_editMaxDisparity(0)
	, m_editScaleFactor(0)
	, m_radMatchMethod(0)
	, m_editPrjPath(_T(""))
	, m_editMaxDiff(0)
	, m_editMinDisparity(0)
	, m_editPreCap(0)
	, m_editSpeckleRange(0)
	, m_editSpeckeWinSize(0)
	, m_editTextThres(0)
	, m_editUniqeRatio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStereoVisionStudioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBO_CAM_LEFT, m_cboCamLeft);
	DDX_Control(pDX, IDC_CBO_CAM_RIGHT, m_cboCamRight);
	DDX_Text(pDX, IDC_EDIT_NX, m_editNx);
	DDX_Text(pDX, IDC_EDIT_NY, m_editNy);
	DDX_Text(pDX, IDC_EDIT_PRJ_NAME, m_editPrjName);
	DDX_Text(pDX, IDC_EDIT_SAP_COUNT, m_editSapCount);
	DDX_Text(pDX, IDC_EDIT_SQUARE_SIZE, m_editSquareSize);
	DDX_Radio(pDX, IDC_RAD_BOUGUET, m_radMethod);
	DDX_Check(pDX, IDC_CHC_SHOW_CAL, m_chcShowCal);
	DDX_Check(pDX, IDC_CHC_SHOW_CORNER, m_chcShowCorner);
	DDX_Text(pDX, IDC_EDIT_BLOCK_SIZE, m_editBlockSize);
	DDX_Text(pDX, IDC_EDIT_MAX_DISPARITY, m_editMaxDisparity);
	DDX_Text(pDX, IDC_EDIT_SCALE_FACTOR, m_editScaleFactor);
	DDX_Radio(pDX, IDC_RAD_BM, m_radMatchMethod);
	DDX_Text(pDX, IDC_EDIT_PRJ_PATH, m_editPrjPath);
	DDX_Text(pDX, IDC_EDIT_MAX_DIFF, m_editMaxDiff);
	DDX_Text(pDX, IDC_EDIT_MIN_DISPARITY, m_editMinDisparity);
	DDX_Text(pDX, IDC_EDIT_PRE_CAP, m_editPreCap);
	DDX_Text(pDX, IDC_EDIT_SPECKLE_RANGE, m_editSpeckleRange);
	DDX_Text(pDX, IDC_EDIT_SPECKLE_WIN_SIZE, m_editSpeckeWinSize);
	DDX_Text(pDX, IDC_EDIT_TEXT_THRES, m_editTextThres);
	DDX_Text(pDX, IDC_EDIT_UNIQE_RATIO, m_editUniqeRatio);
}

BEGIN_MESSAGE_MAP(CStereoVisionStudioDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_CBO_CAM_LEFT, &CStereoVisionStudioDlg::OnSelchangeCboCamLeft)
	ON_CBN_SELCHANGE(IDC_CBO_CAM_RIGHT, &CStereoVisionStudioDlg::OnSelchangeCboCamRight)
	ON_BN_CLICKED(IDC_BTN_OPENCAM, &CStereoVisionStudioDlg::OnClickedBtnOpencam)
	ON_BN_CLICKED(IDC_BTN_CLOSECAM, &CStereoVisionStudioDlg::OnClickedBtnClosecam)
	ON_BN_CLICKED(IDC_BTN_CREATE_PRJ, &CStereoVisionStudioDlg::OnClickedBtnCreatePrj)
	ON_BN_CLICKED(IDC_CAP_IMAGE, &CStereoVisionStudioDlg::OnClickedCapImage)
	ON_BN_CLICKED(IDC_BTN_DEFAULT_CAL_PARA, &CStereoVisionStudioDlg::OnClickedBtnDefaultCalPara)
	ON_BN_CLICKED(IDC_BTN_CALIBRATION, &CStereoVisionStudioDlg::OnBnClickedBtnCalibration)
	ON_BN_CLICKED(IDC_BTN_MARCH, &CStereoVisionStudioDlg::OnBnClickedBtnMarch)
	ON_BN_CLICKED(IDC_BTN_STOP_MATCH, &CStereoVisionStudioDlg::OnBnClickedBtnStopMatch)
	ON_BN_CLICKED(IDC_SELECT_PRJ, &CStereoVisionStudioDlg::OnBnClickedSelectPrj)
	ON_BN_CLICKED(IDC_BTN_DEFAULT_MATCH, &CStereoVisionStudioDlg::OnBnClickedBtnDefaultMatch)
	ON_BN_CLICKED(IDC_BTN_SELECT_PRJ_CAL, &CStereoVisionStudioDlg::OnBnClickedBtnSelectPrjCal)
END_MESSAGE_MAP()


// CStereoVisionStudioDlg message handlers

BOOL CStereoVisionStudioDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//ShowWindow(SW_MAXIMIZE);

	// Get the number of cameras
	m_cameraCount = CVideoUtility::GetCameraCount();
	if (m_cameraCount < 2)
	{
		AfxMessageBox(_T("Please insert at least 2 cameras£¡"));
	}

	// Fill camera list
	char camName[1024];
	char istr[1024];
	CString strCamName;
	for (int i = 0; i < m_cameraCount; i++)
	{
		int retval = CVideoUtility::GetCameraName(i, camName, sizeof(camName));

		sprintf_s(istr, "#%d ", i);
		strcat_s(istr, camName);
		strCamName = istr;
		if (retval >0)
		{
			m_cboCamLeft.AddString(strCamName);
			m_cboCamRight.AddString(strCamName);
		}
		else
		{
			AfxMessageBox(_T("Failed to get camera name!"));
		}
	}
	strCamName.ReleaseBuffer();

	// Disable button
	GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CLOSECAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PRJ_NAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CREATE_PRJ)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAP_IMAGE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP_MATCH)->EnableWindow(FALSE);

	// Defaults to using BOUGUET's method for calibration
	m_radMethod = 0;

	// Defaults to showing calibration results
	m_chcShowCal = true;
	m_chcShowCorner = true;

	// Camera view windows parameters initiating
	m_pwndLf = GetDlgItem(IDC_PIC_LEFT_CAM);
	m_pDCLf = m_pwndLf->GetDC();
	m_hDCLf = m_pDCLf->GetSafeHdc();
	m_pwndLf->GetClientRect(&m_rectLf);

	m_pwndRi = GetDlgItem(IDC_PIC_RIGHT_CAM);
	m_pDCRi = m_pwndRi->GetDC();
	m_hDCRi = m_pDCRi->GetSafeHdc();
	m_pwndRi->GetClientRect(&m_rectRi);

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStereoVisionStudioDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStereoVisionStudioDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStereoVisionStudioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStereoVisionStudioDlg::ShowImage(Mat & frame, IplImage & image, HDC & hdc, CRect & rect)
{
	// Convert to IplImage
	image = frame;

	// Draw image to HDC
	CvvImage cvvImage;
	cvvImage.CopyOf(&image, 3);
	cvvImage.DrawToHDC(hdc, &rect);
}

void CStereoVisionStudioDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (m_lfCam.isOpened())
	{
		// Capture frame from camera
		m_lfCam >> m_lfImage;

		// Draw image to HDC
		ShowImage(m_lfImage, m_copyLfImage, m_hDCLf, m_rectLf);
	}

	if (m_riCam.isOpened())
	{
		// Capture frame from camera
		m_riCam >> m_riImage;

		// Draw image to HDC
		ShowImage(m_riImage, m_copyRiImage, m_hDCRi, m_rectRi);
	}

	// streo match calculation
	if (m_matchFlag)
	{
		UpdateData(TRUE);
		CStereoMatchPara matchPara;
		matchPara.prjName = m_prjPath;
		matchPara.algorithm = m_radMatchMethod;
		matchPara.blockSize = m_editBlockSize;
		matchPara.maxDisparity = m_editMaxDisparity;
		matchPara.scaleFactor = m_editScaleFactor;
		matchPara.leftImage = m_lfImage;
		matchPara.rightImage = m_riImage;
		matchPara.disp12MaxDiff = m_editMaxDiff;
		matchPara.minDisparity = m_editMinDisparity;
		matchPara.preFilterCap = m_editPreCap;
		matchPara.speckleRange = m_editSpeckleRange;
		matchPara.speckleWindowSize = m_editSpeckeWinSize;
		matchPara.textureThreshold = m_editTextThres;
		matchPara.uniquenessRatio = m_editUniqeRatio;
		matchPara.intrinsicFilename = m_prjPath + "\\intrinsics.yml";
		matchPara.extrinsicFilename = m_prjPath + "\\extrinsics.yml";

		CStereoMatch cal;
		cal.Calculation(matchPara, m_dsImage);
		ShowImage(m_dsImage, m_copyDsImage, m_hDCDs, m_rectDs);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CStereoVisionStudioDlg::OnSelchangeCboCamLeft()
{
	// Get left camera ID
	m_lfCamID = m_cboCamLeft.GetCurSel();

	// Enable open camera button
	if (m_lfCamID >= 0 && m_riCamID >= 0)
	{
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(TRUE);
	}

	return;
}


void CStereoVisionStudioDlg::OnSelchangeCboCamRight()
{
	// Get left camera ID
	m_riCamID = m_cboCamRight.GetCurSel();

	// Enable open camera button
	if (m_lfCamID >= 0 && m_riCamID >= 0)
	{
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(TRUE);
	}

	return;
}


void CStereoVisionStudioDlg::OnClickedBtnOpencam()
{
	if (m_cameraCount > 1)
	{
		// Open left camera
		if (!m_lfCam.open(m_lfCamID))
		{
			AfxMessageBox(_T("Open left camera failed!"));
			return;
		}

		// Open right camera
		if (!m_riCam.open(m_riCamID))
		{
			AfxMessageBox(_T("Open right camera failed!"));
			return;
		}

		// Enable & Disable some buttons
		GetDlgItem(IDC_BTN_CLOSECAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_PRJ_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CREATE_PRJ)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAP_IMAGE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBO_CAM_LEFT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBO_CAM_RIGHT)->EnableWindow(FALSE);

		// Start timer
		SetTimer(1, 1, NULL);
	}

	return;
}


void CStereoVisionStudioDlg::OnClickedBtnClosecam()
{
	if (m_lfCam.isOpened())
	{
		// Disable Close Camera button
		GetDlgItem(IDC_BTN_CLOSECAM)->EnableWindow(FALSE);

		// Stop timer
		KillTimer(1);

		// Clear all view data
		m_lfImage = Scalar(0);
		ShowImage(m_lfImage, m_copyLfImage, m_hDCLf, m_rectLf);
		m_lfCam.release();

		// Close right camera
		if (m_riCam.isOpened())
		{
			m_riImage = Scalar(0);
			ShowImage(m_riImage, m_copyRiImage, m_hDCRi, m_rectRi);
			m_riCam.release();
		}

		// Enable & Disable some buttons
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBO_CAM_LEFT)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBO_CAM_RIGHT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_PRJ_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_CREATE_PRJ)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAP_IMAGE)->EnableWindow(FALSE);
	}

	return;
}


void CStereoVisionStudioDlg::OnClickedBtnCreatePrj()
{
	// Get project name
	UpdateData(TRUE);

	if (m_editPrjName.GetLength() <= 0)
	{
		AfxMessageBox(_T("Please input project name!"));
		return;
	}

	// Create project directory
	m_prjPath = CCommonUtility::GetCurDirectory();
	m_prjPath += (CString)"\\";
	m_prjPath += m_editPrjName;
	if (PathIsDirectory(m_prjPath))
	{
		AfxMessageBox(_T("Project has already existed!"));
		return;
	}
	if (CreateDirectory(m_prjPath, NULL))
	{
		AfxMessageBox(_T("Project created successfully!"));

		// Reset sample count
		m_editSapCount = 0;

		m_imagelist.clear();

		// Creat XML file
		TiXmlDocument *writeDoc = new TiXmlDocument;
		TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");
		writeDoc->LinkEndChild(decl);
		TiXmlElement *RootElement = new TiXmlElement("opencv_storage");
		writeDoc->LinkEndChild(RootElement);
		TiXmlElement *StuElement = new TiXmlElement("imagelist");
		RootElement->LinkEndChild(StuElement);
		CString xmlFileName = m_prjPath + "\\" + m_editPrjName + ".xml";
		writeDoc->SaveFile(xmlFileName);
		delete writeDoc;
		UpdateData(FALSE);

		return;
	}
}


void CStereoVisionStudioDlg::OnClickedCapImage()
{
	// Save left & right images
	CString strSavePath = m_prjPath;
	strSavePath += (CString)"\\";
	strSavePath += CConvertUtility::ToString(m_editSapCount);
	m_imagelist.push_back(strSavePath + (CString)"-l.png");
	m_imagelist.push_back(strSavePath + (CString)"-r.png");
	cvSaveImage(strSavePath + "-l.png", &m_copyLfImage);
	cvSaveImage(strSavePath + "-r.png", &m_copyRiImage);
	MessageBox(_T("Successfully saved!"));

	// Sample count auto-incrementing
	m_editSapCount++;
	UpdateData(FALSE);

	return;
}


void CStereoVisionStudioDlg::OnClickedBtnDefaultCalPara()
{
	m_editNx = 9;
	m_editNy = 6;
	m_editSquareSize = 26;

	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedBtnCalibration()
{
	// Get parameters
	UpdateData(TRUE);

	CStereoCalibPara calPara;
	calPara.prjName = m_prjPath;
	calPara.nx = m_editNx;
	calPara.ny = m_editNy;
	calPara.squareSize = m_editSquareSize;
	calPara.calibMethodID = m_radMethod;
	calPara.imagelist = m_imagelist;
	calPara.displayCorners = m_chcShowCorner;
	calPara.showRectified = m_chcShowCal;

	CStereoCalib cal;
	cal.Calibration(calPara);
}


void CStereoVisionStudioDlg::OnBnClickedBtnMarch()
{
	m_matchFlag = true;

	// Enable & Disable some buttons
	GetDlgItem(IDC_BTN_MARCH)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP_MATCH)->EnableWindow(TRUE);
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedBtnStopMatch()
{
	m_matchFlag = false;

	// Enable & Disable some buttons
	GetDlgItem(IDC_BTN_MARCH)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_STOP_MATCH)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedSelectPrj()
{
	char szPath[MAX_PATH];
	CString str;

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = "Please select project.";
	bi.ulFlags = 0;
	bi.lpfn = 0;
	bi.lParam = 0;

	LPITEMIDLIST lp = SHBrowseForFolder(&bi);
	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		str.Format("%s", szPath);
		m_editPrjPath = str;
		m_prjPath = str;
		UpdateData(FALSE);
	}
	else 
	{
		AfxMessageBox("Invalid path.");
	}
}


void CStereoVisionStudioDlg::OnBnClickedBtnDefaultMatch()
{
	m_editBlockSize = 17;
	m_editMaxDisparity = 128;
	m_editMinDisparity = 0;
	m_editTextThres = 10;
	m_editScaleFactor = 1;
	m_editPreCap = 31;
	m_editUniqeRatio = 15;
	m_editSpeckeWinSize = 100;
	m_editSpeckleRange = 32;
	m_editMaxDiff = 1;

	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedBtnSelectPrjCal()
{
	// Select project path
	char szPath[MAX_PATH];
	CString str;

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = "Please select project.";
	bi.ulFlags = 0;
	bi.lpfn = 0;
	bi.lParam = 0;

	LPITEMIDLIST lp = SHBrowseForFolder(&bi);
	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		str.Format("%s", szPath);
		m_editPrjPath = str;
		m_prjPath = str;
	}
	else
	{
		AfxMessageBox("Invalid path.");
	}

	// Get current images
	CCommonUtility::GetFiles(m_prjPath, "*.png", m_imagelist);

	// Get XML file
	vector<CString> xmlFiles;
	if (CCommonUtility::GetFiles(m_prjPath, "*.xml", xmlFiles))
	{
		m_editPrjName = CCommonUtility::GetFileName(xmlFiles[0], false);
		m_prjPath = CCommonUtility::GetCurDirectory();
		m_prjPath += (CString)"\\";
		m_prjPath += m_editPrjName;
	}
	
	UpdateData(FALSE);
}
