#pragma once
#pragma include_alias( "dxtrans.h", "qedit.h" )
#define __IDxtCompositor_INTERFACE_DEFINED__
#define __IDxtAlphaSetter_INTERFACE_DEFINED__
#define __IDxtJpeg_INTERFACE_DEFINED__
#define __IDxtKey_INTERFACE_DEFINED__

#include <atlbase.h>
#include "dshow.h"
#include <windows.h>

using namespace std;

class CVideoUtility
{
public:
	CVideoUtility();
	~CVideoUtility();

	static int GetCameraCount();
	static int GetCameraName(int nCamID, char* sName, int nBufferSize);
};

