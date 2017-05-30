#pragma once
#include "stdafx.h"
#include  <string.h>  
#include  <string>  
#include  <vector>
#include  "shlwapi.h"
#include <io.h>

using namespace std;

class CCommonUtility
{
public:
	CCommonUtility();
	~CCommonUtility();

	static CString GetCurDirectory(HMODULE hInstance = NULL);

	static CString GetParentDirectory(HMODULE hInstance = NULL);

	static CString GetCurrentFullName(HMODULE hInstance = NULL);

	static bool GetFiles(const TCHAR* path, const TCHAR* ext, vector<CString> &files);

	static CString GetFileName(const TCHAR* filePath, bool bIncludeExt);

	static void SaveTextFile(const TCHAR* fileName, const vector<CString> &lines, bool bAppendMode = false);

	static bool LoadTextFile(const TCHAR* fileName, vector<CString> &lines);
};

