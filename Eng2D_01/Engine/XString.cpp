#include "XString.h"

#define X_MSCACHEALIGN
#define X_GCCCACHEALIGN
#define XSTRING_PREFETCH_STR
#define XSTRING_PREFETCH_TBL

namespace X
{
	X_MSCACHEALIGN const bln TblNumber[] = 
	{
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	1,1,1,1,1,1,1,1,	1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,

	} X_GCCCACHEALIGN;


	X_MSCACHEALIGN const bln TblLetter[] = 
	{
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,0,0,0,0,0,
		0,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,

	} X_GCCCACHEALIGN;


	X_MSCACHEALIGN const bln TblSpaceTab[] =
	{
		0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0

	} X_GCCCACHEALIGN;


	X_MSCACHEALIGN const char TblToUpper[] = 
	{
		0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
		36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,
		69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,65,66,67,68,69,
		70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,123,124,125,126,127,128,129,130,131,
		132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,
		157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,
		183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,
		209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,
		235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,

	} X_GCCCACHEALIGN;

	X_MSCACHEALIGN const bln TblUpperLetter[] = 
	{
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,

	} X_GCCCACHEALIGN;

	X_MSCACHEALIGN const char TblToLower[] = 
	{
		0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,
		35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,97,98,
		99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,91,
		92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,
		119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
		144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,
		170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,
		197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,
		225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,

	} X_GCCCACHEALIGN;

	X_MSCACHEALIGN const bln TblLowerLetter[] = 
	{
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,

	} X_GCCCACHEALIGN;



	bln		ChrIsLower(char chr)		{ return TblLowerLetter[chr];	}
	bln		ChrIsUpper(char chr)		{ return TblUpperLetter[chr];	}
	bln		ChrIsLetter(char chr)		{ return TblLetter[chr];		}
	bln		ChrIsNumber(char chr)		{ return TblNumber[chr];		}
	bln		ChrIsSpaceTab(char chr)		{ return TblSpaceTab[chr];		}
	char 	ChrToLower(char chr)		{ return TblToLower[chr]; 		}
	char 	ChrToUpper(char chr)		{ return TblToUpper[chr]; 		}


	size_t StrHash( const char* str )
	{
		XASSERT(str);
		XSTRING_PREFETCH_STR(str);

		size_t hash = 0;
		while (*str)
		{
			hash = ((hash << 5) + hash) + *str;
			str++;
		}
		return hash;
	}

	size_t StrHashI( const char* str )
	{
		XASSERT(str);
		XSTRING_PREFETCH_TBL(TblToLower);
		XSTRING_PREFETCH_STR(str);

		size_t hash = 0;
		while (*str)
		{
			hash = ((hash << 5) + hash) + ChrToLower(*str);
			str++;
		}
		return hash;
	}

	bln StrStartWith( const char* str, const char* subStr )
	{
		XASSERT(str && subStr);

		while(*subStr)
		{
			if(*subStr != *str)
				return false;

			str++;
			subStr++;
		}
		return true;
	}

	bln StrStartWithI( const char* str, const char* subStr )
	{
		XASSERT(str && subStr);
		XSTRING_PREFETCH_TBL(TblToLower);

		while(*subStr)
		{
			if(ChrToLower(*subStr) != ChrToLower(*str))
				return false;

			str++;
			subStr++;
		}
		return true;
	}

	bln StrEqual( const char* a, const char* b )
	{
		XASSERT(a && b);

		if(a == b)
			return true;

		while(*a)
		{
			if(*a != *b)
				return false;
			a++;
			b++;
		}
		return *b == '\0';
	}

	bln StrNEqual( const char* a, const char* b )
	{
		XASSERT(a && b);

		while(*a)
		{
			if(*a != *b)
				return true;
			a++;
			b++;
		}
		return *b != '\0';
	}

	bln StrEqualI( const char* a, const char* b )
	{
		XASSERT(a && b);

		if(a == b)
			return true;

		XSTRING_PREFETCH_TBL(TblToLower);

		while(*a)
		{
			if(ChrToLower(*a) != ChrToLower(*b))
				return false;
			a++;
			b++;
		}
		return *b == '\0';
	}

	bln StrNEqualI( const char* a, const char* b )
	{
		XASSERT(a && b);
		XSTRING_PREFETCH_TBL(TblToLower);


		while(*a)
		{
			if(ChrToLower(*a) != ChrToLower(*b))
				return true;
			a++;
			b++;
		}
		return *b != '\0';
	}

