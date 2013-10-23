#pragma once

#include <assert.h>
#include <windows.h>
#include <new>

#define XASSERT		assert
#define XFORCEINL	__forceinline
#define XNOINL		__declspec(noinline)

#define FASTCALL	__fastcall
#define STDCALL		__stdcall

#define XZEROOBJECT(ptr) ::memset(ptr, 0, sizeof(*ptr))


typedef unsigned char uchar, byte;
typedef unsigned short ushort;
typedef unsigned int uint, bln;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef size_t uintptr;
typedef wchar_t wchar;
typedef void* handle;

namespace X
{
	inline size_t NearAlign(size_t n, size_t align)
	{
		return (n + (align - 1)) & ~(align - 1);
	}

	template < typename Type> Type Max(Type a, Type b) { return a > b ? a : b; }
};