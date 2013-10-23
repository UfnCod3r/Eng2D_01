#pragma once

#include "XMemory.h"

namespace X
{
	/*
	template < typename T> class Array
	{
		T*		m_elements;
		uint	m_length;
	
	public:
		Array()
		{
			m_elements = nullptr;
			m_length  = 0;
		}
		Array(uint size)
		{
			m_elements = (T*)gGenericAllocator.alloc(sizeof(T)*size);
			m_length = size;
		}
		~Array()
		{
			clear();
		}

		inline void resize(size_t newSize)
		{
			XASSERT(newSize > 0);
			if(m_elements)
			{
				void* p = gGenericAllocator.realloc(m_elements, sizeof(T) * newSize);
				if(p != m_elements) ::memcpy(p, m_elements, sizeof(T) * m_length);
				m_elements = (T*)p;
				m_length = newSize;
				return;
			}

			m_elements = (T*)gGenericAllocator.alloc(sizeof(T) * newSize);
			m_length = newSize;
		}

		inline void removeAt(uint index, uint count = 1)
		{
			XASSERT((index < m_length) && ((index + count) <= m_length));
			::memmove(m_elements + index, m_elements + (index + count), sizeof(T) * (m_length - (index + count)));
			m_length -= count;
		}
		inline void flush()
		{
			m_elements = (T*)gGenericAllocator.realloc(m_elements, sizeof(T) * m_length);
		}
		inline uint length() const { return m_length; }

		inline void clear()
		{
			if(m_elements)  gGenericAllocator.free(m_elements);
			m_elements = nullptr;
			m_length = 0;
		}


		T& operator [] (uint index)
		{
			XASSERT(m_length && index < m_length);
			return m_elements[index];
		}
	};
	*/
	
	template < typename Type, GenericAllocator& Allocator = GGenericAllocator> class Vector
	{
		Type*	m_elements;
		uint	m_length;
		uint	m_capacity;

	public:
		Vector()
		{
			m_elements = nullptr;
			m_length  = 0;
			m_capacity = 0;
		}
		Vector(const Vector& copy)
		{
			if(copy.m_elements)
			{
				m_length = copy.m_length;
				m_capacity = copy.m_length;
				m_elements = (Type*)Allocator.alloc(copy.m_length * sizeof(Type));
				XASSERT(m_elements);
				::memcpy(m_elements, copy.m_elements, copy.m_length * sizeof(Type));
				return;
			}
			new (this) Vector;
		}
		~Vector()
		{
			clear();
		}

		Vector& operator = (const Vector& copy)
		{
			if(m_elements) Allocator.free(m_elements);
			new (this) Vector(copy);
			return *this;
		}
		Type& operator [] (size_t index)
		{
			XASSERT(m_elements && index < m_length);
			return m_elements[index];
		}
		Type operator [] (size_t index) const 
		{
			XASSERT(m_elements && index < m_length);
			return m_elements[index];
		}
		uint  length() const   { return m_length;	}
		uint  capacity() const { return m_capacity;	}
		Type* elements() const { return m_elements;	}

		void extendBuffer(uint size)
		{
			XASSERT(size > 0);
			m_capacity += size;
			if(m_elements)
				m_elements = (Type*)Allocator.realloc(m_elements, m_capacity * sizeof(Type));
			else
				m_elements = (Type*)Allocator.alloc(m_capacity * sizeof(Type));
			XASSERT(m_elements);
		}
		void flushBuffer()
		{
			m_capacity = m_length;
			if(m_elements)
				m_elements = (Type*)Allocator.realloc(m_elements, sizeof(Type) * m_length);
		}
		void clear()
		{
			if(m_elements) Allocator.free(m_elements);
			m_elements = nullptr;
			m_length = 0;
			m_capacity = 0;
		}
		void push(const Type& value)
		{
			if(m_length == m_capacity) extendBuffer(32);
			new (m_elements + m_length) Type(value);
			m_length++;
		}
		void pop()
		{
			XASSERT(m_length);
			m_length--;
		}
		void removeAt(uint index)
		{
			XASSERT(index < m_length);
			::memmove(m_elements + index, m_elements + (index + 1), sizeof(Type) * (m_length - (index + 1)));
			m_length--;
		}
		void removeRegion(uint index, uint count)
		{
			XASSERT((index < m_length) && ((index + count) <= m_length));
			::memmove(m_elements + index, m_elements + (index + count), sizeof(Type) * (m_length - (index + count)));
			m_length -= count;
		}
		void removeIf(const Type& compareValue)
		{
			uint n = 0;
			for (uint i = 0; i < m_length; i++)
			{
				if(m_elements[i] != compareValue)
				{
					m_elements[n] = m_elements[i];
					n++;
				}
			}
			m_length = n;
		}
	};
};