#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <assert.h>
#include <windows.h>

#define XASSERT	assert

typedef unsigned char uchar, byte;
typedef unsigned short ushort;
typedef unsigned int uint, bln;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef size_t uintptr;
typedef wchar_t wchar;

namespace X
{
	inline size_t NearAlign(size_t n, size_t align)
	{
		return (n + (align - 1)) & ~(align - 1);
	}

	template < typename T> T Max(T a, T b) { return a > b ? a : b; }
};