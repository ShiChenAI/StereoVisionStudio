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

using namespace std;
using namespace cv;
class CStereoMatchPara
{
	/*  [--algorithm=bm|sgbm|hh|sgbm3way] [--blocksize=<block_size>]\n"
	"[--max-disparity=<max_disparity>] [--scale=scale_factor>] [-i=<intrinsic_filename>] [-e=<extrinsic_filename>]\n"
	"[--no-display] [-o=<disparity_image>] [-p=<point_cloud_file>]/**/
public:
	CString prjName;			// project name
	int algorithm;				// algorithm: 0-BM, 1-SGBM, 2-HH, 3-VAR, 4-SGBM3ways
	int blockSize;				// block size
	int maxDisparity;			// max disparity
	double scaleFactor;			// scale factor
	Mat leftImage;
	Mat rightImage;
	CString intrinsicFilename;
	CString extrinsicFilename;

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

