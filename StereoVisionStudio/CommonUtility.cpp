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

bool CCommonUtility::GetFiles(const TCHAR * path, const TCHAR * ext, vector<CString>& files)
{
	files.clear();

	if (::SetCurrentDirectory(path))
	{
		CFileFind ff;
		BOOL bWorking = ff.FindFile(ext);
		while (bWorking)
		{
			bWorking = ff.FindNextFile();
			if (ff.IsDots() || ff.IsDirectory())
			{
				continue;
			}
			else
			{
				files.push_back(ff.GetFilePath());
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

CString CCommonUtility::GetFileName(const TCHAR * filePath, bool bIncludeExt)
{
	CString strFilePath = filePath;
	int pos = -1;
	CString fileName;
	if (!bIncludeExt)
	{
		pos = strFilePath.ReverseFind(TEXT('.'));

		if (pos >= 0)
		{
			strFilePath = strFilePath.Left(pos);
		}
	}

	pos = strFilePath.ReverseFind(TEXT('\\'));
	if (pos >= 0)
	{
		fileName = strFilePath.Right(strFilePath.GetLength() - pos - 1);
	}

	return fileName;
}
