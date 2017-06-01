#pragma once
#include "opencv2/core.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;
class CImageProcessing
{
public:
	CImageProcessing();
	~CImageProcessing();

	static void BackgroundSubtraction(Ptr<BackgroundSubtractor> bgModel, Mat &srcImg, Mat &fgMask, Mat &fgImg, bool smoothMask);
};

