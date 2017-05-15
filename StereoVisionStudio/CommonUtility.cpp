#include "stdafx.h"
#include "CommonUtility.h"


CCommonUtility::CCommonUtility()
{
}


CCommonUtility::~CCommonUtility()
{
}

CString CCommonUtility::GetCurDirectory(HMODULE hInstance)
{
	TCHAR szPath[256];
	GetModuleFileName(hInstance, szPath, sizeof(szPath));
	*(_tcsrchr(szPath, '\\')) = 0;

	CString strResult = szPath;
	//strResult += "\\";

	return strResult;
}

CString CCommonUtility::GetParentDirectory(HMODULE hInstance)
{
	TCHAR szPath[256];
	GetModuleFileName(hInstance, szPath, sizeof(szPath));
	//*(strrchr(szPath, '\\')) = 0;

	CString strResult = szPath;

	return strResult;
}

CString CCommonUtility::GetCurrentFullName(HMODULE hInstance)
{
	TCHAR szPath[256];
	GetModuleFileName(hInstance, szPath, sizeof(szPath));
	*(_tcsrchr(szPath, '\\')) = 0;		
	*(_tcsrchr(szPath, '\\')) = 0;		

	CString strResult = szPath;

	return strResult;
}