	void StrToLower( char* inOutStr )
	{
		XASSERT(inOutStr);
		XSTRING_PREFETCH_TBL(TblToLower);


		while(*inOutStr)
		{
			*inOutStr = ChrToLower(*inOutStr);
			inOutStr++;
		}
	}

	void StrToLower( const char* src, char* dst )
	{
		XASSERT(dst && src);
		XSTRING_PREFETCH_TBL(TblToLower);


		while(*src)
		{
			*dst = ChrToLower(*src);
			dst++;
			src++;
		}
		*dst = '\0';
	}

	void StrToUpper( char* inOutStr )
	{
		XASSERT(inOutStr);
		XSTRING_PREFETCH_TBL(TblToUpper);

		while(*inOutStr)
		{
			*inOutStr = ChrToUpper(*inOutStr);
			inOutStr++;
		}
	}

	void StrToUpper( const char* src, char* dst )
	{
		XASSERT(dst && src);
		XSTRING_PREFETCH_TBL(TblToUpper);


		while(*src)
		{
			*dst = ChrToUpper(*src);
			dst++;
			src++;
		}
		*dst = '\0';
	}

	char* StrFindFirstChar( const char* str, char chr )
	{
		XASSERT(str);
		while(*str)
		{
			if(*str == chr)
				return (char*)str;
			str++;
		}
		return nullptr;
	}

	char* StrFindLastChar( const char* str, char chr )
	{
		XASSERT(str);
		char* ret = nullptr;
		while(*str)
		{
			if(*str == chr)
				ret = (char*)str;
			str++;
		}
		return ret;
	}

	char* StrFindFirstCharI( const char* str, char chr )
	{
		XASSERT(str);
		XSTRING_PREFETCH_TBL(TblToLower);

		chr = ChrToLower(chr);
		while(*str)
		{
			if(ChrToLower(*str) == chr)
				return (char*)str;
			str++;
		}
		return nullptr;
	}

	char* StrFindLastCharI( const char* str, char chr )
	{
		XASSERT(str);
		XSTRING_PREFETCH_TBL(TblToLower);

		chr = ChrToLower(chr);
		char* ret = nullptr;
		while(*str)
		{
			if(ChrToLower(*str) == chr)
				ret = (char*)str;
			str++;
		}
		return ret;
	}

	char* StrFindFirstStr( const char* str, const char* subStr )
	{
		XASSERT(str && subStr);

		while (*str)
		{
			char* s1 = (char*)str;
			char* s2 = (char*)subStr;

			do
			{
				if(*s2 != *s1) goto SEC2;
				s2++;
				s1++;
			} while(*s2);

			return (char*)str;
SEC2:
			str++;
		}

		return nullptr;
	}

	char* StrFindFirstStrI(const char* str, const char* subStr)
	{
		XASSERT(str && subStr);
		XSTRING_PREFETCH_TBL(TblToLower);

		while (*str)
		{
			char* s1 = (char*)str;
			char* s2 = (char*)subStr;

			do
			{
				if(ChrToLower(*s2) != ChrToLower(*s1)) goto SEC2;
				s2++;
				s1++;
			} while(*s2);

			return (char*)str;
SEC2:
			str++;
		}

		return nullptr;
	}

	char* StrFindLastStr( const char* str, const char* subStr )
	{
		XASSERT(str && subStr);
		char* ret = nullptr;
		while(*str)
		{
			if(*str == *subStr)
			{
				register const char* _str = str + 1;
				register const char* _subStr = subStr + 1;
				while(*_subStr)
				{
					if(*_subStr != *str)
						break;
					_str++;
					_subStr++;
				}
				ret = (char*)str;
			}
			str++;
		}
		return ret;
	}



	void StrTrim( const char* str, char* dst )
	{
		XASSERT(str && dst);
		XSTRING_PREFETCH_TBL(TblSpaceTab);

		while(ChrIsSpaceTab(*str))
			str++;

		const char* _str = str;
		if(*str)
		{
			str++;
			while(*str)
				str++;
			str--;
		}
		else
			goto END;

		while(ChrIsSpaceTab(*str))
			str--;
		str++;

		while(_str != str)
		{
			*dst = *_str;
			_str++;
			dst++;
		}

END:
		*dst = '\0';
	}

	
	void StrTrim( char* inout )
	{
		StrTrimLeft(inout);
		StrTrimRight(inout);
	}



