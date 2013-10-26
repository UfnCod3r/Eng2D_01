#pragma once

#include "XBasic.h"


namespace X
{
	bln			ChrIsLower(char chr);
	bln			ChrIsUpper(char chr);
	bln			ChrIsLetter(char chr);
	bln			ChrIsNumber(char chr);
	bln			ChrIsSpaceTab(char chr);

	char	ChrToLower(char chr);
	char	ChrToUpper(char chr);

	//@NOTE
	//Suffix I == Ignore Case Insensitive

	size_t		StrHash(const char* str);
	size_t		StrHashI(const char* str);
	bln			StrStartWith(const char* str, const char* subStr);
	bln			StrStartWithI(const char* str, const char* subStr);
	bln			StrEqual(const char* a, const char* b);
	bln			StrNEqual(const char* a, const char* b);
	bln			StrEqualI(const char* a, const char* b);
	bln			StrNEqualI(const char* a, const char* b);
	void		StrToLower(char* inOutStr);
	void		StrToLower(const char* str, char* dst);
	void		StrToUpper(char* inOutStr);
	void		StrToUpper(const char* str, char* dst);
	void		StrTrim(const char* str, char* dst);
	void		StrTrim(char* inout);
	void		StrTrimRight(const char* str, char* dst);
	void		StrTrimRight(char* inout);
	void		StrTrimLeft(const char* str, char* dst);
	void		StrTrimLeft(char* inout);

	void		StrReadUntil(const char* str, char chr, char* dst);

	inline size_t		StrLen(const char* str)							{ return ::strlen(str);				}
	inline int			StrCmp(const char* str1, const char* str2)		{ return ::strcmp(str1, str2);		}
	inline int			StrCmpI(const char* str1, const char* str2)		{ return ::stricmp(str1, str2);		}
	inline char*		StrCopy(const char* src, char* dst)				{ return ::strcpy(dst, src);		}

	void		StrCopyLower(const char* src, char* dst);
	void		StrCopyUpper(const char* src, char* dst);

	char*		StrFindFirstChar(const char* str, char chr);
	char*		StrFindLastChar(const char* str, char chr);
	char*		StrFindFirstCharI(const char* str, char chr);
	char*		StrFindLastCharI(const char* str, char chr);

	char*		StrFindFirstStr(const char* str, const char* subStr);
	char*		StrFindFirstStrI(const char* str, const char* subStr);

	char*		StrReadLine(const char* str, char* outLine);
	char*		StrReadWord(const char* str, char* outWord);
};