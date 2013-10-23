#pragma once

#include "XBasic.h"


namespace X
{
	size_t			StrHash(const char* str);
	inline size_t	StrLen(const char* str) { return strlen(str); }
	inline char*	StrCopy(const char* src, char* dst) { return strcpy(dst, src); }
};