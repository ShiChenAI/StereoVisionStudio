#include "stdafx.h"
#include "ConvertUtility.h"


CConvertUtility::CConvertUtility()
{
}


CConvertUtility::~CConvertUtility()
{
}

CString CConvertUtility::ToString(long value)
{
	CString str;
	str.Format(TEXT("%ld"), value);
	return str;
}

CString CConvertUtility::ToString(DWORD dw)
{
	CString str;
	str.Format(TEXT("%d"), dw);
	return str;
}

CString CConvertUtility::ToString(int value)
{
	CString str;
	str.Format(TEXT("%d"), value);
	return str;
}

CString CConvertUtility::ToString(byte value)
{
	CString str;
	str.Format(TEXT("%d"), value);
	return str;
}

CString CConvertUtility::ToString(double value, int precision, bool bEraseZeroTail)
{
	CString strFormat, str;
	strFormat.Format(TEXT("%%.%df"), precision);
	str.Format(strFormat, value);
	if (bEraseZeroTail)
	{
		if (str.Find(TEXT(".")) >= 0)
		{
			str.TrimRight(TEXT("0"));
			str.TrimRight(TEXT("."));
		}
	}

	return str;
}

CString CConvertUtility::ToString(const CTime & tm)
{
	CString str;
	str.Format(TEXT("%d-%02d-%02d %02d:%02d"), tm.GetYear(), tm.GetMonth(), tm.GetDay(), tm.GetHour(), tm.GetMinute());
	return str;
}

long CConvertUtility::ToLong(const TCHAR * str)
{
	return _ttol(str);
}

double CConvertUtility::ToDouble(const TCHAR * str)
{
	TCHAR* pszStop = NULL;
	return _tcstod(str, &pszStop);
}
