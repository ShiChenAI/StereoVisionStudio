
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
	, m_imageSource(0)
	, m_staticBlockSize(_T(""))
	, m_staticMaxDiff(_T(""))
	, m_staticMaxDisparity(_T(""))
	, m_staticMinDisparity(_T(""))
	, m_staticPreCap(_T(""))
	, m_staticScale(_T(""))
	, m_staticSpeckleRange(_T(""))
	, m_staticSpeckleWinSize(_T(""))
	, m_staticTextThrs(_T(""))
	, m_staticUniqRatio(_T(""))
	, m_editResultName(_T(""))
	, m_chcUseBackSub(FALSE)
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
	DDX_Control(pDX, IDC_SLIDE_MAX_DISPARITY, m_sliderMaxDisparity);
	DDX_Control(pDX, IDC_SLIDER_BLOCK_SIZE, m_sliderBlockSize);
	DDX_Control(pDX, IDC_SLIDER_MAX_DIFF, m_sliderMaxDiff);
	DDX_Control(pDX, IDC_SLIDER_MIN_DISPARITY, m_sliderMinDisparity);
	DDX_Control(pDX, IDC_SLIDER_PRE_CAP, m_sliderPreCap);
	DDX_Control(pDX, IDC_SLIDER_SCALE_FACTOR, m_sliderScaleFactor);
	DDX_Control(pDX, IDC_SLIDER_SPECKLE_RANGE, m_sliderSpeckleRange);
	DDX_Control(pDX, IDC_SLIDER_SPECKLE_WIN_SIZE, m_sliderSpeckleWinSize);
	DDX_Control(pDX, IDC_SLIDER_TEXT_THRES, m_sliderTextThres);
	DDX_Control(pDX, IDC_SLIDER_UNIQE_RATIO, m_sliderUniqeRatio);
	DDX_Radio(pDX, IDC_RAD_FROM_CAMERA, m_imageSource);
	DDX_Text(pDX, IDC_STATIC_BLOCK_SIZE, m_staticBlockSize);
	DDX_Text(pDX, IDC_STATIC_MAX_DIFF, m_staticMaxDiff);
	DDX_Text(pDX, IDC_STATIC_MAX_DISPARITY, m_staticMaxDisparity);
	DDX_Text(pDX, IDC_STATIC_MIN_DISPARITY, m_staticMinDisparity);
	DDX_Text(pDX, IDC_STATIC_PRE_CAP, m_staticPreCap);
	DDX_Text(pDX, IDC_STATIC_SCALE, m_staticScale);
	DDX_Text(pDX, IDC_STATIC_SPECKLE_RANGE, m_staticSpeckleRange);
	DDX_Text(pDX, IDC_STATIC_SPECKLE_WIN_SIZE, m_staticSpeckleWinSize);
	DDX_Text(pDX, IDC_STATIC_TEXT_THRS, m_staticTextThrs);
	DDX_Text(pDX, IDC_STATIC_UNIQ_RATIO, m_staticUniqRatio);
	DDX_Control(pDX, IDC_CBO_CAMERA_RESOLUTION, m_cboCameraResolution);
	DDX_Text(pDX, IDC_EDIT_RESULT_NAME, m_editResultName);
	DDX_Check(pDX, IDC_CHC_USE_BACK_SUB, m_chcUseBackSub);
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
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RAD_BM, &CStereoVisionStudioDlg::OnBnClickedRadBm)
	ON_BN_CLICKED(IDC_RAD_SGBM, &CStereoVisionStudioDlg::OnBnClickedRadSgbm)
	ON_BN_CLICKED(IDC_RAD_HH, &CStereoVisionStudioDlg::OnBnClickedRadHh)
	ON_BN_CLICKED(IDC_RAD_VAR, &CStereoVisionStudioDlg::OnBnClickedRadVar)
	ON_BN_CLICKED(IDC_RAD_CGBM3WAYS, &CStereoVisionStudioDlg::OnBnClickedRadCgbm3ways)
	ON_BN_CLICKED(IDC_RAD_BOUGUET, &CStereoVisionStudioDlg::OnBnClickedRadBouguet)
	ON_BN_CLICKED(IDC_RAD_HARTLEY, &CStereoVisionStudioDlg::OnBnClickedRadHartley)
	ON_BN_CLICKED(IDC_RAD_FROM_CAMERA, &CStereoVisionStudioDlg::OnBnClickedRadFromCamera)
	ON_BN_CLICKED(IDC_RAD_FROM_IMAGE, &CStereoVisionStudioDlg::OnBnClickedRadFromImage)
	ON_CBN_SELCHANGE(IDC_CBO_CAMERA_RESOLUTION, &CStereoVisionStudioDlg::OnCbnSelchangeCboCameraResolution)
	ON_BN_CLICKED(IDC_BTN_SAVE_RESULTS, &CStereoVisionStudioDlg::OnBnClickedBtnSaveResults)
	ON_BN_CLICKED(IDC_CHC_USE_BACK_SUB, &CStereoVisionStudioDlg::OnBnClickedChcUseBackSub)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,
};

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

	// Initializing combobox
	InitCombobox();

	// Disable button
	GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CLOSECAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PRJ_NAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CREATE_PRJ)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAP_IMAGE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP_MATCH)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SAVE_RESULTS)->EnableWindow(FALSE);

	// Defaults to using BOUGUET's method for calibration
	m_radMethod = 0;

	// Defaults to showing calibration results
	m_chcShowCal = true;
	m_chcShowCorner = true;

	// Defaults to using BM method for match
	m_radMatchMethod = 0;

	// Defaults to using camera as image source
	m_imageSource = 0;

	// Camera view windows parameters initiating
	m_pwndLf = GetDlgItem(IDC_PIC_LEFT_CAM);
	m_pDCLf = m_pwndLf->GetDC();
	m_hDCLf = m_pDCLf->GetSafeHdc();
	m_pwndLf->GetClientRect(&m_rectLf);

	m_pwndRi = GetDlgItem(IDC_PIC_RIGHT_CAM);
	m_pDCRi = m_pwndRi->GetDC();
	m_hDCRi = m_pDCRi->GetSafeHdc();
	m_pwndRi->GetClientRect(&m_rectRi);
	
	m_pwndDs = GetDlgItem(IDC_PIC_DISPARITY_CAM);
	m_pDCDs = m_pwndDs->GetDC();
	m_hDCDs = m_pDCDs->GetSafeHdc();
	m_pwndDs->GetClientRect(&m_rectDs);

	// Initialize Slider
	InitSliders();

	// Initialize Statusbar
	InitStatusbar();

	// Set default parameters
	SetMatchDefaultPara();
	SetCalDefaultPara();

	// Start timer
	SetTimer(1, 50, NULL);

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

