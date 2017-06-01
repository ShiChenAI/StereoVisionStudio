#include "stdafx.h"
#include "ImageProcessing.h"


CImageProcessing::CImageProcessing()
{
}


CImageProcessing::~CImageProcessing()
{
}

void CImageProcessing::BackgroundSubtraction(Ptr<BackgroundSubtractor> bgModel, Mat & srcImg, Mat & fgMask, Mat & fgImg, bool smoothMask)
{
	if (srcImg.empty())
	{
		return;
	}

	//update the model
	bgModel->apply(srcImg, fgMask, -1);
	if (smoothMask)
	{
		GaussianBlur(fgMask, fgMask, Size(11, 11), 3.5, 3.5);
		threshold(fgMask, fgMask, 10, 255, THRESH_BINARY);
	}

	fgImg = Scalar::all(0);
	srcImg.copyTo(fgImg, fgMask);
}
