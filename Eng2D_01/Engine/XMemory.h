#pragma once

#include "XThreading.h"

namespace X
{
	// 	class IAllocator
	// 	{
	// 	protected:
	// 		virtual void* alloc(size_t){return nullptr; }
	// 		virtual void* realloc(void*, size_t){return nullptr; }
	// 		virtual void  free(void*){}
	// 	};

	
	//////////////////////////////////////////////////////////////////////////TempAllocator
	class TempAllocator
	{
		TAC		m_tac;
		byte*	m_bufferSeek;
		byte*	m_bufferEnd;
		byte*	m_bufferBegin;
		volatile bln		m_exec;

	public:
		void init(size_t buffSize = 1024*1024);
		void release();

		void* alloc(size_t size);
		void* alloc(size_t size, size_t align);
	};

	extern TempAllocator GTempAllocator;

	template < TempAllocator& Ref> class UseTempAllocator
	{
	public:
		inline void* operator new (size_t x)	{ return Ref.alloc(x);	}
		inline void operator delete (void* x)	{ }
	};
	


	//////////////////////////////////////////////////////////////////////////GenericAllocator
	class GenericAllocator
	{
		HANDLE	m_hHeap;

	public:

		void init();
		void release();

		void* alloc(size_t size);
		void  free(void* memory);
		void* realloc(void* memory, size_t newSize);
	};

	extern GenericAllocator GGenericAllocator;

	template <GenericAllocator& Ref> class UseGenericAllocator
	{
	public:
		inline void* operator new (size_t x)	{ return Ref.alloc(x);	}
		inline void operator delete (void* x)	{ Ref.free(x);			}
	};


};