void CStereoVisionStudioDlg::InitCombobox()
{
	// Get cameras list
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

	// Set resolution list: 320 * 240;352 * 288;640 * 480;
	m_cboCameraResolution.AddString(TEXT("320 * 240"));
	m_cboCameraResolution.AddString(TEXT("352 * 288"));
	m_cboCameraResolution.AddString(TEXT("640 * 480"));
}

void CStereoVisionStudioDlg::InitStatusbar()
{
	m_Statusbar.Create(this);
	m_Statusbar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
	CRect rect;
	GetWindowRect(rect);
	//m_Statusbar.SetPaneInfo(0, ID_SEPARATOR, SBPS_STRETCH, rect.Width() / 4);
	m_Statusbar.SetPaneInfo(0, ID_SEPARATOR, SBPS_STRETCH, rect.Width());
	m_Statusbar.SetPaneText(0, "Ready.");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
}

void CStereoVisionStudioDlg::InitSliders()
{
	// BlockSize: 
	// BM: 5X5~255X255 (usually 5X5~21X21)
	// SGBM: 1X1~11X11 (usually 3X3~11X11)
	m_sliderBlockSize.SetRange(2, 127);

	// Max disparity: 16~256
	m_sliderMaxDisparity.SetRange(1, 16);

	// Min disparity: -64~64 (default: 0)
	m_sliderMinDisparity.SetRange(-64, 64);

	// Texture threshold: 0~60
	m_sliderTextThres.SetRange(0, 60);

	// Scale factor: 0.1~2
	m_sliderScaleFactor.SetRange(1, 20);

	// Pre-filter cap: 1~63
	m_sliderPreCap.SetRange(0, 31);

	// Uniqueness ratio: 0~100 (usually 5-15)
	m_sliderUniqeRatio.SetRange(0, 100);

	// Speckle Window Size: 3X3~99X99
	m_sliderSpeckleWinSize.SetRange(0, 49);

	// Speckle Range: 0~50 (default: 4)
	m_sliderSpeckleRange.SetRange(0, 50);

	// disp12MaxDiff: -1~1 (default: -1)
	m_sliderMaxDiff.SetRange(-1, 1);
}

