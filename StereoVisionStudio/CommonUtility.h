#pragma once
#include "stdafx.h"
#include  <string.h>  
#include  <string>  

class CCommonUtility
{
public:
	CCommonUtility();
	~CCommonUtility();

	static CString GetCurDirectory(HMODULE hInstance = NULL);

	static CString GetParentDirectory(HMODULE hInstance = NULL);

	static CString GetCurrentFullName(HMODULE hInstance = NULL);
};

