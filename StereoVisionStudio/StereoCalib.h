#pragma once
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ConvertUtility.h"
#include "StereoVisionStudioDlg.h"

using namespace std;
using namespace cv;

class CStereoCalibPara
{
public:
	CStereoCalibPara();

	CString prjName;			// Project name
	long nx;					// Corners number x
	long ny;					// Corners number y
	double squareSize;			// Square Size
	int calibMethodID;			// Calibration method ID (0-BOUGUET'S METHOD, 1-HARTLEY'S METHOD)
	vector<CString> imagelist;	// Image list
	bool displayCorners;		// Display corners or not
	bool showRectified;			// Show calibration results or not
};
class CStereoCalib
{
public:
	CStereoCalib();
	~CStereoCalib();

	void Calibration(CStereoCalibPara para);
};

