#pragma once

#include <assert.h>
#include <windows.h>
#include <new>
#include <iostream>

#define XASSERT		assert
#define XFORCEINL	__forceinline
#define XNOINL		__declspec(noinline)

#define FASTCALL	__fastcall
#define STDCALL		__stdcall

#define XZEROOBJECT(ptr) ::memset(ptr, 0, sizeof(*ptr))

#define XMSALIGN(Align)		__declspec(align(Align))
#define XGCCALIGN(Align)

#define XARRAY_LENGTH(Array) (sizeof(Array) / sizeof(Array[0]))

#define XDBGLOG_FUNC()	printf(__FUNCTION__)

#define XINITLOG(a)		a;	printf("%s\n", #a)

#define XINDBG(x) x

//////////////////////////////////////////////////////////////////////////typedefs
typedef unsigned char uchar, byte;
typedef unsigned short ushort;
typedef unsigned int uint, bln;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef size_t uintptr;
typedef wchar_t wchar;
typedef void* handle;


typedef void(*Proc_VoidVoid)(void);

//////////////////////////////////////////////////////////////////////////fwd decl
// struct Vec2;
// struct Vec3;
// struct Mat2x2;
// struct Transform;

class Name;
class GenericAllocator;
class TempAllocator;
class Console;
class FileManager;
class GameWindow;
class Input;
class Renderer;
class ThreadGameUpdate;
class ThreadGameRender;



namespace X
{
	inline size_t NearAlign(size_t n, size_t align)
	{
		return (n + (align - 1)) & ~(align - 1);
	}

	template < typename Type> Type Max(Type a, Type b) { return a > b ? a : b; }

	bln IsRenderThread();
	bln IsUpdateThread();

	bln WaitingForPassGLCommands();
};