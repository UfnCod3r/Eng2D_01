#include "XMemory.h"

namespace X
{
	TempAllocator		gTempAllocator;
	GenericAllocator	gGenericAllocator;

	//////////////////////////////////////////////////////////////////////////TempAllocator
	void TempAllocator::init( size_t buffSize )
	{
		m_tac.init();
		m_bufferBegin = (byte*)::GlobalAlloc(0, buffSize);
		XASSERT(m_bufferBegin);
		m_bufferSeek = m_bufferBegin;
		m_bufferEnd = m_bufferBegin +  buffSize;
	}

	void TempAllocator::release()
	{
		m_tac.release();
		::GlobalFree((HGLOBAL)m_bufferBegin);
	}

	void* TempAllocator::alloc( size_t size )
	{
		m_tac.lock();
		byte* ret = m_bufferSeek;
		m_bufferSeek += size;
		if(m_bufferSeek < m_bufferEnd) 
		{
			m_tac.unlock();
			return ret;
		}
		ret = m_bufferBegin;
		m_bufferSeek = ret + size;
		m_tac.unlock();
		return ret;
	}

	void* TempAllocator::alloc( size_t size, size_t align )
	{
		m_tac.lock();
		m_bufferSeek = (byte*)NearAlign((size_t)m_bufferSeek, align);
		byte* ret = m_bufferSeek;
		m_bufferSeek += size;
		if(m_bufferSeek < m_bufferEnd)
		{
			m_tac.unlock();
			return ret;
		}
		ret = (byte*)NearAlign((size_t)m_bufferBegin, align);
		m_bufferSeek = ret + size;
		m_tac.unlock();
		return ret;
	}





	//////////////////////////////////////////////////////////////////////////GenericAllocator
	void GenericAllocator::init()
	{
		m_hHeap = ::HeapCreate(0,0,0);
		XASSERT(m_hHeap);
	}

	void GenericAllocator::release()
	{
		::HeapDestroy(m_hHeap);
	}

	void* GenericAllocator::alloc( size_t size )
	{
		return ::HeapAlloc(m_hHeap, 0, size);
	}

	void GenericAllocator::free( void* memory )
	{
		XASSERT(memory);
		XASSERT(::HeapFree(m_hHeap, 0, memory));
	}

	void* GenericAllocator::realloc( void* memory, size_t newSize )
	{
		XASSERT(memory);
		return ::HeapReAlloc(m_hHeap, 0, memory, newSize);
	}



}