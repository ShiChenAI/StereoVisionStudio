#pragma once
class CConvertUtility
{
public:
	CConvertUtility();
	~CConvertUtility();

	static CString ToString(long value);
	static CString ToString(DWORD dw);
	static CString ToString(int value);
	static CString ToString(byte value);
	static CString ToString(double value, int precision = 2, bool bEraseZeroTail = false);
	static CString ToString(const CTime &tm);

	static long ToLong(const TCHAR* str);

	static double ToDouble(const TCHAR* str);
};