void CStereoVisionStudioDlg::SetMatchDefaultPara()
{
	if (m_radMatchMethod == 0)
	{
		m_staticBlockSize = TEXT("(usually 5X5~21X21, default: 17X17)");
		m_editBlockSize = 17;
		m_sliderBlockSize.SetPos(8);

		m_staticMaxDisparity = TEXT("(default: 128)");
		m_editMaxDisparity = 128;
		m_sliderMaxDisparity.SetPos(8);

		m_staticMinDisparity = TEXT("(default: 0)");
		m_editMinDisparity = 0;
		m_sliderMinDisparity.SetPos(0);

		m_staticTextThrs = TEXT("(default: 10)");
		m_editTextThres = 10;
		m_sliderTextThres.SetPos(10);

		m_staticScale = TEXT("(default: 1)");
		m_editScaleFactor = 1;
		m_sliderScaleFactor.SetPos(10);

		m_staticPreCap = TEXT("(default: 31)");
		m_editPreCap = 31;
		m_sliderPreCap.SetPos(15);

		m_staticUniqRatio = TEXT("(usually 5~15, default: 15)");
		m_editUniqeRatio = 15;
		m_sliderUniqeRatio.SetPos(15);

		m_staticSpeckleWinSize = TEXT("(default: 99)");
		m_editSpeckeWinSize = 99;
		m_sliderSpeckleWinSize.SetPos(49);

		m_staticSpeckleRange = TEXT("(default: 4)");
		m_editSpeckleRange = 4;
		m_sliderSpeckleRange.SetPos(4);

		m_staticMaxDiff = TEXT("(default: -1)");
		m_editMaxDiff = -1;
		m_sliderMaxDiff.SetPos(-1);
	}
	else if (m_radMatchMethod == 1 || m_radMatchMethod == 2 || m_radMatchMethod == 4)
	{
		m_staticBlockSize = TEXT("(usually 3X3~11X11, default: 7X7)");
		m_editBlockSize = 7;
		m_sliderBlockSize.SetPos(3);

		m_staticMaxDisparity = TEXT("(default: 128)");
		m_editMaxDisparity = 128;
		m_sliderMaxDisparity.SetPos(8);

		m_staticMinDisparity = TEXT("(default: 0)");
		m_editMinDisparity = 0;
		m_sliderMinDisparity.SetPos(0);

		m_staticTextThrs = TEXT("(default: 10)");
		m_editTextThres = 10;
		m_sliderTextThres.SetPos(10);

		m_staticScale = TEXT("(default: 1)");
		m_editScaleFactor = 1;
		m_sliderScaleFactor.SetPos(10);

		m_staticPreCap = TEXT("(default: 63)");
		m_editPreCap = 63;
		m_sliderPreCap.SetPos(31);

		m_staticUniqRatio = TEXT("(usually 5~15, default: 15)");
		m_editUniqeRatio = 10;
		m_sliderUniqeRatio.SetPos(10);

		m_staticSpeckleWinSize = TEXT("(default: 99)");
		m_editSpeckeWinSize = 99;
		m_sliderSpeckleWinSize.SetPos(49);

		m_staticSpeckleRange = TEXT("(default: 4)");
		m_editSpeckleRange = 4;
		m_sliderSpeckleRange.SetPos(4);

		m_staticMaxDiff = TEXT("(default: -1)");
		m_editMaxDiff = -1;
		m_sliderMaxDiff.SetPos(-1);
	}
	else if (m_radMatchMethod == 3)
	{
		m_staticBlockSize = TEXT("(usually 3X3~11X11, default: 7X7)");
		m_editBlockSize = 7;
		m_sliderBlockSize.SetPos(3);

		m_staticMaxDisparity = TEXT("(default: 128)");
		m_editMaxDisparity = 128;
		m_sliderMaxDisparity.SetPos(8);

		m_staticMinDisparity = TEXT("(default: -64)");
		m_editMinDisparity = -64;
		m_sliderMinDisparity.SetPos(-64);

		m_staticTextThrs = TEXT("(default: 10)");
		m_editTextThres = 10;
		m_sliderTextThres.SetPos(10);

		m_staticScale = TEXT("(default: 1)");
		m_editScaleFactor = 1;
		m_sliderScaleFactor.SetPos(10);

		m_staticPreCap = TEXT("(default: 63)");
		m_editPreCap = 63;
		m_sliderPreCap.SetPos(31);

		m_staticUniqRatio = TEXT("(usually 5~15, default: 15)");
		m_editUniqeRatio = 10;
		m_sliderUniqeRatio.SetPos(10);

		m_staticSpeckleWinSize = TEXT("(default: 99)");
		m_editSpeckeWinSize = 99;
		m_sliderSpeckleWinSize.SetPos(49);

		m_staticSpeckleRange = TEXT("(default: 4)");
		m_editSpeckleRange = 4;
		m_sliderSpeckleRange.SetPos(4);

		m_staticMaxDiff = TEXT("(default: -1)");
		m_editMaxDiff = -1;
		m_sliderMaxDiff.SetPos(-1);
	}
}