	void StrTrimRight( const char* str, char* dst )
	{
		XASSERT(str && dst);

		const char* _str = str;

		if(*str)
		{
			str++;
			while(*str)
				str++;
			str--;
		}
		else
			goto END;

		XSTRING_PREFETCH_TBL(TblSpaceTab);
		while(ChrIsSpaceTab(*str))
			str--;
		str++;
		while(_str != str)
		{
			*dst = *_str;
			_str++;
			dst++;
		}

END:
		*dst = '\0';
	}

	void StrTrimRight( char* inoutStr )
	{
		XASSERT(inoutStr);

		char* _str = inoutStr;

		if(*inoutStr)
		{
			inoutStr++;
			while(*inoutStr)
				inoutStr++;
			inoutStr--;
		}
		else return;

		XSTRING_PREFETCH_TBL(TblSpaceTab);
		while(ChrIsSpaceTab(*inoutStr))
			inoutStr--;
		inoutStr[1] = '\0';
	}

	void StrTrimLeft( const char* str, char* dst )
	{
		XASSERT(str && dst);
		XSTRING_PREFETCH_TBL(TblSpaceTab);

		while(ChrIsSpaceTab(*str))
			str++;
		while(*str)
		{
			*dst = *str;
			str++;
			dst++;
		}
		*dst = '\0';
	}

	void StrTrimLeft( char* inoutStr )
	{
		XASSERT(inoutStr);
		XSTRING_PREFETCH_TBL(TblSpaceTab);
		char* _str = inoutStr;

		while(ChrIsSpaceTab(*inoutStr))
			inoutStr++;

		size_t n = inoutStr - _str;
		if(n == 0) return;
		while (*inoutStr)
		{
			*(inoutStr - n) = *inoutStr;
			inoutStr++;
		}

		*(inoutStr - n) = '\0';
	}

	void StrCopyLower(const char* src, char* dst)
	{
		XASSERT(src && dst);
		XSTRING_PREFETCH_TBL(TblToLower);

		while (src)
		{
			*dst = ChrToLower(*src);
			src++;
			dst++;
		}
		*dst = '\0';
	}

	void StrCopyUpper(const char* src, char* dst)
	{
		XASSERT(src && dst);
		XSTRING_PREFETCH_TBL(TblToUpper);

		while (src)
		{
			*dst = ChrToUpper(*src);
			src++;
			dst++;
		}
		*dst = '\0';
	}

	void StrReplaceChr( char* str, char targetChar, char replaceChar )
	{
		XASSERT(str);
		while(*str)
		{
			if(*str == targetChar)
				*str = replaceChar;
			str++;
		}
	}

	void StrReplaceChrI( char* str, char targetChar, char replaceChar )
	{
		XASSERT(str);
		XSTRING_PREFETCH_TBL(TblToLower);

		targetChar = ChrToLower(targetChar);
		while(*str)
		{
			if(ChrToLower(*str) == targetChar)
				*str = replaceChar;
			str++;
		}
	}

	char* StrReadLine( const char* str, char* outLine )
	{
		XASSERT(str && outLine);

LOOP:
		if(*str)
		{
			if(*str != '\n')
			{
				*outLine = *str;
				str++;
				outLine++;
				goto LOOP;
			}
			else
			{
				*(outLine - 1) = '\0';
				str++;
				return (char*)str;
			}
		}
		else
		{
			*outLine = '\0';
			return nullptr;
		}
	}

	//TODO : Optimize
	char* StrReadWord( const char* str, char* outWord )
	{
		XASSERT(str && outWord);
		XSTRING_PREFETCH_TBL(TblSpaceTab);

		while(ChrIsSpaceTab(*str) || *str == '\n')
			str++;

		while (*str && !ChrIsSpaceTab(*str) && *str != '\n')
		{
			*outWord = *str;
			str++;
			outWord++;
		}
		*outWord = '\0';

		while(ChrIsSpaceTab(*str) || *str == '\n')
			str++;
		if(str[0])
			return (char*)str;
		return nullptr;
	}

	void StrReadUntil( const char* str, char chr, char* dst )
	{
		XASSERT(str && dst);
		while (*str && *str != chr)
		{
			*dst = *str;
			dst++;
			str++;
		}
		*dst = '\0';
	}

};