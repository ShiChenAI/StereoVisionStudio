#include "stdafx.h"
#include "StereoMatch.h"


CStereoMatch::CStereoMatch()
{
}


CStereoMatch::~CStereoMatch()
{
}

void CStereoMatch::Calculation(CStereoMatchPara para, Mat &result)
{
	enum { STEREO_BM = 0, STEREO_SGBM = 1, STEREO_HH = 2, STEREO_VAR = 3, STEREO_3WAY = 4 };
	int alg;
	float scale;
	Mat leftImage;
	Mat rightImage;
	Ptr<StereoBM> bm = StereoBM::create(16, 9);
	Ptr<StereoSGBM> sgbm = StereoSGBM::create(0, 16, 3);

	// Algorithm parameters
	int SADWindowSize;										/* Defines the size of both the support window in the left image and the correlation
															   window in the right image.Window sizes are odd numbers like 9x9, 21x21, 41x41, etc.
															   A smaller window size might increase the number of mismatches while a bigger window
															   slows down the computation while giving a smoother disparity map. */

	int numberOfDisparities;								/* This value controls the searching range along scan line.Since disparity is inversely
															   proportional to object distance, usually a smaller value of numberOfDisparities
															   is chosen if we want to see things far away, while a larger value is chosen
															   if we want to see things close up. */

	int minDisparity;										/* Minimum disparity decides the starting position for the matching process.
															   Its value defaults to 0, meaning that the search in the right image will 
															   start at exactly the same pixel position as in the left image. */

	int preFilterCap;										/* Defines the window size for the averaging operator. Its value varies from
															   5x5 to 21x21.The pre-filter normalizes pixelÅfs intensity with the average intensity 
															   within its window.The purpose of this operator is to reduce light disturbances 
															   and enhance texture. */

	int textureThreshold;									/* Disparity is only computed for pixels within a textured enough region.
															   Its default value is 12. This prevents any ambiguous match in flat areas. */

	int uniquenessRatio;									/* It controls the screening criteria for disparity candidates.A strong
															   candidate should have a global minimum SAD value within the whole search range.
															   The default value of uniquenessRatio is 12. */
	int speckleWindowSize;
	int speckleRange;
	int disp12MaxDiff;

	// Read parameters
	string intrinsicFilename = para.intrinsicFilename.GetBuffer(0);
	string extrinsicFilename = para.extrinsicFilename.GetBuffer(0);
	numberOfDisparities = para.maxDisparity;	
	SADWindowSize = para.blockSize;				
	scale = para.scaleFactor;
	alg = para.algorithm;
	minDisparity = para.minDisparity;
	preFilterCap = para.preFilterCap;
	textureThreshold = para.textureThreshold;
	uniquenessRatio = para.uniquenessRatio;
	speckleWindowSize = para.speckleWindowSize;
	speckleRange = para.speckleRange;
	disp12MaxDiff = para.disp12MaxDiff;

	// Read left image & right image
	int color_mode = -1;
	if (alg == STEREO_BM)	// Image need to be converted to gray in BM algorithm
	{
		cvtColor(para.leftImage, leftImage, CV_BGR2GRAY);
		cvtColor(para.rightImage, rightImage, CV_BGR2GRAY);
	}
	else
	{
		para.leftImage.copyTo(leftImage);
		para.rightImage.copyTo(rightImage);
	}

	if (leftImage.empty())
	{
		printf("Could not load left image file\n");
		return;
	}
	if (rightImage.empty())
	{
		printf("Could not load right image file\n");
		return;
	}

	// Image resize
	if (scale != 1.f)
	{
		Mat temp1, temp2;
		int method = scale < 1 ? INTER_AREA : INTER_CUBIC;
		resize(leftImage, temp1, Size(), scale, scale, method);
		leftImage = temp1;
		resize(rightImage, temp2, Size(), scale, scale, method);
		rightImage = temp2;
	}

	Size img_size = leftImage.size();

	Rect roi1, roi2;
	Mat Q;

	// Reading calibration files
	if (!intrinsicFilename.empty())
	{
		// Reading intrinsic parameters
		FileStorage fs(intrinsicFilename, FileStorage::READ);
		if (!fs.isOpened())
		{
			printf("Failed to open file %s\n", intrinsicFilename.c_str());
			return;
		}

		Mat M1, D1, M2, D2;
		fs["M1"] >> M1;
		fs["D1"] >> D1;
		fs["M2"] >> M2;
		fs["D2"] >> D2;

		M1 *= scale;
		M2 *= scale;

		// Reading extrinsic parameters
		fs.open(extrinsicFilename, FileStorage::READ);
		if (!fs.isOpened())
		{
			printf("Failed to open file %s\n", extrinsicFilename.c_str());
			return;
		}

		Mat R, T, R1, P1, R2, P2;
		fs["R"] >> R;
		fs["T"] >> T;

		stereoRectify(M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2);

		Mat map11, map12, map21, map22;
		initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
		initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

		Mat img1r, img2r;
		remap(leftImage, img1r, map11, map12, INTER_LINEAR);
		remap(rightImage, img2r, map21, map22, INTER_LINEAR);

		leftImage = img1r;
		rightImage = img2r;
	}

	numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((img_size.width / 8) + 15) & -16;

	//bm->setROI1(roi1);
	//bm->setROI2(roi2);
	//bm->setPreFilterCap(31);
	//bm->setBlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
	//bm->setMinDisparity(0);
	//bm->setNumDisparities(numberOfDisparities);
	//bm->setTextureThreshold(10);
	//bm->setUniquenessRatio(15);
	//bm->setSpeckleWindowSize(100);
	//bm->setSpeckleRange(32);
	//bm->setDisp12MaxDiff(1);

	//sgbm->setPreFilterCap(63);
	//int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
	//sgbm->setBlockSize(sgbmWinSize);

	//int cn = leftImage.channels();

	//sgbm->setP1(8 * cn*sgbmWinSize*sgbmWinSize);
	//sgbm->setP2(32 * cn*sgbmWinSize*sgbmWinSize);
	//sgbm->setMinDisparity(0);
	//sgbm->setNumDisparities(numberOfDisparities);
	//sgbm->setUniquenessRatio(10);
	//sgbm->setSpeckleWindowSize(100);
	//sgbm->setSpeckleRange(32);
	//sgbm->setDisp12MaxDiff(1);

	// BM parameters
	bm->setROI1(roi1);
	bm->setROI2(roi2);
	bm->setPreFilterCap(preFilterCap);
	bm->setBlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
	bm->setMinDisparity(minDisparity);
	bm->setNumDisparities(numberOfDisparities);
	bm->setTextureThreshold(textureThreshold);
	bm->setUniquenessRatio(uniquenessRatio);
	bm->setSpeckleWindowSize(speckleWindowSize);
	bm->setSpeckleRange(speckleRange);
	bm->setDisp12MaxDiff(disp12MaxDiff);

	// SGBM parameters
	sgbm->setPreFilterCap(preFilterCap);
	int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
	sgbm->setBlockSize(sgbmWinSize);

	int cn = leftImage.channels();

	sgbm->setP1(8 * cn*sgbmWinSize*sgbmWinSize);
	sgbm->setP2(32 * cn*sgbmWinSize*sgbmWinSize);
	sgbm->setMinDisparity(minDisparity);
	sgbm->setNumDisparities(numberOfDisparities);
	sgbm->setUniquenessRatio(uniquenessRatio);
	sgbm->setSpeckleWindowSize(speckleWindowSize);
	sgbm->setSpeckleRange(speckleRange);
	sgbm->setDisp12MaxDiff(disp12MaxDiff);

	if (alg == STEREO_HH)
	{
		sgbm->setMode(StereoSGBM::MODE_HH);
	}	
	else if (alg == STEREO_SGBM)
	{
		sgbm->setMode(StereoSGBM::MODE_SGBM);
	}		
	else if (alg == STEREO_3WAY)
	{
		sgbm->setMode(StereoSGBM::MODE_SGBM_3WAY);
	}

	Mat disp, disp8;
	//Mat img1p, img2p, dispp;
	//copyMakeBorder(img1, img1p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);
	//copyMakeBorder(img2, img2p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);

	// Match calculating
	int64 t = getTickCount();
	if (alg == STEREO_BM)
	{
		bm->compute(leftImage, rightImage, disp);
	}		
	else if (alg == STEREO_SGBM || alg == STEREO_HH || alg == STEREO_3WAY)
	{
		sgbm->compute(leftImage, rightImage, disp);
	}	
	t = getTickCount() - t;
	printf("Time elapsed: %fms\n", t * 1000 / getTickFrequency());

	//disp = dispp.colRange(numberOfDisparities, img1p.cols);
	if (alg != STEREO_VAR)
	{
		disp.convertTo(disp8, CV_8U, 255 / (numberOfDisparities*16.));
	}	
	else
	{
		disp.convertTo(disp8, CV_8U);
	}

	// Calculating result
	result = disp8;

	//if (!no_display)
	//{
	//	namedWindow("left", 1);
	//	imshow("left", img1);
	//	namedWindow("right", 1);
	//	imshow("right", img2);
	//	namedWindow("disparity", 0);
	//	imshow("disparity", disp8);
	//	printf("press any key to continue...");
	//	fflush(stdout);
	//	waitKey();
	//	printf("\n");
	//}

	//if (!disparity_filename.empty())
	//	imwrite(disparity_filename, disp8);
	

	//if (!point_cloud_filename.empty())
	//{
	//	printf("storing the point cloud...");
	//	fflush(stdout);
	//	Mat xyz;
	//	reprojectImageTo3D(disp, xyz, Q, true);
	//	saveXYZ(point_cloud_filename.c_str(), xyz);
	//	printf("\n");
	//}

	return;
}