void CStereoVisionStudioDlg::SetCalDefaultPara()
{
	m_editNx = 9;
	m_editNy = 6;
	m_editSquareSize = 26;
}

void CStereoVisionStudioDlg::ReadCalPara()
{
	string intrinsicFilename = m_prjPath + "\\intrinsics.yml";
	string extrinsicFilename = m_prjPath + "\\extrinsics.yml";

	if (!intrinsicFilename.empty())
	{
		// Reading intrinsic parameters
		FileStorage fs(intrinsicFilename, FileStorage::READ);
		if (!fs.isOpened())
		{
			AfxMessageBox(TEXT("Failed to open intrinsic file!"));
			//printf("Failed to open file %s\n", intrinsicFilename.c_str());
			return;
		}
		fs["M1"] >> m_M1;
		fs["D1"] >> m_D1;
		fs["M2"] >> m_M2;
		fs["D2"] >> m_D2;

		// Reading extrinsic parameters
		fs.open(extrinsicFilename, FileStorage::READ);
		if (!fs.isOpened())
		{
			AfxMessageBox(_T("Failed to open extrinsics file!"));
			return;
		}
		fs["R"] >> m_R;
		fs["T"] >> m_T;
	}
}

void CStereoVisionStudioDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (m_imageSource == 0)
	{
		if (m_lfCam.isOpened())
		{
			// Capture frame from camera
			m_lfCam >> m_lfImage;

			// Use Background Subtraction
			if (m_chcUseBackSub)
			{
				Mat fgImg;
				Mat fgMask;
				CImageProcessing::BackgroundSubtraction(m_bgModel, m_lfImage, fgMask, fgImg, true);

				// Draw image to HDC
				ShowImage(fgImg, m_copyLfImage, m_hDCLf, m_rectLf);
			}
			else
			{
				// Draw image to HDC
				ShowImage(m_lfImage, m_copyLfImage, m_hDCLf, m_rectLf);
			}
		}

		if (m_riCam.isOpened())
		{
			// Capture frame from camera
			m_riCam >> m_riImage;

			// Use Background Subtraction
			if (m_chcUseBackSub)
			{
				Mat fgImg;
				Mat fgMask;
				CImageProcessing::BackgroundSubtraction(m_bgModel, m_riImage, fgMask, fgImg, true);

				// Draw image to HDC
				ShowImage(fgImg, m_copyRiImage, m_hDCRi, m_rectRi);
			}
			else
			{
				// Draw image to HDC
				ShowImage(m_riImage, m_copyRiImage, m_hDCRi, m_rectRi);
			}
		}
	}
	else if (m_imageSource == 1)
	{
		string leftImagePath = m_prjPath + "\\left.png";
		string rightImagePath = m_prjPath + "\\right.png";

		m_lfImage = imread(leftImagePath);
		if (m_lfImage.empty())
		{
			m_Statusbar.SetPaneText(0, TEXT("Load left image failed!"));
		}
		else
		{
			// Draw image to HDC
			ShowImage(m_lfImage, m_copyLfImage, m_hDCLf, m_rectLf);
		}

		m_riImage = imread(rightImagePath);
		if (m_riImage.empty())
		{
			m_Statusbar.SetPaneText(0, TEXT("Load right image failed!"));
		}
		else
		{
			// Draw image to HDC
			ShowImage(m_riImage, m_copyRiImage, m_hDCRi, m_rectRi);
		}
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
		matchPara.M1 = m_M1;
		matchPara.M2 = m_M2;
		matchPara.D1 = m_D1;
		matchPara.D2 = m_D2;
		matchPara.R = m_R;
		matchPara.T = m_T;
		//matchPara.intrinsicFilename = m_prjPath + "\\intrinsics.yml";
		//matchPara.extrinsicFilename = m_prjPath + "\\extrinsics.yml";

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
	if (m_lfCamID >= 0 && m_riCamID >= 0 && m_resolution >= 0)
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
	if (m_lfCamID >= 0 && m_riCamID >= 0 && m_resolution >= 0)
	{
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(TRUE);
	}

	return;
}


