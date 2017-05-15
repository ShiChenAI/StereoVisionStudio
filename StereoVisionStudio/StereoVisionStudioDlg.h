
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
	int m_cameraCount = 0;		// Number of Cameras
	int m_lfCamID = -1;			// Left camera ID
	int m_riCamID = -1;			// Right camera ID
	CString m_prjPath = NULL;	// Current project path
	vector<CString> m_imagelist;// Image List for calibration

	// OpenCV VideoCapture parameters
	VideoCapture m_lfCam;
	VideoCapture m_riCam;
	Mat m_lfImage;
	Mat m_riImage;
	IplImage m_copyLfImage;
	IplImage m_copyRiImage;

	// Picture Control parameters
	HDC m_hDCLf;
	CRect m_rectLf;
	CDC *m_pDCLf;
	CWnd *m_pwndLf;
	HDC m_hDCRi;
	CRect m_rectRi;
	CDC *m_pDCRi;
	CWnd *m_pwndRi;

	// Draw image to Picture Control
	void ShowImage(Mat &frame, IplImage &image, HDC &hdc, CRect &rect);

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
	int m_radMatchMethod;
	afx_msg void OnBnClickedBtnMarch();
};
