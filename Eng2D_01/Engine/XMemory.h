#pragma once

#include "XThreading.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////TempAllocator
	class TempAllocator
	{
		TAC		m_tac;
		byte*	m_bufferSeek;
		byte*	m_bufferEnd;
		byte*	m_bufferBegin;

	public:
		void init(size_t buffSize);
		void release();

		void* alloc(size_t size);
		void* alloc(size_t size, size_t align);
	};
	extern TempAllocator gTempAllocator;


	
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


	extern GenericAllocator gGenericAllocator;
};