void CStereoVisionStudioDlg::OnClickedBtnOpencam()
{
	if (m_cameraCount > 1)
	{
		if (m_lfCamID == m_riCamID)
		{
			AfxMessageBox(TEXT("Left camera and right camera can't be the same!"));
			return;
		}

		// Open left camera
		if (!m_lfCam.open(m_lfCamID))
		{
			AfxMessageBox(TEXT("Open left camera failed!"));
			return;
		}
		m_lfCam.set(CV_CAP_PROP_FRAME_WIDTH, m_frameWidth);
		m_lfCam.set(CV_CAP_PROP_FRAME_HEIGHT, m_frameHeight);

		// Open right camera
		if (!m_riCam.open(m_riCamID))
		{
			AfxMessageBox(TEXT("Open right camera failed!"));
			return;
		}
		m_riCam.set(CV_CAP_PROP_FRAME_WIDTH, m_frameWidth);
		m_riCam.set(CV_CAP_PROP_FRAME_HEIGHT, m_frameHeight);

		// Enable & Disable some buttons
		GetDlgItem(IDC_BTN_CLOSECAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_PRJ_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CREATE_PRJ)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAP_IMAGE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBO_CAM_LEFT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBO_CAM_RIGHT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBO_CAMERA_RESOLUTION)->EnableWindow(FALSE);

		// Start timer
		SetTimer(1, 50, NULL);
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
		GetDlgItem(IDC_CBO_CAMERA_RESOLUTION)->EnableWindow(TRUE);
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
	SetCalDefaultPara();

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

		// Reading calibration parameters
		ReadCalPara();

		UpdateData(FALSE);
	}
	else 
	{
		AfxMessageBox("Invalid path.");
	}
}


