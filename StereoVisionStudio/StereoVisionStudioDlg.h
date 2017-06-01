
// StereoVisionStudioDlg.h : header file
//

#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv2/imgproc.hpp>
#include "CvvImage.h"
#include "afxwin.h"
#include "CommonUtility.h"
#include "VideoUtility.h"
#include <stdio.h>
#include <cstring>
#include <io.h> 
#include "ConvertUtility.h"
#include "StereoCalib.h"
#include "StereoMatch.h"
#include "tinyxml.h" 
#include "afxcmn.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/videoio.hpp"
#include "ImageProcessing.h"

using namespace std;
using namespace cv;



// CStereoVisionStudioDlg dialog
class CStereoVisionStudioDlg : public CDialogEx
{
// Construction
public:
	CStereoVisionStudioDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STEREOVISIONSTUDIO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int m_cameraCount = 0;			// Number of Cameras
	int m_lfCamID = -1;				// Left camera ID
	int m_riCamID = -1;				// Right camera ID
	CString m_prjPath = NULL;		// Current project path
	vector<CString> m_imagelist;	// Image List for calibration

	// OpenCV VideoCapture parameters
	VideoCapture m_lfCam;
	VideoCapture m_riCam;
	Mat m_lfImage;
	Mat m_riImage;
	Mat m_dsImage;
	IplImage m_copyLfImage;
	IplImage m_copyRiImage;
	IplImage m_copyDsImage;
	int m_frameWidth;
	int m_frameHeight;

	// Calibration parameters
	Mat m_M1, m_D1, m_M2, m_D2;		// intrinsic parameters
	Mat m_R, m_T;					// extrinsic parameters

	// Picture Control parameters
	HDC m_hDCLf;
	CRect m_rectLf;
	CDC *m_pDCLf;
	CWnd *m_pwndLf;

	HDC m_hDCRi;
	CRect m_rectRi;
	CDC *m_pDCRi;
	CWnd *m_pwndRi;

	HDC m_hDCDs;
	CRect m_rectDs;
	CDC *m_pDCDs;
	CWnd *m_pwndDs;

	Ptr<BackgroundSubtractor> m_bgModel;

	// Drawing image to Picture Control
	void ShowImage(Mat &frame, IplImage &image, HDC &hdc, CRect &rect);

	// Initializing combobox
	void InitCombobox();

	// Initializing Statusbar
	void InitStatusbar();

	// Initializing Sliders
	void InitSliders();

	// Setting match paramaters default
	void SetMatchDefaultPara();

	// Setting calibration paramaters default
	void SetCalDefaultPara();

	// Reading calibration parameters
	void ReadCalPara();

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_cboCamLeft;
	CComboBox m_cboCamRight;
	long m_editNx;				// Board width
	long m_editNy;				// Board height
	CString m_editPrjName;		// Current Project Name
	long m_editSapCount;		// Captured samples count
	double m_editSquareSize;	// Square size
	afx_msg void OnSelchangeCboCamLeft();
	afx_msg void OnSelchangeCboCamRight();
	afx_msg void OnClickedBtnOpencam();
	afx_msg void OnClickedBtnClosecam();
	afx_msg void OnClickedBtnCreatePrj();
	afx_msg void OnClickedCapImage();
	afx_msg void OnClickedBtnDefaultCalPara();
	int m_radMethod;			// Calibration method ID (0-BOUGUET'S METHOD, 1-HARTLEY'S METHOD)
	BOOL m_chcShowCal;			// Show calibration results or not
	afx_msg void OnBnClickedBtnCalibration();
	BOOL m_chcShowCorner;
	double m_editBlockSize;
	double m_editMaxDisparity;
	double m_editScaleFactor;
	int m_radMatchMethod;		// Match method ID (0-BM, 1-SGBM, 2-HH, 3-VAR, 4-SGBM 3ways)
	afx_msg void OnBnClickedBtnMarch();
	bool m_matchFlag = false;
	CString m_editPrjPath;
	afx_msg void OnBnClickedBtnStopMatch();
	afx_msg void OnBnClickedSelectPrj();
	afx_msg void OnBnClickedBtnDefaultMatch();
	long m_editMaxDiff;
	long m_editMinDisparity;
	long m_editPreCap;
	long m_editSpeckleRange;
	long m_editSpeckeWinSize;
	long m_editTextThres;
	long m_editUniqeRatio;
	afx_msg void OnBnClickedBtnSelectPrjCal();
	CStatusBar m_Statusbar;
	CSliderCtrl m_sliderMaxDisparity;
	CSliderCtrl m_sliderBlockSize;
	CSliderCtrl m_sliderMaxDiff;
	CSliderCtrl m_sliderMinDisparity;
	CSliderCtrl m_sliderPreCap;
	CSliderCtrl m_sliderScaleFactor;
	CSliderCtrl m_sliderSpeckleRange;
	CSliderCtrl m_sliderSpeckleWinSize;
	CSliderCtrl m_sliderTextThres;
	CSliderCtrl m_sliderUniqeRatio;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedRadBm();
	afx_msg void OnBnClickedRadSgbm();
	afx_msg void OnBnClickedRadHh();
	afx_msg void OnBnClickedRadVar();
	afx_msg void OnBnClickedRadCgbm3ways();
	afx_msg void OnBnClickedRadBouguet();
	afx_msg void OnBnClickedRadHartley();
	int m_imageSource;
	afx_msg void OnBnClickedRadFromCamera();
	afx_msg void OnBnClickedRadFromImage();
	CString m_staticBlockSize;
	CString m_staticMaxDiff;
	CString m_staticMaxDisparity;
	CString m_staticMinDisparity;
	CString m_staticPreCap;
	CString m_staticScale;
	CString m_staticSpeckleRange;
	CString m_staticSpeckleWinSize;
	CString m_staticTextThrs;
	CString m_staticUniqRatio;
	CComboBox m_cboCameraResolution;
	int m_resolution;			// Resolution ID (0-640 * 480, 1-352 * 288, 2-320 * 240)
	afx_msg void OnCbnSelchangeCboCameraResolution();
	afx_msg void OnBnClickedBtnSaveResults();
	CString m_editResultName;
	CString m_resultPath;
	BOOL m_chcUseBackSub;
	afx_msg void OnBnClickedChcUseBackSub();
};
