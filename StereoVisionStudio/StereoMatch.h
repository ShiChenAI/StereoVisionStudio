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
class CStereoMatchPara
{
public:
	CString prjName;			// project name
	int algorithm;				// algorithm: 0-BM, 1-SGBM, 2-HH, 3-VAR, 4-SGBM3ways
	int blockSize;				// block size
	int maxDisparity;			// max disparity
	double scaleFactor;			// scale factor
	Mat leftImage;
	Mat rightImage;
	//CString intrinsicFilename;
	//CString extrinsicFilename;
	// Calibration parameters
	Mat M1, D1, M2, D2;			// intrinsic parameters
	Mat R, T;					// extrinsic parameters

	// Extra algorithm calculating parameters
	int minDisparity;
	int preFilterCap;
	int textureThreshold;
	int uniquenessRatio;
	int speckleWindowSize;
	int speckleRange;
	int disp12MaxDiff;
};

class CStereoMatch
{
public:
	CStereoMatch();
	~CStereoMatch();

	void Calculation(CStereoMatchPara para, Mat &result);
};