void CStereoVisionStudioDlg::OnBnClickedBtnDefaultMatch()
{
	SetMatchDefaultPara();

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



void CStereoVisionStudioDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	m_editBlockSize = m_sliderBlockSize.GetPos() * 2 + 1;
	m_editMaxDisparity = m_sliderMaxDisparity.GetPos() * 16;
	m_editMinDisparity = m_sliderMinDisparity.GetPos();
	m_editTextThres = m_sliderTextThres.GetPos();
	m_editScaleFactor = m_sliderScaleFactor.GetPos() / 10.;
	m_editPreCap = m_sliderPreCap.GetPos() * 2 + 1;
	m_editUniqeRatio = m_sliderUniqeRatio.GetPos();
	if (m_sliderSpeckleWinSize.GetPos() != 0)
	{
		m_editSpeckeWinSize = m_sliderSpeckleWinSize.GetPos() * 2 + 1;
	}
	else
	{
		m_editSpeckeWinSize = 0;
	}
	m_editSpeckleRange = m_sliderSpeckleRange.GetPos();
	m_editMaxDiff = m_sliderMaxDiff.GetPos();

	UpdateData(FALSE);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CStereoVisionStudioDlg::OnBnClickedRadBm()
{
	m_radMatchMethod = 0;
	m_sliderBlockSize.SetRange(2, 127);
	SetMatchDefaultPara();
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadSgbm()
{
	m_radMatchMethod = 1;
	m_sliderBlockSize.SetRange(0, 5);
	SetMatchDefaultPara();
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadHh()
{
	m_radMatchMethod = 2;
	m_sliderBlockSize.SetRange(0, 5);
	SetMatchDefaultPara();
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadVar()
{
	m_radMatchMethod = 3;
	m_sliderBlockSize.SetRange(0, 5);
	SetMatchDefaultPara();
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadCgbm3ways()
{
	m_radMatchMethod = 4;
	m_sliderBlockSize.SetRange(0, 5);
	SetMatchDefaultPara();
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadBouguet()
{
	m_radMethod = 0;
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadHartley()
{
	m_radMethod = 1;
	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadFromCamera()
{
	m_imageSource = 0;

	GetDlgItem(IDC_BTN_SAVE_RESULTS)->EnableWindow(FALSE);

	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnBnClickedRadFromImage()
{
	m_imageSource = 1;

	GetDlgItem(IDC_BTN_SAVE_RESULTS)->EnableWindow(TRUE);

	UpdateData(FALSE);
}


void CStereoVisionStudioDlg::OnCbnSelchangeCboCameraResolution()
{
	// Get left camera ID
	int m_resolution = m_cboCameraResolution.GetCurSel();
	switch (m_resolution)
	{
		case 0:
			m_frameWidth = 320;
			m_frameHeight = 240;
			break;
		case 1:
			m_frameWidth = 352;
			m_frameHeight = 288;
			break;
		case 2:
			m_frameWidth = 640;
			m_frameHeight = 480;
			break;
		default:
			m_frameWidth = 352;
			m_frameHeight = 288;
	}

	// Enable open camera button
	if (m_lfCamID >= 0 && m_riCamID >= 0 && m_resolution >= 0)
	{
		GetDlgItem(IDC_BTN_OPENCAM)->EnableWindow(TRUE);
	}

	return;
}


void CStereoVisionStudioDlg::OnBnClickedBtnSaveResults()
{
	// Get result name
	UpdateData(TRUE);

	if (m_editResultName.GetLength() <= 0)
	{
		AfxMessageBox(_T("Please input result name!"));
		return;
	}

	// Create result directory
	m_resultPath = m_prjPath + TEXT("\\");
	m_resultPath += m_editResultName;
	if (PathIsDirectory(m_resultPath))
	{
		AfxMessageBox(_T("Result has already existed!"));
		return;
	}
	if (CreateDirectory(m_resultPath, NULL))
	{
		// Save parameters
		vector<CString> params;
		CString line = TEXT("");
		switch (m_radMatchMethod)
		{
		case 0:
			line = TEXT("Mathod: BM");
			break;
		case 1:
			line = TEXT("Mathod: SGBM");
			break;
		case 2:
			line = TEXT("Mathod: HH");
			break;
		case 3:
			line = TEXT("Mathod: VAR");
			break;
		case 4:
			line = TEXT("Mathod: SGBM 3 ways");
			break;
		default:
			line = TEXT("Mathod: BM");
		}
		params.push_back(line);
		line.Format(TEXT("Result Name: %s"), m_editResultName);
		params.push_back(line);
		line.Format(TEXT("Block Size: %f"), m_editBlockSize);
		params.push_back(line);
		line.Format(TEXT("Max Disparity: %f"), m_editMaxDisparity);
		params.push_back(line);
		line.Format(TEXT("MIn Disparity: %d"), m_editMinDisparity);
		params.push_back(line);
		line.Format(TEXT("Texture Thres: %d"), m_editTextThres);
		params.push_back(line);
		line.Format(TEXT("Scale Factor: %f"), m_editScaleFactor);
		params.push_back(line);
		line.Format(TEXT("Pre-Filter Cap: %d"), m_editPreCap);
		params.push_back(line);
		line.Format(TEXT("Uniqueness Ratio: %d"), m_editUniqeRatio);
		params.push_back(line);
		line.Format(TEXT("Speckle WindowSize: %d"), m_editSpeckeWinSize);
		params.push_back(line);
		line.Format(TEXT("Speckle Range: %d"), m_editSpeckleRange);
		params.push_back(line);
		line.Format(TEXT("Disp12MaxDiff: %d"), m_editMaxDiff);
		params.push_back(line);

		CString txtPath = m_resultPath + TEXT("\\Parameters.txt");
		CCommonUtility::SaveTextFile(txtPath, params);

		// Save image
		CString imagePath = m_resultPath + TEXT("\\Disparity.png");
		cvSaveImage(imagePath, &m_copyDsImage);

		AfxMessageBox(_T("Result saved successfully!"));

		return;
	}
}


void CStereoVisionStudioDlg::OnBnClickedChcUseBackSub()
{
	UpdateData(true);

	if (m_chcUseBackSub)
	{
		m_bgModel = createBackgroundSubtractorMOG2().dynamicCast<BackgroundSubtractor>();
	}
}
